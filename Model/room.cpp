#include "room.h"

Room::Room()
{

}

Room::Room(QString RoomName, QString RoomPassword, quint16 port):roomName(RoomName), roomPassword(RoomPassword), port(port)
{
}

User *Room::getRoomAdministrator() const
{
    return RoomAdministrator;
}

void Room::setRoomAdministrator(User *value)
{
    RoomAdministrator = value;
}

RoomType Room::getRoomType() const
{
    return roomType;
}

void Room::setRoomType(const RoomType &value)
{
    roomType = value;
}

void Room::setUserAudioData(QString name, const QByteArray &audioData) //TODO: may be make more safe
{
    if (Users.indexOf(User(name)) >= 0){
        Users[Users.indexOf(User(name))].setAudioData(audioData);
    }
}

bool operator ==(const Room& left, const Room &right)
{
    return right.roomName == left.roomName;
}
