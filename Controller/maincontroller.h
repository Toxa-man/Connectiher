#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "Network/network.h"
#include <QEvent>
#include <QDebug>
#include "View/mainwindow.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = 0);
    void startAll();
private:
    NetworkManager *Network;
    MainWindow *mainWindow;
signals:

public slots:
    void GuiEventSlot(GuiEvent event);
};

#endif // MAINCONTROLLER_H
