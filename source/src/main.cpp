#include <QtGui/QApplication>
#include "../headers/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator myTranslator;
    myTranslator.load("lang/untitled_" + QLocale::system().name());
    app.installTranslator(&myTranslator);

    MainWindow w;

    w.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    w.showMaximized();
    w.show();

    return app.exec();
}
