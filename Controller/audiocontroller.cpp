#include "audiocontroller.h"

AudioController::AudioController(QObject *parent) : QObject(parent)
{
    QAudioFormat audioFormat;
    audioFormat.setSampleRate(8000);
    audioFormat.setChannelCount(1);
    audioFormat.setSampleSize(8);
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setSampleType(QAudioFormat::UnSignedInt);

    audioInput = new QAudioInput(audioFormat,this);
    audioOutput = new QAudioOutput(audioFormat,this);

    QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();
    QAudioDeviceInfo outputDevice = QAudioDeviceInfo::defaultOutputDevice();
}

QByteArray AudioController::getDataFromDevice()  //YARIK::ATTENTION: implement this method, it should return data readed from input device (mic, for example)
{
    inputAudioBuffer.open(QBuffer::ReadWrite);
    inputAudioBuffer.seek(0);
    audioInput->start(&inputAudioBuffer); //ANTON::ATTENTION:: when to stop writing data and return them?
    return QByteArray(inputAudioBuffer);
}

void AudioController::pushDataToOutput(const Room &room) //YARIK::ATTENTION: implement this method. It should run over every user in room, get it's audio data and out it to device (dynamics for example)
{

    outputAudioBuffer.open(QBuffer::ReadWrite);
    outputAudioBuffer.seek(0);
    outputAudioBuffer.setData(); //ANTON::ATTENTION:: Where to get data? From the previous class? If yes, how?
    audioOutput->start(&outputBuffer);
}

