#include "audiocontroller.h"

AudioController::AudioController(QObject *parent) : QObject(parent)
{
    QAudioFormat audioFormat;
    audioFormat.setSampleRate(44100);
    audioFormat.setChannelCount(1);
    audioFormat.setSampleSize(16);
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo inputInfo = QAudioDeviceInfo::defaultInputDevice();
    if (!inputInfo.isFormatSupported(format)) {
        qWarning() << "Default format for input device is not supported, trying to use the nearest.";
        format = inputInfo.nearestFormat(format);
    }

    audioInput = new QAudioInput(audioFormat,this);
    audioOutput = new QAudioOutput(audioFormat,this);

    connect(audioInput, &QAudioInput::stateChanged, this, &AudioController::handleInputStateChanging);
    connect(audioOutput, &QAudioOutput::stateChanged, this, &AudioController::handleOutputStateChanging);

    outputAudioBuffer.open(QBuffer::ReadWrite);
    inputAudioBuffer.open(QBuffer::ReadWrite);

    QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();
    QAudioDeviceInfo outputDevice = QAudioDeviceInfo::defaultOutputDevice();
}

QByteArray AudioController::getDataFromDevice()
{
    inputAudioBuffer.seek(0);
    audioInput->start(&inputAudioBuffer);
    return QByteArray(inputAudioBuffer.data());
}

void AudioController::pushDataToOutput(const QVector<QPair<QString, QByteArray> > &audioData)
{
    outputAudioBuffer.seek(0);
    outputAudioBuffer.setData(nullptr);
    audioOutput->start(&outputAudioBuffer);
}

void AudioController::handleInputStateChanging(QAudio::State state)
{
    qDebug() << "New input "  << state;
    if (audioInput->error() != QAudio::NoError){
        qWarning() << "Input error : " << audioInput->error();
    }
}

void AudioController::handleOutputStateChanging(QAudio::State state)
{
    qDebug() << "New output "  << state;
    if (audioOutput->error() != QAudio::NoError){
        qWarning() << "Output error : " << audioOutput->error();
    }
}

