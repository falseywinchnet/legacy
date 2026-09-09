// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_MAIN_WINDOW_HPP
#define FEQ_MAIN_WINDOW_HPP
#include "project_runner.hpp"
#include <QMainWindow>
class QComboBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QPlainTextEdit;
class QProgressBar;
class QPushButton;
class QTabWidget;
class QWidget;

namespace feq_app {
QString resourceFolder();
QString enginePath(Engine engine);

class MainWindow final : public QMainWindow {
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
    void loadExample(int index);
    void runModel();
    bool running() const;
    RunResult lastResult() const;
private:
    void chooseInput();
    void showResult(const RunResult& result);
    void showOutput();
    void refreshHistory();
    void openHistory();
    void setBusy(bool busy);
    ProjectRunner runner_;
    QComboBox* engine_;
    QLineEdit* input_;
    QLineEdit* modelFolder_;
    QLineEdit* workingFolder_;
    QLineEdit* resultsFolder_;
    QLineEdit* name_;
    QTabWidget* tabs_;
    QLabel* status_;
    QLabel* resultStatus_;
    QProgressBar* progress_;
    QPushButton* run_;
    QPushButton* cancel_;
    QListWidget* examples_;
    QListWidget* outputs_;
    QListWidget* history_;
    QPlainTextEdit* preview_;
    QPlainTextEdit* console_;
    QWidget* form_;
    QWidget* folders_;
    QString exampleArgument_;
    RunResult last_;
};
}
#endif
