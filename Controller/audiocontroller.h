#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QBuffer>
#include <Model/room.h>

class AudioController : public QObject //YARIK::ATTENTION: This is your main class, create and store all needed objects here
{
    Q_OBJECT
public:
    explicit AudioController(QObject *parent = 0);
    QByteArray getDataFromDevice();
    void pushDataToOutput(const Room& room);
signals:

public slots:
};

#endif // AUDIOCONTROLLER_H
