#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller/settings.h"
#include <QDebug>
#include "Model/room.h"

namespace Ui {
class MainWindow;
}

struct GuiEvent
{
    Settings::Keys key;
    Settings::Types type;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showErrorMessage(GuiErrorMessage errorType);
    void newRoomCreated(const Room& newRoom);
private:
    Ui::MainWindow *ui;
signals:
    void CreateRoomSignal(QString roomName, QString roomPassword);
    void SendMessageSignal(ChatMessage message);
private slots:
    void connectBtnClicked();
    void createBtnClicked();
};

#endif // MAINWINDOW_H
