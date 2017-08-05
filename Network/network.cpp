#include "network.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{

}

QPair<CreateResponses, quint16> NetworkManager::createRoom()
{
    //TODO: make a method that create a room
    return qMakePair<CreateResponses, quint16>(CreateResponses::Success, 0);
}

SendMessageResponses NetworkManager::sendMessageToRoom(const ChatMessage &message, Room RoomToSend)
{

}

void NetworkManager::sendAudioDataToUsers(const Room &room)
{
    //TODO: implement method. It should send all users aduio data to each user except from whom data was recieved.
}

Room NetworkManager::getAudioDataFromNetwork(const Room& currentRoom)
{
    //TODO: implement method. It should return all avilable audio data
    return Room();
}
