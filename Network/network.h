#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QPair>
#include <QString>
#include "Model/room.h"
#include <QByteArray>
#include "Model/user.h"

enum ConnectResponses{Success, Timeout, WrongPassword, Banned, Overloaded};
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
signals:
    void tryingToConnect(User user, quint16 port);

public slots:
};

#endif // NETWORK_H
