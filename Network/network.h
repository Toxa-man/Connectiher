#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QPair>
#include <QString>
#include "Model/room.h"
#include <QByteArray>
#include "Model/user.h"

enum class ConnectResponses{Success, Timeout, WrongPassword, Banned, Overloaded};
enum class CreateResponses{Success, Failed};
enum class SendMessageResponses{Success, Failed};
class IP4
{
public:
    IP4();
    IP4(QByteArray ip4);
    IP4(quint8 *ip4);
    IP4(QString ip4);
    QString toString() const;
    QByteArray toQByteArray() const;
    void operator =(const QString& str);
    void operator =(const QByteArray& arr);
private:
    QByteArray data;

};

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    QPair<ConnectResponses, Room*> connectToRoom(IP4 ip4, quint16 port, QString password); //return code of attempt and pointer to Room, nullptr if failed to connect
    QPair<CreateResponses, quint16> createRoom(); //return response and port if successed
    SendMessageResponses sendMessage(const ChatMessage& message, Room RoomToSend);
signals:
    void tryingToConnect(User user, quint16 port);

public slots:
};

#endif // NETWORK_H
