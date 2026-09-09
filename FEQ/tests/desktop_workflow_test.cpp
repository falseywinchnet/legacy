// Exercise the real desktop controller, all six shipped models, and failed runs.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "../app/main_window.hpp"
#include <QApplication>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QLineEdit>
#include <QListWidget>
#include <QSettings>
#include <QStandardPaths>
#include <QTabWidget>
#include <QTimer>
#include <iostream>
#include <stdexcept>
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}
void waitFor(feq_app::MainWindow& window) {
    QEventLoop loop;
    QTimer poll;
    QTimer deadline;
    deadline.setSingleShot(true);
    bool timeout = false;
    QObject::connect(&poll, &QTimer::timeout, &loop, [&window, &loop]() { if (!window.running()) loop.quit(); });
    QObject::connect(&deadline, &QTimer::timeout, &loop, [&timeout, &loop]() { timeout = true; loop.quit(); });
    poll.start(10);
    deadline.start(120000);
    loop.exec();
    require(!timeout, "Desktop model timed out");
}
feq_app::RunResult runRequest(feq_app::RunRequest request, bool cancelPreparing = false, bool cancelEngine = false) {
    feq_app::ProjectRunner runner;
    QEventLoop loop;
    QTimer deadline;
    deadline.setSingleShot(true);
    feq_app::RunResult result;
    bool timeout = false;
    runner.finished = [&result, &loop](const feq_app::RunResult& value) { result = value; loop.quit(); };
    runner.consoleReady = [&runner, cancelEngine](const QString& text) {
        if (cancelEngine && text.contains(QStringLiteral("READY FOR CANCELLATION"))) runner.cancel();
    };
    QObject::connect(&deadline, &QTimer::timeout, &loop, [&runner, &timeout, &loop]() { timeout = true; runner.cancel(); loop.quit(); });
    runner.start(request);
    if (cancelPreparing) runner.cancel();
    deadline.start(20000);
    loop.exec();
    runner.finished = {};
    require(!timeout, "Desktop process outcome timed out");
    return result;
}
void writeInput(const QString& path, const QByteArray& bytes) {
    QFile file(path);
    require(file.open(QIODevice::WriteOnly), "Cannot create test input");
    require(file.write(bytes) == bytes.size(), "Cannot write test input");
}
}
int main(int argc, char** argv) {
    QApplication application(argc, argv);
    if (argc != 3) return 2;
    try {
        const QString output = QFileInfo(QString::fromLocal8Bit(argv[1])).absoluteFilePath();
        const QString fake = QFileInfo(QString::fromLocal8Bit(argv[2])).absoluteFilePath();
        require(QDir().mkpath(output), "Cannot create test destination");
        QCoreApplication::setOrganizationName(QStringLiteral("FEQ Tests"));
        QCoreApplication::setApplicationName(QStringLiteral("Desktop Workflow"));
        QSettings::setDefaultFormat(QSettings::IniFormat);
        QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QDir(output).filePath(QStringLiteral("settings")));
        QStandardPaths::setTestModeEnabled(true);
        feq_app::MainWindow window;
        QLineEdit* results = window.findChild<QLineEdit*>(QStringLiteral("resultsFolder"));
        require(results != nullptr, "Results folder control missing");
        results->setText(QDir(output).filePath(QStringLiteral("runs with spaces")));
        window.show();
        application.processEvents();
        require(window.grab().save(QDir(output).filePath(QStringLiteral("run-page.png"))), "Cannot save application screenshot");
        QTabWidget* tabs = window.findChild<QTabWidget*>(QStringLiteral("workspaceTabs"));
        require(tabs != nullptr, "Workspace tabs missing");
        tabs->setCurrentIndex(1);
        application.processEvents();
        require(window.grab().save(QDir(output).filePath(QStringLiteral("examples-page.png"))), "Cannot save examples screenshot");
        QJsonArray runs;
        for (int index = 0; index < 6; ++index) {
            window.loadExample(index);
            window.runModel();
            waitFor(window);
            const feq_app::RunResult result = window.lastResult();
            std::cout << "Example " << index+1 << ": " << result.status.toStdString() << " " << result.message.toStdString() << '\n';
            require(result.status == QStringLiteral("completed"), "Supplied desktop example failed");
            require(!result.outputs.isEmpty(), "Desktop failed to list example outputs");
            runs.append(QJsonObject{{QStringLiteral("example"), index}, {QStringLiteral("folder"), result.folder},
                                   {QStringLiteral("working"), result.workingFolder}});
            if (index == 0) {
                application.processEvents();
                require(window.grab().save(QDir(output).filePath(QStringLiteral("results-page.png"))), "Cannot save results screenshot");
            }
        }
        window.loadExample(0);
        window.runModel();
        waitFor(window);
        require(window.lastResult().folder != runs.at(0).toObject().value(QStringLiteral("folder")).toString(), "Rerun reused an existing run folder");
        const QString model = QDir(output).filePath(QStringLiteral("source model"));
        require(QDir().mkpath(model), "Cannot create test model");
        feq_app::RunRequest request;
        request.modelFolder = model;
        request.workingFolder = model;
        request.inputFile = QDir(model).filePath(QStringLiteral("input.in"));
        request.resultsFolder = results->text();
        request.executable = fake;
        request.name = QStringLiteral("Failure tests");
        writeInput(request.inputFile, "warnings\n");
        const feq_app::RunResult warning = runRequest(request);
        require(warning.status == QStringLiteral("completed") && warning.warnings == 1, "A warning must be reported without becoming a failure");
        writeInput(request.inputFile, "errors\n");
        const feq_app::RunResult error = runRequest(request);
        require(error.status == QStringLiteral("failed") && error.errors == 1, "Exit zero with a model error must fail");
        writeInput(request.inputFile, "stop\n");
        require(runRequest(request).status == QStringLiteral("failed"), "An abnormal engine stop must fail even with exit zero");
        writeInput(request.inputFile, "empty\n");
        require(runRequest(request).status == QStringLiteral("failed"), "An empty report must fail");
        writeInput(request.inputFile, "wait\n");
        const feq_app::RunResult cancelled = runRequest(request, false, true);
        require(cancelled.status == QStringLiteral("cancelled"), "Engine cancellation was not recorded");
        require(QFileInfo(QDir(cancelled.folder).filePath(QStringLiteral("console.log"))).size() > 0, "Cancelled run lost its log");
        require(runRequest(request, true).status == QStringLiteral("cancelled"), "Preparation cancellation was not recorded");
        request.resultsFolder = QDir(model).filePath(QStringLiteral("must not create/nested"));
        require(runRequest(request).status == QStringLiteral("failed"), "Nested results folder must be rejected");
        require(!QFileInfo::exists(QDir(model).filePath(QStringLiteral("must not create"))), "Rejected destination modified source model");
        request.resultsFolder = results->text();
        request.executable = feq_app::enginePath(feq_app::Engine::tables);
        request.engine = feq_app::Engine::tables;
        writeInput(request.inputFile, "invalid hydraulic model\n");
        require(runRequest(request).status == QStringLiteral("failed"), "Real FEQUTL invalid input did not fail");
        QFile receipt(QDir(output).filePath(QStringLiteral("desktop-runs.json")));
        require(receipt.open(QIODevice::WriteOnly), "Cannot save desktop evidence");
        receipt.write(QJsonDocument(runs).toJson());
        std::cout << "All desktop workflow checks passed\n";
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
