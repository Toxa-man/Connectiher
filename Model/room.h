#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "Model/user.h"
#include <QVector>

class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(QObject *parent = 0);
private:
    User RoomAdministrator;
    QVector<User> Users;
signals:

public slots:
};

#endif // ROOM_H
