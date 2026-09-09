// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "main_window.hpp"
#include <QApplication>
int main(int argc, char** argv) {
    QApplication application(argc, argv);
    QCoreApplication::setOrganizationName(QStringLiteral("Rainstar"));
    QCoreApplication::setApplicationName(QStringLiteral("FEQ Workbench"));
    QCoreApplication::setApplicationVersion(QStringLiteral("0.1.0"));
    feq_app::MainWindow window;
    window.show();
    return application.exec();
}
