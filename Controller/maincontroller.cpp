#include "maincontroller.h"

MainController::MainController(QObject *parent) : QObject(parent)
{

}

void MainController::startAll()
{
    Network = new NetworkManager(this);
    mainWindow = new MainWindow();
    mainWindow->show();
    connect(mainWindow, &MainWindow::GuiEventSignal, this, &MainController::GuiEventSlot);

}

void MainController::GuiEventSlot(GuiEvent event)
{
}
