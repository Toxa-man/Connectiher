#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "Model/user.h"
#include <QVector>
#include <QString>
#include <QDateTime>
#include <QBuffer>
#include <QPair>

struct ChatMessage
{
    QString authorName;
    QString messageText;
    QDateTime sendTime;
};

enum class RoomType{Created, Connected};

class Room
{

public:
    Room();
    Room(QString RoomName, QString RoomPassword = "", quint16 port = 0);
    friend bool operator ==(const Room& left, const Room& right);
    User *getRoomAdministrator() const;
    void setRoomAdministrator(User *value);

    RoomType getRoomType() const;
    void setRoomType(const RoomType &value);
    void setUserAudioData(QString name, const QByteArray& audioData);

    QVector<QPair<QString, QByteArray>> getRoomAudioData(); //first - user name, second - data;

private:
    QString roomName;
    QString roomPassword;
    quint16 port;
    User* RoomAdministrator;
    QVector<User> Users;
    QVector<ChatMessage> ChatMessage;
    RoomType roomType;

signals:

public slots:
};

#endif // ROOM_H
