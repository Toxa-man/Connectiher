#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "Model/user.h"
#include <QVector>
#include <QString>

class Room
{

public:
    Room();
    Room(QString RoomName, QString RoomPassword = "", quint16 port = 0);
    friend bool operator ==(const Room& left, const Room& right);
    User *getRoomAdministrator() const;
    void setRoomAdministrator(User *value);

private:
    QString roomName;
    QString roomPassword;
    quint16 port;
    User* RoomAdministrator;
    QVector<User> Users;
signals:

public slots:
};

#endif // ROOM_H
