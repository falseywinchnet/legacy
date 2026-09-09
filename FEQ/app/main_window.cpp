// The desktop workflow exposes models, runs and results. Recovery machinery
// belongs in the maintainer documentation, not in the operator's workflow.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "main_window.hpp"
#include <QApplication>
#include <QAction>
#include <QComboBox>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QFormLayout>
#include <QGroupBox>
#include <QIcon>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QSettings>
#include <QSplitter>
#include <QStandardPaths>
#include <QTabWidget>
#include <QTextCursor>
#include <QToolButton>
#include <QUrl>
#include <QVBoxLayout>

namespace feq_app {
namespace {
struct Example {
    const char* title;
    const char* description;
    const char* input;
    const char* argument;
    Engine engine;
};
const Example examples[] = {
    {"Single branch", "FEQ example 1 · Unsteady flow in one channel", "FEQEX1", "..\\data\\feqex1", Engine::simulation},
    {"Three branches", "FEQ example 2 · Three-branch channel system", "FEQEX2", "..\\data\\feqex2", Engine::simulation},
    {"Reservoir at a junction", "FEQ example 3 · Three branches and a level-pool reservoir", "FEQEX3", "..\\data\\feqex3", Engine::simulation},
    {"Offline reservoir", "FEQ example 4 · A reservoir with two stream connections", "FEQEX4", "..\\data\\feqex4", Engine::simulation},
    {"Hydraulic tables", "FEQUTL · Cross sections, transitions, gates and more", "UTLEXM.IN", "..\\data\\utlexm.in", Engine::tables},
    {"Culvert tables", "FEQUTL · Supplied culvert example", "CULVERT.IN", "..\\data\\culvert.in", Engine::tables}
};

QWidget* folderField(QLineEdit* edit, const QString& title, QWidget* parent) {
    QWidget* row = new QWidget(parent);
    QHBoxLayout* layout = new QHBoxLayout(row);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(edit, 1);
    QPushButton* browse = new QPushButton(QStringLiteral("Browse…"), row);
    layout->addWidget(browse);
    QObject::connect(browse, &QPushButton::clicked, row, [edit, title, parent]() {
        const QString folder = QFileDialog::getExistingDirectory(parent, title, edit->text());
        if (!folder.isEmpty()) edit->setText(folder);
    });
    return row;
}

void openLocal(const QString& path) {
    if (!path.isEmpty() && QFileInfo::exists(path)) QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
}

QString resourceFolder() {
    const QDir application(QCoreApplication::applicationDirPath());
    const QStringList candidates{
        application.filePath(QStringLiteral("../Resources")),
        application.filePath(QStringLiteral("../share/feq")),
        QString::fromUtf8(FEQ_APPLICATION_RESOURCES)};
    for (qsizetype index = 0; index < candidates.size(); ++index) {
        if (QDir(QDir(candidates.at(index)).filePath(QStringLiteral("examples/data"))).exists()) return QDir(candidates.at(index)).absolutePath();
    }
    return candidates.last();
}

QString enginePath(Engine engine) {
    QString name = engine == Engine::simulation ? QStringLiteral("feq") : QStringLiteral("fequtl");
#ifdef Q_OS_WIN
    name += QStringLiteral(".exe");
#endif
    return QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(name);
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), runner_(this) {
    setWindowTitle(QStringLiteral("FEQ Workbench"));
    setWindowIcon(QIcon(QDir(resourceFolder()).filePath(QStringLiteral("feq-workbench.svg"))));
    resize(1080, 790);
    setMinimumSize(820, 640);
    QWidget* central = new QWidget(this);
    QVBoxLayout* outer = new QVBoxLayout(central);
    outer->setContentsMargins(26, 22, 26, 22);
    outer->setSpacing(14);
    QLabel* title = new QLabel(QStringLiteral("FEQ Workbench"), central);
    title->setObjectName(QStringLiteral("title"));
    outer->addWidget(title);
    QLabel* subtitle = new QLabel(QStringLiteral("Run flow simulations. Build hydraulic tables. Keep every run together."), central);
    subtitle->setObjectName(QStringLiteral("subtitle"));
    outer->addWidget(subtitle);
    tabs_ = new QTabWidget(central);
    tabs_->setObjectName(QStringLiteral("workspaceTabs"));
    outer->addWidget(tabs_, 1);

    QWidget* runPage = new QWidget(tabs_);
    QVBoxLayout* runLayout = new QVBoxLayout(runPage);
    runLayout->setContentsMargins(22, 22, 22, 22);
    runLayout->setSpacing(18);
    form_ = new QWidget(runPage);
    QFormLayout* form = new QFormLayout(form_);
    form->setContentsMargins(0, 0, 0, 0);
    form->setVerticalSpacing(16);
    engine_ = new QComboBox(form_);
    engine_->setObjectName(QStringLiteral("engineChoice"));
    engine_->addItem(QStringLiteral("Flow simulation — FEQ 10.61"));
    engine_->addItem(QStringLiteral("Hydraulic tables — FEQUTL 5.80"));
    form->addRow(QStringLiteral("Program"), engine_);
    input_ = new QLineEdit(form_);
    input_->setObjectName(QStringLiteral("inputFile"));
    input_->setPlaceholderText(QStringLiteral("Select your model's main input file"));
    QWidget* inputRow = new QWidget(form_);
    QHBoxLayout* inputLayout = new QHBoxLayout(inputRow);
    inputLayout->setContentsMargins(0, 0, 0, 0);
    inputLayout->addWidget(input_, 1);
    QPushButton* browse = new QPushButton(QStringLiteral("Choose file…"), inputRow);
    inputLayout->addWidget(browse);
    QObject::connect(browse, &QPushButton::clicked, this, [this]() { chooseInput(); });
    form->addRow(QStringLiteral("Input file"), inputRow);
    name_ = new QLineEdit(form_);
    name_->setObjectName(QStringLiteral("runName"));
    name_->setPlaceholderText(QStringLiteral("A name for this run"));
    form->addRow(QStringLiteral("Run name"), name_);
    resultsFolder_ = new QLineEdit(form_);
    resultsFolder_->setObjectName(QStringLiteral("resultsFolder"));
    QSettings settings;
    const QString defaultResults = QDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)).filePath(QStringLiteral("FEQ Runs"));
    resultsFolder_->setText(settings.value(QStringLiteral("resultsFolder"), defaultResults).toString());
    form->addRow(QStringLiteral("Save runs in"), folderField(resultsFolder_, QStringLiteral("Choose a results folder"), form_));
    runLayout->addWidget(form_);
    QToolButton* options = new QToolButton(runPage);
    options->setText(QStringLiteral("Model folders"));
    options->setCheckable(true);
    options->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    options->setArrowType(Qt::RightArrow);
    runLayout->addWidget(options);
    QGroupBox* folders = new QGroupBox(runPage);
    folders_ = folders;
    QFormLayout* folderLayout = new QFormLayout(folders);
    modelFolder_ = new QLineEdit(folders);
    modelFolder_->setObjectName(QStringLiteral("modelFolder"));
    workingFolder_ = new QLineEdit(folders);
    workingFolder_->setObjectName(QStringLiteral("workingFolder"));
    folderLayout->addRow(QStringLiteral("Model folder"), folderField(modelFolder_, QStringLiteral("Choose the folder containing the complete model"), folders));
    folderLayout->addRow(QStringLiteral("Working folder"), folderField(workingFolder_, QStringLiteral("Choose the model's working folder"), folders));
    QLabel* explanation = new QLabel(QStringLiteral("The model folder should contain every file used by relative paths. The working folder is where those paths begin. Each run uses a separate copy."), folders);
    explanation->setWordWrap(true);
    folderLayout->addRow(explanation);
    folders->hide();
    runLayout->addWidget(folders);
    QObject::connect(options, &QToolButton::toggled, folders, [options, folders](bool expanded) {
        folders->setVisible(expanded);
        options->setArrowType(expanded ? Qt::DownArrow : Qt::RightArrow);
    });
    QLabel* firstRun = new QLabel(QStringLiteral("New to FEQ? Open Examples and run a supplied model to get started."), runPage);
    firstRun->setWordWrap(true);
    runLayout->addWidget(firstRun);
    runLayout->addStretch(1);
    tabs_->addTab(runPage, QStringLiteral("Run a model"));

