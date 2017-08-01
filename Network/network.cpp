#include "network.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{

}

QPair<CreateResponses, quint16> NetworkManager::createRoom()
{
    //TODO: make a method that create a room
    return qMakePair<CreateResponses, quint16>(CreateResponses::Success, 0);
}
