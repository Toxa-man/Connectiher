#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QBuffer>
#include <Model/room.h>
#include <QAudioInput>
#include <QAudioOutput>
#include <QDebug>

class AudioController : public QObject
{
    Q_OBJECT
public:
    explicit AudioController(QObject *parent = 0);
    QByteArray getDataFromDevice();
    void pushDataToOutput(const QVector<QPair<QString, QByteArray>>& audioData); // first - name, second - audio data
signals:
private:
    QBuffer inputAudioBuffer;
    QAudioInput *audioInput;
    QAudioDeviceInfo inputDevice;
    QBuffer outputAudioBuffer;
    QAudioOutput *audioOutput;
    QAudioDeviceInfo outputDevice;
public slots:
private slots:
    void handleInputStateChanging(QAudio::State state);
    void handleOutputStateChanging(QAudio::State state);
};

#endif // AUDIOCONTROLLER_H