    QWidget* examplePage = new QWidget(tabs_);
    QVBoxLayout* exampleLayout = new QVBoxLayout(examplePage);
    exampleLayout->setContentsMargins(22, 22, 22, 22);
    exampleLayout->addWidget(new QLabel(QStringLiteral("Six complete models are included. Your run gets its own copy and results folder."), examplePage));
    examples_ = new QListWidget(examplePage);
    examples_->setObjectName(QStringLiteral("examples"));
    for (int index = 0; index < 6; ++index) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromUtf8(examples[index].title)+QStringLiteral("\n")+QString::fromUtf8(examples[index].description), examples_);
        item->setSizeHint(QSize(100, 61));
    }
    examples_->setCurrentRow(0);
    exampleLayout->addWidget(examples_, 1);
    QPushButton* load = new QPushButton(QStringLiteral("Use selected example"), examplePage);
    load->setObjectName(QStringLiteral("loadExample"));
    exampleLayout->addWidget(load, 0, Qt::AlignLeft);
    QObject::connect(load, &QPushButton::clicked, this, [this]() { loadExample(examples_->currentRow()); });
    tabs_->addTab(examplePage, QStringLiteral("Examples"));

    QWidget* resultsPage = new QWidget(tabs_);
    QVBoxLayout* resultLayout = new QVBoxLayout(resultsPage);
    resultLayout->setContentsMargins(16, 16, 16, 16);
    resultStatus_ = new QLabel(QStringLiteral("Completed runs appear here."), resultsPage);
    resultStatus_->setWordWrap(true);
    resultLayout->addWidget(resultStatus_);
    QSplitter* split = new QSplitter(resultsPage);
    outputs_ = new QListWidget(split);
    outputs_->setObjectName(QStringLiteral("outputFiles"));
    preview_ = new QPlainTextEdit(split);
    preview_->setReadOnly(true);
    preview_->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    preview_->setLineWrapMode(QPlainTextEdit::NoWrap);
    split->addWidget(outputs_);
    split->addWidget(preview_);
    split->setStretchFactor(1, 1);
    split->setSizes(QList<int>{230, 700});
    resultLayout->addWidget(split, 1);
    QHBoxLayout* resultActions = new QHBoxLayout();
    QPushButton* openReport = new QPushButton(QStringLiteral("Open full report"), resultsPage);
    QPushButton* openFolder = new QPushButton(QStringLiteral("Open run folder"), resultsPage);
    resultActions->addWidget(openReport);
    resultActions->addWidget(openFolder);
    resultActions->addStretch();
    resultLayout->addLayout(resultActions);
    QObject::connect(outputs_, &QListWidget::currentRowChanged, this, [this](int) { showOutput(); });
    QObject::connect(openReport, &QPushButton::clicked, this, [this]() { openLocal(last_.reportPath); });
    QObject::connect(openFolder, &QPushButton::clicked, this, [this]() { openLocal(last_.folder); });
    tabs_->addTab(resultsPage, QStringLiteral("Results"));

    console_ = new QPlainTextEdit(tabs_);
    console_->setObjectName(QStringLiteral("engineLog"));
    console_->setReadOnly(true);
    console_->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    console_->setMaximumBlockCount(10000);
    tabs_->addTab(console_, QStringLiteral("Engine log"));

    QWidget* recentPage = new QWidget(tabs_);
    QVBoxLayout* recentLayout = new QVBoxLayout(recentPage);
    history_ = new QListWidget(recentPage);
    recentLayout->addWidget(history_, 1);
    QPushButton* reopen = new QPushButton(QStringLiteral("Open selected run"), recentPage);
    recentLayout->addWidget(reopen, 0, Qt::AlignLeft);
    QObject::connect(reopen, &QPushButton::clicked, this, [this]() { openHistory(); });
    tabs_->addTab(recentPage, QStringLiteral("Recent runs"));

    QHBoxLayout* actionLayout = new QHBoxLayout();
    status_ = new QLabel(QStringLiteral("Ready"), central);
    status_->setObjectName(QStringLiteral("runStatus"));
    status_->setWordWrap(true);
    actionLayout->addWidget(status_, 1);
    cancel_ = new QPushButton(QStringLiteral("Stop run"), central);
    cancel_->setEnabled(false);
    actionLayout->addWidget(cancel_);
    run_ = new QPushButton(QStringLiteral("Run model"), central);
    run_->setObjectName(QStringLiteral("runButton"));
    run_->setMinimumWidth(140);
    actionLayout->addWidget(run_);
    outer->addLayout(actionLayout);
    progress_ = new QProgressBar(central);
    progress_->setRange(0, 0);
    progress_->setTextVisible(false);
    progress_->setFixedHeight(4);
    progress_->hide();
    outer->addWidget(progress_);
    setCentralWidget(central);
    QObject::connect(run_, &QPushButton::clicked, this, [this]() { runModel(); });
    QObject::connect(cancel_, &QPushButton::clicked, this, [this]() { runner_.cancel(); });
    QObject::connect(input_, &QLineEdit::textEdited, this, [this](const QString&) { exampleArgument_.clear(); });
    QObject::connect(modelFolder_, &QLineEdit::textChanged, this, [this](const QString&) { exampleArgument_.clear(); });
    QObject::connect(workingFolder_, &QLineEdit::textChanged, this, [this](const QString&) { exampleArgument_.clear(); });
    QObject::connect(input_, &QLineEdit::editingFinished, this, [this]() {
        if (!QFileInfo(input_->text()).isFile()) return;
        if (modelFolder_->text().isEmpty()) modelFolder_->setText(QFileInfo(input_->text()).absolutePath());
        if (workingFolder_->text().isEmpty()) workingFolder_->setText(QFileInfo(input_->text()).absolutePath());
        if (name_->text().isEmpty()) name_->setText(QFileInfo(input_->text()).completeBaseName());
    });
    runner_.statusChanged = [this](const QString& text) { status_->setText(text); };
    runner_.consoleReady = [this](const QString& text) {
        console_->moveCursor(QTextCursor::End);
        console_->insertPlainText(text);
        console_->ensureCursorVisible();
    };
    runner_.finished = [this](const RunResult& result) { showResult(result); };

    QMenu* help = menuBar()->addMenu(QStringLiteral("Help"));
    QAction* manual = help->addAction(QStringLiteral("Open program manual"));
    QObject::connect(manual, &QAction::triggered, this, [this]() {
        openLocal(QDir(resourceFolder()).filePath(engine_->currentIndex() == 0 ? QStringLiteral("manuals/feq.pdf") : QStringLiteral("manuals/fequtl.pdf")));
    });
    QAction* licenses = help->addAction(QStringLiteral("Open licenses and Qt sources"));
    QObject::connect(licenses, &QAction::triggered, this, []() {
        openLocal(QDir(resourceFolder()).filePath(QStringLiteral("licenses")));
    });
    QAction* about = help->addAction(QStringLiteral("About FEQ Workbench"));
    QObject::connect(about, &QAction::triggered, this, [this]() {
        QMessageBox::about(this, QStringLiteral("About FEQ Workbench"), QStringLiteral("FEQ Workbench\nNative FEQ 10.61 and FEQUTL 5.80\n\nWork: Astra\nSponsor: Rainstar\nFoundation: Hashem\n\nNew project work is MIT licensed. Historical program and runtime notices are preserved with the installation.\n\nUses Qt, copyright The Qt Company Ltd. and contributors, under LGPL version 3. License texts and matching Qt sources are included in licenses/qt."));
    });
    setStyleSheet(QStringLiteral(
        "QMainWindow, QWidget { background: #f5f6f3; color: #182c3a; }"
        "QLabel#title { font-size: 28px; font-weight: 650; }"
        "QLabel#subtitle { color: #526572; padding-bottom: 8px; }"
        "QTabWidget::pane { border: 1px solid #d4deda; border-radius: 6px; }"
        "QTabBar::tab { padding: 10px 18px; border: 0; border-bottom: 3px solid transparent; background: transparent; }"
        "QTabBar::tab:selected { color: #126b72; border-bottom: 3px solid #187c80; }"
        "QLineEdit, QComboBox { background: white; border: 1px solid #becdc8; border-radius: 5px; padding: 8px; }"
        "QPushButton { border: 1px solid #b9cac4; border-radius: 5px; padding: 9px 14px; background: #ffffff; }"
        "QPushButton:hover { background: #e6f0ed; }"
        "QPushButton:disabled { color: #879691; background: #e9eeeb; }"
        "QPushButton#runButton { background: #166f75; border-color: #166f75; color: white; font-weight: 600; }"
        "QPushButton#runButton:disabled { background: #92b4b4; border-color: #92b4b4; }"
        "QListWidget, QPlainTextEdit { background: white; border: 1px solid #d4deda; border-radius: 4px; }"
        "QListWidget::item { padding: 10px; }"
        "QListWidget::item:selected { color: #123f44; background: #dbecea; }"
        "QProgressBar { border: 0; background: #d6e3de; }"
        "QProgressBar::chunk { background: #187c80; }"));
    refreshHistory();
}

