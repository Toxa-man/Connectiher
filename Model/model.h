#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>
#include <QVector>
#include "Model/room.h"

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);


private:
    QVector<Room> ConnectedRooms;
    QVector<Room> CreatedRooms;
signals:

public slots:
};

#endif // MODEL_H
