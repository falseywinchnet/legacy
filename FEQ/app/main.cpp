// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include "main_window.hpp"
#include "verify_installation.hpp"
#include <QApplication>
int main(int argc, char** argv) {
    QApplication application(argc, argv);
    QCoreApplication::setOrganizationName(QStringLiteral("Rainstar"));
    QCoreApplication::setApplicationName(QStringLiteral("FEQ Workbench"));
    QCoreApplication::setApplicationVersion(QStringLiteral("0.1.0"));
    const QStringList arguments = application.arguments();
    if (arguments.size() == 3 && arguments.at(1) == QStringLiteral("--verify-installation")) {
        return feq_app::verifyInstallation(application, arguments.at(2));
    }
    feq_app::MainWindow window;
    window.show();
    return application.exec();
}
