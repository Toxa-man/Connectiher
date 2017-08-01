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

private:
    QVector<Room> ConnectedRooms;
    QVector<Room> CreatedRooms;
signals:

public slots:
};

#endif // MODEL_H
