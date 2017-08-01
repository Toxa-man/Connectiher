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
signals:

public slots:
    void GuiEventSlot(GuiEvent event);
    void createRoomSlot(QString roomName, QString roomPassword);
};

#endif // MAINCONTROLLER_H
