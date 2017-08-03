#include "model.h"

DataModel::DataModel(QObject *parent) : QObject(parent)
{

}

bool DataModel::haveCreatedRoom(QString roomName)
{
    return CreatedRooms.contains(Room(roomName));
}

void DataModel::addNewCreatedRoom(Room newRoom)
{
    CreatedRooms.push_back(newRoom);
}

Room DataModel::getCurrentRoom() const
{
    return CurrentRoom;
}

void DataModel::setCurrentRoom(const Room &value)
{
    CurrentRoom = value;
}

