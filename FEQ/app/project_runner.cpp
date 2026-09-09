// Each run uses a separate copy of the selected model folder. The original
// input tree is never an engine working directory. Process launch uses an
// argument vector and never a shell command string.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "project_runner.hpp"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDir>
#include <QDirListing>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QRegularExpression>
#include <QProcessEnvironment>
#include <QSaveFile>
#include <QUuid>
#include <QtConcurrentRun>
#include <stdexcept>

namespace feq_app {
namespace {
QString relativeWithin(const QString& folder, const QString& path) {
    const QString relative = QDir(folder).relativeFilePath(path);
    if (relative == QStringLiteral("..") || relative.startsWith(QStringLiteral("../")) || QDir::isAbsolutePath(relative)) {
        throw std::runtime_error("The input file and working folder must be inside the model folder.");
    }
    return relative;
}

// Resolve existing parent links before creating anything. A rejected destination
// must not leave even an empty directory in the source model.
QString futureCanonicalPath(const QString& path) {
    if (path.trimmed().isEmpty()) throw std::runtime_error("Choose a results folder.");
    QFileInfo current(QDir::cleanPath(QFileInfo(path).absoluteFilePath()));
    QStringList missing;
    while (!current.exists()) {
        if (current.isSymLink()) throw std::runtime_error("The results path contains a broken link.");
        missing.prepend(current.fileName());
        const QString parent = current.absolutePath();
        if (parent == current.absoluteFilePath()) throw std::runtime_error("Cannot resolve the results folder.");
        current.setFile(parent);
    }
    QString resolved = current.canonicalFilePath();
    for (qsizetype index = 0; index < missing.size(); ++index) resolved = QDir(resolved).filePath(missing.at(index));
    return resolved;
}

QString fileHash(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) throw std::runtime_error(("Cannot read "+path).toStdString());
    QCryptographicHash hash(QCryptographicHash::Sha256);
    if (!hash.addData(&file)) throw std::runtime_error(("Cannot hash "+path).toStdString());
    return QString::fromLatin1(hash.result().toHex());
}

void writeManifest(const QString& folder, const QJsonObject& manifest) {
    QSaveFile file(QDir(folder).filePath(QStringLiteral("run.json")));
    const QByteArray bytes = QJsonDocument(manifest).toJson(QJsonDocument::Indented);
    if (!file.open(QIODevice::WriteOnly) || file.write(bytes) != bytes.size() || !file.commit()) {
        throw std::runtime_error("Cannot save the run record. Check the results folder and available disk space.");
    }
}

QString copyFile(const QString& source, const QString& destination,
                 const std::shared_ptr<std::atomic_bool>& cancelled) {
    QFile input(source);
    QSaveFile output(destination);
    if (!input.open(QIODevice::ReadOnly) || !output.open(QIODevice::WriteOnly)) {
        throw std::runtime_error(("Cannot copy model file: "+source).toStdString());
    }
    QCryptographicHash hash(QCryptographicHash::Sha256);
    while (!input.atEnd()) {
        if (cancelled->load()) throw std::runtime_error("Run cancelled while copying the model.");
        const QByteArray bytes = input.read(1024*1024);
        if (bytes.isEmpty() && input.error() != QFileDevice::NoError) {
            throw std::runtime_error(("Cannot read model file: "+source).toStdString());
        }
        hash.addData(bytes);
        if (output.write(bytes) != bytes.size()) throw std::runtime_error("Cannot finish the model copy. Check available disk space.");
    }
    if (!output.commit()) throw std::runtime_error("Cannot save the model copy.");
    return QString::fromLatin1(hash.result().toHex());
}

PreparedRun prepareRun(const RunRequest& request, const std::shared_ptr<std::atomic_bool>& cancelled) {
    PreparedRun run;
    try {
        const QString root = QFileInfo(request.modelFolder).canonicalFilePath();
        const QString input = QFileInfo(request.inputFile).canonicalFilePath();
        const QString working = QFileInfo(request.workingFolder).canonicalFilePath();
        if (root.isEmpty() || !QFileInfo(root).isDir()) throw std::runtime_error("Choose an existing model folder.");
        if (input.isEmpty() || !QFileInfo(input).isFile()) throw std::runtime_error("Choose an existing input file.");
        if (working.isEmpty() || !QFileInfo(working).isDir()) throw std::runtime_error("Choose an existing working folder.");
        if (!QFileInfo(request.executable).isExecutable()) throw std::runtime_error("The selected engine is missing from this installation.");
        const QString inputRelative = relativeWithin(root, input);
        const QString workingRelative = relativeWithin(root, working);
        const QString results = futureCanonicalPath(request.resultsFolder);
        const QString resultsRelative = QDir(root).relativeFilePath(results);
        if (resultsRelative != QStringLiteral("..") && !resultsRelative.startsWith(QStringLiteral("../")) && !QDir::isAbsolutePath(resultsRelative)) {
            throw std::runtime_error("Choose a results folder outside the model folder so that each run can copy the model safely.");
        }
        if (!QDir().mkpath(results)) throw std::runtime_error("Cannot create the results folder.");
        QString name = request.name.trimmed();
        name.replace(QRegularExpression(QStringLiteral("[^A-Za-z0-9_-]")), QStringLiteral("-"));
        if (name.isEmpty()) name = QStringLiteral("model");
        name = name.left(48);
        const QString id = QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMdd-HHmmss"))+
                           QStringLiteral("-")+name+QStringLiteral("-")+QUuid::createUuid().toString(QUuid::Id128).left(8);
        run.folder = QDir(results).filePath(id);
        if (!QDir(results).mkdir(id)) throw std::runtime_error("Cannot create a new run folder.");
        const QString copyRoot = QDir(run.folder).filePath(QStringLiteral("model"));
        if (!QDir().mkpath(copyRoot)) throw std::runtime_error("Cannot create the working model copy.");
        QJsonArray inputs;
        const QDirListing files(root, QDirListing::IteratorFlag::Recursive | QDirListing::IteratorFlag::IncludeHidden |
                                     QDirListing::IteratorFlag::FollowDirSymlinks | QDirListing::IteratorFlag::IncludeBrokenSymlinks);
        for (QDirListing::const_iterator file = files.begin(); file != files.end(); ++file) {
            if (cancelled->load()) throw std::runtime_error("Run cancelled while copying the model.");
            const QString source = file->filePath();
            const QFileInfo info = file->fileInfo();
            const QString relative = QDir(root).relativeFilePath(source);
            const QString destination = QDir(copyRoot).filePath(relative);
            if (!info.isDir() && !info.isFile()) throw std::runtime_error(("The model contains an unreadable or special file: "+relative).toStdString());
            if (info.isDir()) {
                if (!QDir().mkpath(destination)) throw std::runtime_error("Cannot create a directory in the model copy.");
                continue;
            }
            if (!QDir().mkpath(QFileInfo(destination).absolutePath())) throw std::runtime_error("Cannot create a model file directory.");
            const QString hash = copyFile(source, destination, cancelled);
            inputs.append(QJsonObject{{QStringLiteral("path"), relative}, {QStringLiteral("sha256"), hash},
                                      {QStringLiteral("bytes"), QFileInfo(destination).size()}});
        }
        run.workingFolder = QDir(copyRoot).filePath(workingRelative);
        QString stem = QFileInfo(input).completeBaseName().toLower();
        stem.replace(QRegularExpression(QStringLiteral("[^A-Za-z0-9_-]")), QStringLiteral("-"));
        if (stem.isEmpty()) stem = QStringLiteral("model");
        if (QFileInfo::exists(QDir(run.workingFolder).filePath(stem+QStringLiteral(".out"))) ||
            QFileInfo::exists(QDir(run.workingFolder).filePath(stem+QStringLiteral(".tab")))) {
            stem += QStringLiteral("-result-")+QUuid::createUuid().toString(QUuid::Id128).left(8);
        }
        const QString report = stem+QStringLiteral(".out");
        run.reportPath = QDir(run.workingFolder).filePath(report);
        const QString inputCopy = QDir(copyRoot).filePath(inputRelative);
        const QString argument = request.inputArgument.isEmpty() ? QDir(run.workingFolder).relativeFilePath(inputCopy) : request.inputArgument;
        run.arguments = QStringList{argument, report};
        if (request.engine == Engine::tables) {
            const QString table = stem+QStringLiteral(".tab");
            run.arguments.append(table);
            run.tablePath = QDir(run.workingFolder).filePath(table);
        }
        run.manifest = QJsonObject{
            {QStringLiteral("format_version"), 1}, {QStringLiteral("name"), request.name},
            {QStringLiteral("status"), QStringLiteral("prepared")},
            {QStringLiteral("created_utc"), QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs)},
            {QStringLiteral("engine"), request.engine == Engine::simulation ? QStringLiteral("FEQ 10.61") : QStringLiteral("FEQUTL 5.80")},
            {QStringLiteral("engine_sha256"), fileHash(request.executable)},
            {QStringLiteral("source_folder"), root}, {QStringLiteral("input_file"), inputRelative},
            {QStringLiteral("working_folder"), workingRelative}, {QStringLiteral("inputs"), inputs},
            {QStringLiteral("arguments"), QJsonArray::fromStringList(run.arguments)}};
        writeManifest(run.folder, run.manifest);
    } catch (const std::exception& error) {
        run.error = QString::fromUtf8(error.what());
        run.cancelled = cancelled->load();
    }
    return run;
}
}

