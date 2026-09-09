// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#ifndef FEQ_VERIFY_INSTALLATION_HPP
#define FEQ_VERIFY_INSTALLATION_HPP
class QApplication;
class QString;
namespace feq_app {
int verifyInstallation(QApplication& application, const QString& outputFolder);
}
#endif