MainWindow::~MainWindow() {
    runner_.statusChanged = {};
    runner_.consoleReady = {};
    runner_.finished = {};
    runner_.cancel();
}

void MainWindow::chooseInput() {
    const QString path = QFileDialog::getOpenFileName(this, QStringLiteral("Choose the main input file"), input_->text());
    if (path.isEmpty()) return;
    input_->setText(path);
    name_->setText(QFileInfo(path).completeBaseName());
    modelFolder_->setText(QFileInfo(path).absolutePath());
    workingFolder_->setText(QFileInfo(path).absolutePath());
    exampleArgument_.clear();
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        const QByteArray beginning = file.read(8192).toUpper();
        if (beginning.contains("STDTAB=")) engine_->setCurrentIndex(1);
        else if (beginning.contains("RUN CONTROL BLOCK")) engine_->setCurrentIndex(0);
    }
    tabs_->setCurrentIndex(0);
}

void MainWindow::loadExample(int index) {
    if (runner_.busy() || index < 0 || index >= 6) return;
    const QDir source(QDir(resourceFolder()).filePath(QStringLiteral("examples")));
    const Example& example = examples[index];
    input_->setText(source.filePath(QStringLiteral("data/")+QString::fromUtf8(example.input)));
    modelFolder_->setText(source.absolutePath());
    workingFolder_->setText(source.filePath(QStringLiteral("test")));
    name_->setText(QString::fromUtf8(example.title));
    engine_->setCurrentIndex(example.engine == Engine::simulation ? 0 : 1);
    exampleArgument_ = QString::fromUtf8(example.argument);
    status_->setText(QStringLiteral("Example loaded. Select Run model to begin."));
    tabs_->setCurrentIndex(0);
}

