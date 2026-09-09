// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_PROJECT_RUNNER_HPP
#define FEQ_PROJECT_RUNNER_HPP
#include <QFutureWatcher>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <atomic>
#include <functional>
#include <memory>

namespace feq_app {
enum class Engine { simulation, tables };

struct RunRequest {
    Engine engine = Engine::simulation;
    QString executable;
    QString modelFolder;
    QString inputFile;
    QString workingFolder;
    QString resultsFolder;
    QString name;
    // Optional supplied-example spelling, including its original separators.
    QString inputArgument;
};

struct PreparedRun {
    QString folder;
    QString workingFolder;
    QString reportPath;
    QString tablePath;
    QStringList arguments;
    QJsonObject manifest;
    QString error;
    bool cancelled = false;
};

struct RunResult {
    QString folder;
    QString workingFolder;
    QString reportPath;
    QString tablePath;
    QString status;
    QString message;
    QJsonArray outputs;
    int exitCode = -1;
    int warnings = 0;
    int errors = 0;
};

class ProjectRunner final : public QObject {
public:
    explicit ProjectRunner(QObject* parent = nullptr);
    ~ProjectRunner() override;
    bool busy() const;
    void start(const RunRequest& request);
    void cancel();
    std::function<void(const QString&)> statusChanged;
    std::function<void(const QString&)> consoleReady;
    std::function<void(const RunResult&)> finished;

private:
    void prepared();
    void readConsole();
    void complete(int exitCode, QProcess::ExitStatus exitStatus);
    void fail(const QString& message);
    void persist(const QString& status);
    RunRequest request_;
    PreparedRun prepared_;
    QProcess process_;
    QFutureWatcher<PreparedRun> preparation_;
    std::shared_ptr<std::atomic_bool> cancelled_;
    QFutureWatcher<RunResult> completion_;
    QFile consoleFile_;
    QByteArray consoleTail_;
    bool consoleStopped_ = false;
    bool consoleNormal_ = false;
    bool consoleWriteFailed_ = false;
    bool busy_ = false;
    bool completionStarted_ = false;
};
}
#endif
