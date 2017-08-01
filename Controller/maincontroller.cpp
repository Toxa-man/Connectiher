#include "maincontroller.h"

MainController::MainController(QObject *parent) : QObject(parent)
{

}

void MainController::startAll()
{
    Network = new NetworkManager(this);
    Model = new DataModel(this);
    mainWindow = new MainWindow();
    mainWindow->show();
    connect(mainWindow, &MainWindow::GuiEventSignal, this, &MainController::GuiEventSlot);

}

void MainController::GuiEventSlot(GuiEvent event)
{
}

void MainController::createRoomSlot(QString roomName, QString roomPassword)
{
    if (Model->haveCreatedRoom(roomName)){
        mainWindow->showErrorMessage(GuiErrorMessage::CreatingRoomExists);
        return;
    }
    QPair<CreateResponses, quint16> response = Network->createRoom();
    switch (response.first) {
    case CreateResponses::Success:{
        Room newRoom(roomName, roomPassword, response.second);
        newRoom.setRoomAdministrator(CURRENT_USER);
        Model->addNewCreatedRoom(newRoom);
        mainWindow->newRoomCreated(newRoom);
        break;
    }
    case CreateResponses::Failed:{
        mainWindow->showErrorMessage(GuiErrorMessage::CantCreateRoom);
        break;
    }
    default:
        break;
    }

}
