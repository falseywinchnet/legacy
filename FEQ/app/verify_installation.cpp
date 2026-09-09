// Maintainer acceptance mode runs the installed application's real controller.
// It is also useful for checking a relocated installation without a compiler.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "verify_installation.hpp"
#include "main_window.hpp"
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QLineEdit>
#include <QSaveFile>
#include <QSettings>
#include <QTimer>
#include <iostream>
#include <stdexcept>
namespace feq_app {
int verifyInstallation(QApplication& application, const QString& outputFolder) {
    const QString output = QFileInfo(outputFolder).absoluteFilePath();
    if (!QDir().mkpath(output)) return 2;
    QCoreApplication::setApplicationName(QStringLiteral("FEQ Installation Verification"));
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QDir(output).filePath(QStringLiteral("settings")));
    MainWindow window;
    QLineEdit* results = window.findChild<QLineEdit*>(QStringLiteral("resultsFolder"));
    if (results == nullptr) return 2;
    results->setText(QDir(output).filePath(QStringLiteral("runs")));
    window.show();
    window.loadExample(0);
    window.runModel();
    int index = 0;
    QJsonArray runs;
    QTimer poll;
    QTimer deadline;
    deadline.setSingleShot(true);
    QObject::connect(&deadline, &QTimer::timeout, &application, [&application]() {
        std::cerr << "Installed application verification timed out\n";
        application.exit(1);
    });
    QObject::connect(&poll, &QTimer::timeout, &application, [&application, &window, &poll, &deadline, &index, &runs, output]() {
        if (window.running()) return;
        try {
            const RunResult result = window.lastResult();
            if (result.status != QStringLiteral("completed")) throw std::runtime_error(result.message.toStdString());
            runs.append(QJsonObject{{QStringLiteral("example"), index}, {QStringLiteral("folder"), result.folder},
                                   {QStringLiteral("working"), result.workingFolder}});
            if (index == 0 && !window.grab().save(QDir(output).filePath(QStringLiteral("installed-results.png")))) {
                throw std::runtime_error("Cannot save installation screenshot");
            }
            ++index;
            if (index < 6) {
                window.loadExample(index);
                window.runModel();
                return;
            }
            poll.stop();
            deadline.stop();
            const QJsonObject record{{QStringLiteral("runs"), runs},
                {QStringLiteral("resources"), resourceFolder()},
                {QStringLiteral("qt_version"), QString::fromLatin1(qVersion())},
                {QStringLiteral("plugin_paths"), QJsonArray::fromStringList(QCoreApplication::libraryPaths())}};
            QSaveFile receipt(QDir(output).filePath(QStringLiteral("installation.json")));
            const QByteArray bytes = QJsonDocument(record).toJson();
            if (!receipt.open(QIODevice::WriteOnly) || receipt.write(bytes) != bytes.size() || !receipt.commit()) {
                throw std::runtime_error("Cannot save installation verification record");
            }
            std::cout << "Installed FEQ Workbench completed all six supplied models\n";
            application.exit(0);
        } catch (const std::exception& error) {
            poll.stop();
            std::cerr << error.what() << '\n';
            application.exit(1);
        }
    });
    deadline.start(120000);
    poll.start(10);
    return application.exec();
}
}