void MainWindow::setBusy(bool busy) {
    form_->setEnabled(!busy);
    folders_->setEnabled(!busy);
    run_->setEnabled(!busy);
    cancel_->setEnabled(busy);
    progress_->setVisible(busy);
}

void MainWindow::runModel() {
    if (runner_.busy()) return;
    RunRequest request;
    request.engine = engine_->currentIndex() == 0 ? Engine::simulation : Engine::tables;
    request.executable = enginePath(request.engine);
    request.modelFolder = modelFolder_->text();
    request.inputFile = input_->text();
    request.workingFolder = workingFolder_->text();
    request.resultsFolder = resultsFolder_->text();
    request.name = name_->text();
    request.inputArgument = exampleArgument_;
    QSettings settings;
    settings.setValue(QStringLiteral("resultsFolder"), request.resultsFolder);
    console_->clear();
    setBusy(true);
    runner_.start(request);
}

bool MainWindow::running() const { return runner_.busy(); }
RunResult MainWindow::lastResult() const { return last_; }

void MainWindow::showResult(const RunResult& result) {
    last_ = result;
    setBusy(false);
    status_->setText(result.message);
    resultStatus_->setText(result.message);
    outputs_->clear();
    for (qsizetype index = 0; index < result.outputs.size(); ++index) {
        const QJsonObject output = result.outputs.at(index).toObject();
        const QString relative = output.value(QStringLiteral("path")).toString();
        QListWidgetItem* item = new QListWidgetItem(QFileInfo(relative).fileName(), outputs_);
        item->setData(Qt::UserRole, QDir(result.folder).filePath(relative));
        item->setToolTip(relative);
    }
    const QString log = QDir(result.folder).filePath(QStringLiteral("console.log"));
    if (!result.folder.isEmpty() && QFileInfo::exists(log)) {
        QListWidgetItem* item = new QListWidgetItem(QStringLiteral("Engine log"), outputs_);
        item->setData(Qt::UserRole, log);
    }
    if (outputs_->count() > 0) {
        int selected = 0;
        for (int index = 0; index < outputs_->count(); ++index) {
            if (outputs_->item(index)->data(Qt::UserRole).toString() == result.reportPath) selected = index;
        }
        outputs_->setCurrentRow(selected);
    } else preview_->setPlainText(result.message);
    tabs_->setCurrentIndex(result.outputs.isEmpty() && result.folder.isEmpty() ? 0 : 2);
    if (!result.folder.isEmpty()) {
        QSettings settings;
        QStringList folders = settings.value(QStringLiteral("recentRuns")).toStringList();
        folders.removeAll(result.folder);
        folders.prepend(result.folder);
        while (folders.size() > 30) folders.removeLast();
        settings.setValue(QStringLiteral("recentRuns"), folders);
        refreshHistory();
    }
}

