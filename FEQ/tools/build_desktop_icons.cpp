// Render the project's own SVG into platform icon formats. No hydraulic code.
// Work: Astra. Sponsor: Rainstar. Foundation: Hashem. MIT licensed.
#include <QApplication>
#include <QDir>
#include <QIcon>
#include <QImage>
#include <QString>
#include <iostream>
int main(int argc, char** argv) {
    QApplication application(argc, argv);
    if (argc != 3) return 2;
    const QIcon icon(QString::fromLocal8Bit(argv[1]));
    const QDir output(QString::fromLocal8Bit(argv[2]));
    if (icon.isNull() || !QDir().mkpath(output.absolutePath())) return 2;
    const int sizes[] = {16, 32, 64, 128, 256, 512, 1024};
    for (int index = 0; index < 7; ++index) {
        const int size = sizes[index];
        const QImage image = icon.pixmap(size, size).toImage();
        if (!image.save(output.filePath(QStringLiteral("icon_%1.png").arg(size)))) return 1;
    }
    if (!icon.pixmap(256, 256).toImage().save(output.filePath(QStringLiteral("feq-workbench.ico")), "ICO")) return 1;
    std::cout << "Rendered platform icons from the project SVG\n";
    return 0;
}
