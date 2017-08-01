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

