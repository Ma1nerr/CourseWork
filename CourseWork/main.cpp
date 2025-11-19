#include <QApplication>
#include "MainWindow.h"
#include "StartupDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartupDialog startup;
    MainWindow mainWindow;

    // Підключаємо сигнал вибору файлу до методу завантаження головного вікна
    QObject::connect(&startup, &StartupDialog::fileSelected, &mainWindow, &MainWindow::loadFromFile);

    if (startup.exec() == QDialog::Accepted) {
        mainWindow.show();
        return a.exec();
    }

    return 0;
}