void MainWindow::showOutput() {
    const QListWidgetItem* item = outputs_->currentItem();
    if (item == nullptr) return;
    QFile file(item->data(Qt::UserRole).toString());
    if (!file.open(QIODevice::ReadOnly)) { preview_->setPlainText(QStringLiteral("This output file is no longer available.")); return; }
    const QByteArray bytes = file.read(2*1024*1024);
    if (bytes.contains('\0')) { preview_->setPlainText(QStringLiteral("This is a binary output. It is saved in the run folder.")); return; }
    QString text = bytes.isValidUtf8() ? QString::fromUtf8(bytes) : QString::fromLatin1(bytes);
    if (!file.atEnd()) text += QStringLiteral("\n\n[Preview limited to 2 MiB. Open the full report to read the complete file.]");
    preview_->setPlainText(text);
}

void MainWindow::refreshHistory() {
    history_->clear();
    const QStringList folders = QSettings().value(QStringLiteral("recentRuns")).toStringList();
    for (qsizetype index = 0; index < folders.size(); ++index) {
        QFile file(QDir(folders.at(index)).filePath(QStringLiteral("run.json")));
        if (!file.open(QIODevice::ReadOnly)) continue;
        const QJsonObject record = QJsonDocument::fromJson(file.readAll()).object();
        QListWidgetItem* item = new QListWidgetItem(record.value(QStringLiteral("name")).toString()+QStringLiteral(" · ")+
            record.value(QStringLiteral("status")).toString()+QStringLiteral("\n")+folders.at(index), history_);
        item->setData(Qt::UserRole, folders.at(index));
        item->setSizeHint(QSize(100, 58));
    }
    if (history_->count() > 0) history_->setCurrentRow(0);
}

void MainWindow::openHistory() {
    const QListWidgetItem* item = history_->currentItem();
    if (item == nullptr) return;
    const QString folder = item->data(Qt::UserRole).toString();
    QFile file(QDir(folder).filePath(QStringLiteral("run.json")));
    if (!file.open(QIODevice::ReadOnly)) return;
    const QJsonObject record = QJsonDocument::fromJson(file.readAll()).object();
    RunResult result;
    result.folder = folder;
    result.workingFolder = QDir(QDir(folder).filePath(QStringLiteral("model"))).filePath(record.value(QStringLiteral("working_folder")).toString());
    const QJsonArray arguments = record.value(QStringLiteral("arguments")).toArray();
    if (arguments.size() > 1) result.reportPath = QDir(result.workingFolder).filePath(arguments.at(1).toString());
    if (arguments.size() > 2) result.tablePath = QDir(result.workingFolder).filePath(arguments.at(2).toString());
    result.status = record.value(QStringLiteral("status")).toString();
    result.message = record.value(QStringLiteral("message")).toString();
    result.outputs = record.value(QStringLiteral("outputs")).toArray();
    showResult(result);
}
}