ProjectRunner::ProjectRunner(QObject* parent) : QObject(parent) {
    QObject::connect(&preparation_, &QFutureWatcher<PreparedRun>::finished, this, [this]() { prepared(); });
    QObject::connect(&completion_, &QFutureWatcher<RunResult>::finished, this, [this]() {
        const RunResult result = completion_.result();
        busy_ = false;
        if (finished) finished(result);
    });
    QObject::connect(&process_, &QProcess::readyReadStandardOutput, this, [this]() { readConsole(); });
    QObject::connect(&process_, &QProcess::finished, this, [this](int code, QProcess::ExitStatus status) { complete(code, status); });
    QObject::connect(&process_, &QProcess::errorOccurred, this, [this](QProcess::ProcessError error) {
        if (error == QProcess::FailedToStart) fail(QStringLiteral("The engine could not start: ")+process_.errorString());
    });
}

ProjectRunner::~ProjectRunner() {
    if (cancelled_) cancelled_->store(true);
    if (preparation_.isRunning()) preparation_.waitForFinished();
    if (process_.state() != QProcess::NotRunning) {
        process_.kill();
        process_.waitForFinished(3000);
    }
    if (completion_.isRunning()) completion_.waitForFinished();
}

bool ProjectRunner::busy() const { return busy_; }

