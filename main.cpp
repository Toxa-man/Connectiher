#include "View/mainwindow.h"
#include <QApplication>
#include "Controller/maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController *mainController = new MainController;
    mainController->startAll();

    return a.exec();
}
