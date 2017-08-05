#include "audiocontroller.h"

AudioController::AudioController(QObject *parent) : QObject(parent)
{

}

QByteArray AudioController::getDataFromDevice()  //YARIK::ATTENTION: implement this method, it should return data readed from input device (mic, for example)
{
    return QByteArray();
}

void AudioController::pushDataToOutput(const Room &room) //YARIK::ATTENTION: implement this method. It should run over every user in room, get it's audio data and out it to device (dynamics for example)
{

}