void ProjectRunner::start(const RunRequest& request) {
    if (busy_) return;
    request_ = request;
    prepared_ = PreparedRun{};
    consoleTail_.clear();
    consoleStopped_ = false;
    consoleNormal_ = false;
    consoleWriteFailed_ = false;
    consoleFile_.close();
    busy_ = true;
    completionStarted_ = false;
    cancelled_ = std::make_shared<std::atomic_bool>(false);
    if (statusChanged) statusChanged(QStringLiteral("Preparing a separate model copy…"));
    const std::shared_ptr<std::atomic_bool> cancelled = cancelled_;
    preparation_.setFuture(QtConcurrent::run([request, cancelled]() { return prepareRun(request, cancelled); }));
}

void ProjectRunner::prepared() {
    prepared_ = preparation_.result();
    if (!prepared_.error.isEmpty()) { fail(prepared_.error); return; }
    if (cancelled_->load()) { fail(QStringLiteral("Run cancelled.")); return; }
    consoleFile_.setFileName(QDir(prepared_.folder).filePath(QStringLiteral("console.log")));
    if (!consoleFile_.open(QIODevice::WriteOnly)) { fail(QStringLiteral("Cannot create the engine log.")); return; }
    try { persist(QStringLiteral("running")); }
    catch (const std::exception& error) { fail(QString::fromUtf8(error.what())); return; }
    if (statusChanged) statusChanged(request_.engine == Engine::simulation ? QStringLiteral("Running the flow simulation…") : QStringLiteral("Building hydraulic tables…"));
    process_.setProcessChannelMode(QProcess::MergedChannels);
    process_.setWorkingDirectory(prepared_.workingFolder);
    QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
    environment.insert(QStringLiteral("FEQ_RUN_SOURCE_ROOT"), prepared_.manifest.value(QStringLiteral("source_folder")).toString());
    environment.insert(QStringLiteral("FEQ_RUN_COPY_ROOT"), QDir(prepared_.folder).filePath(QStringLiteral("model")));
    process_.setProcessEnvironment(environment);
    process_.setStandardInputFile(QProcess::nullDevice());
    process_.start(request_.executable, prepared_.arguments);
}

