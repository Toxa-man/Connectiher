#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QBuffer>
#include <Model/room.h>
#include <QAudioInput> //ANTON::ATTENTION:: QAudioInput/Output connected with QObject, isn't it?
#include <QAudioOutput>
#include <QDebug>

class AudioController : public QObject //YARIK::ATTENTION: This is your main class, create and store all needed objects here
{
    Q_OBJECT
public:
    explicit AudioController(QObject *parent = 0);
    QByteArray getDataFromDevice();
    void pushDataToOutput(const Room& room);
signals:
private:
    QBuffer inputAudioBuffer;
    QAudioInput *audioInput;
    QAudioDeviceInfo inputDevice;
    QBuffer outputAudioBuffer;
    QAudioInput *audioOutput;
    QAudioDeviceInfo outputDevice;
public slots:
};

#endif // AUDIOCONTROLLER_H
