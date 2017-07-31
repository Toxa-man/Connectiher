#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Controller/settings.h>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
signals:
    void GuiEventSignal(GuiEvent event);
private slots:
    void connectBtnClicked();
    void createBtnClicked();
};

#endif // MAINWINDOW_H
