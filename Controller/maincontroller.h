#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "Network/network.h"
#include <QEvent>
#include <QDebug>
#include "View/mainwindow.h"
#include "Model/model.h"
#include "Controller/settings.h"
#include "Model/user.h"
#include <QThread>
#include <QFutureWatcher>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = 0);
    void startAll();
private:
    NetworkManager *Network;
    MainWindow *mainWindow;
    DataModel *Model;
    QFutureWatcher<SendMessageResponses> *SendMessageWatcher = new QFutureWatcher<SendMessageResponses>();
signals:

public slots:
    void createRoomSlot(QString roomName, QString roomPassword);
    void SendMessageSlot(ChatMessage message);
    void MessageSendingResult();
};

#endif // MAINCONTROLLER_H