void ProjectRunner::readConsole() {
    const QByteArray bytes = process_.readAllStandardOutput();
    if (bytes.isEmpty()) return;
    if (consoleFile_.write(bytes) != bytes.size() || !consoleFile_.flush()) {
        consoleWriteFailed_ = true;
        process_.kill();
    }
    // Preserve a short overlap to recognize error markers split across reads.
    consoleTail_ += bytes;
    consoleStopped_ = consoleStopped_ || consoleTail_.contains("Abnormal stop") ||
                      consoleTail_.contains("FEQ engine stopped:") || consoleTail_.contains("runtime error:");
    consoleNormal_ = consoleNormal_ || consoleTail_.contains("Normal stop in MANTIM") || consoleTail_.contains("Normal stop in SEGEND");
    consoleTail_ = consoleTail_.right(256);
    if (consoleReady) consoleReady(QString::fromLocal8Bit(bytes));
}

void ProjectRunner::persist(const QString& status) {
    prepared_.manifest.insert(QStringLiteral("status"), status);
    writeManifest(prepared_.folder, prepared_.manifest);
}

void ProjectRunner::cancel() {
    if (!busy_) return;
    cancelled_->store(true);
    if (statusChanged) statusChanged(QStringLiteral("Stopping the run…"));
    if (process_.state() != QProcess::NotRunning) process_.kill();
}

void ProjectRunner::fail(const QString& message) {
    if (completionStarted_) return;
    completionStarted_ = true;
    busy_ = false;
    RunResult result;
    result.folder = prepared_.folder;
    result.workingFolder = prepared_.workingFolder;
    result.status = cancelled_ && cancelled_->load() ? QStringLiteral("cancelled") : QStringLiteral("failed");
    result.message = message;
    if (!prepared_.folder.isEmpty()) {
        prepared_.manifest.insert(QStringLiteral("message"), message);
        try { persist(result.status); } catch (const std::exception&) { result.message += QStringLiteral(" The run record could not be saved."); }
    }
    if (finished) finished(result);
}

