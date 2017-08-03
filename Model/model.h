#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>
#include <QVector>
#include "Model/room.h"

class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = 0);
    bool haveCreatedRoom(QString roomName);
    void addNewCreatedRoom(Room newRoom);

    Room getCurrentRoom() const;
    void setCurrentRoom(const Room &value);

private:
    QVector<Room> ConnectedRooms;
    QVector<Room> CreatedRooms;
    Room CurrentRoom;
signals:

public slots:
};

#endif // MODEL_H
