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
    connect(mainWindow, &MainWindow::SendMessageSignal, this, &MainController::SendMessageSlot);
    connect(mainWindow, &MainWindow::CreateRoomSignal, this, &MainController::createRoomSlot);

}


void MainController::createRoomSlot(QString roomName, QString roomPassword)
{
    if (Model->haveCreatedRoom(roomName)){ //check this room: exist or not?
        mainWindow->showErrorMessage(GuiErrorMessage::CreatingRoomExists);//if exist, show error
        return;
    }
    QPair<CreateResponses, quint16> response = Network->createRoom();//if not, create new
    switch (response.first) {//check status
    case CreateResponses::Success:{//if succ, create new
        Room newRoom(roomName, roomPassword, response.second); //parame
        newRoom.setRoomAdministrator(CURRENT_USER); //host == admin
        newRoom.setRoomType(RoomType::Created);// set type of room
        Model->addNewCreatedRoom(newRoom); //add room to a model
        mainWindow->newRoomCreated(newRoom); // window reaction on new room
        break;
    }
    case CreateResponses::Failed:{// if fail, show error
        mainWindow->showErrorMessage(GuiErrorMessage::CantCreateRoom);
        break;
    }
    default:
        break;
    }

}

void MainController::SendMessageSlot(ChatMessage message)
{
    connect(SendMessageWatcher, SIGNAL(finished()), this, SLOT(MessageSendingResult()));
    QFuture<SendMessageResponses> future = QtConcurrent::run(this->Network, &NetworkManager::sendMessageToRoom , message , Model->getCurrentRoom());
    SendMessageWatcher->setFuture(future);
}

void MainController::MessageSendingResult()
{
    if (SendMessageWatcher->result() == SendMessageResponses::Success){ //TODO: push message to vector, mark it as sended in gui

    }
}
