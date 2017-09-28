#ifndef SERVERROOM_H
#define SERVERROOM_H
#include <QTcpServer>
#include <QString>

class ServerRoom
{
public:
    ServerRoom();
private:
    QTcpServer Server;
    QString roomName;
};

#endif // SERVERROOM_H