void ProjectRunner::complete(int exitCode, QProcess::ExitStatus exitStatus) {
    if (completionStarted_) return;
    readConsole();
    consoleFile_.close();
    completionStarted_ = true;
    if (statusChanged) statusChanged(QStringLiteral("Saving results and checking the report…"));
    const PreparedRun run = prepared_;
    const bool cancelled = cancelled_->load();
    const bool stopped = consoleStopped_;
    const bool normal = consoleNormal_;
    const bool logFailure = consoleWriteFailed_;
    // Reports and model trees may be large. Hash and scan them away from the UI.
    completion_.setFuture(QtConcurrent::run([run, exitCode, exitStatus, cancelled, stopped, normal, logFailure]() {
        RunResult result;
        result.folder = run.folder;
        result.workingFolder = run.workingFolder;
        result.reportPath = run.reportPath;
        result.tablePath = run.tablePath;
        result.exitCode = exitCode;
        QJsonObject manifest = run.manifest;
        try {
            if (logFailure) throw std::runtime_error("The engine log could not be saved completely. Check available disk space.");
            QFile report(run.reportPath);
            const bool hasReport = report.open(QIODevice::ReadOnly);
            const QRegularExpression errors(QStringLiteral("\\*ERR:[0-9]+\\*"));
            const QRegularExpression warnings(QStringLiteral("\\*(?:WRN|ERR/WRN):[0-9]+\\*"));
            while (hasReport && !report.atEnd()) {
                const QString line = QString::fromLatin1(report.readLine());
                QRegularExpressionMatchIterator matches = errors.globalMatch(line);
                while (matches.hasNext()) { matches.next(); ++result.errors; }
                matches = warnings.globalMatch(line);
                while (matches.hasNext()) { matches.next(); ++result.warnings; }
                if (report.error() != QFileDevice::NoError) throw std::runtime_error("Cannot read the complete report.");
            }
            const bool failedRun = exitStatus != QProcess::NormalExit || exitCode != 0 || !hasReport || report.size() == 0 || (result.errors > 0 && !normal) || stopped;
            result.status = cancelled ? QStringLiteral("cancelled") : failedRun ? QStringLiteral("failed") : QStringLiteral("completed");
            result.message = cancelled ? QStringLiteral("Run stopped. Partial results are saved.") :
                             failedRun ? QStringLiteral("The run did not complete successfully. Open the report or engine log for details.") :
                             result.errors > 0 ? QStringLiteral("The engine reached normal completion with %1 error diagnostics and %2 warnings. Review the report before using results.").arg(result.errors).arg(result.warnings) :
                             result.warnings > 0 ? QStringLiteral("Run completed with %1 model warnings. Review the report.").arg(result.warnings) : QStringLiteral("Run completed. Results are ready.");
            QJsonObject original;
            const QJsonArray inputs = manifest.value(QStringLiteral("inputs")).toArray();
            for (qsizetype index = 0; index < inputs.size(); ++index) {
                const QJsonObject input = inputs.at(index).toObject();
                original.insert(input.value(QStringLiteral("path")).toString(), input.value(QStringLiteral("sha256")));
            }
            const QString modelRoot = QDir(run.folder).filePath(QStringLiteral("model"));
            const QDirListing files(modelRoot, QDirListing::IteratorFlag::Recursive | QDirListing::IteratorFlag::IncludeHidden | QDirListing::IteratorFlag::FilesOnly);
            for (QDirListing::const_iterator file = files.begin(); file != files.end(); ++file) {
                const QString path = file->filePath();
                const QString relative = QDir(modelRoot).relativeFilePath(path);
                const QString hash = fileHash(path);
                if (original.value(relative).toString() != hash || path == run.reportPath || path == run.tablePath) {
                    result.outputs.append(QJsonObject{{QStringLiteral("path"), QStringLiteral("model/")+relative},
                                                      {QStringLiteral("sha256"), hash}, {QStringLiteral("bytes"), QFileInfo(path).size()}});
                }
            }
        } catch (const std::exception& error) {
            result.status = QStringLiteral("failed");
            result.message = QString::fromUtf8(error.what());
        }
        manifest.insert(QStringLiteral("exit_code"), exitCode);
        manifest.insert(QStringLiteral("completed_utc"), QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs));
        manifest.insert(QStringLiteral("warnings"), result.warnings);
        manifest.insert(QStringLiteral("errors"), result.errors);
        manifest.insert(QStringLiteral("status"), result.status);
        manifest.insert(QStringLiteral("message"), result.message);
        manifest.insert(QStringLiteral("outputs"), result.outputs);
        try { writeManifest(run.folder, manifest); }
        catch (const std::exception& error) { result.status = QStringLiteral("failed"); result.message = QString::fromUtf8(error.what()); }
        return result;
    }));
}
}
