#ifndef CREATEROOMDIALOG_H
#define CREATEROOMDIALOG_H

#include <QMainWindow>

namespace Ui {
class CreateRoomDialog;
}

class CreateRoomDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateRoomDialog(QWidget *parent = 0);
    ~CreateRoomDialog();

private:
    Ui::CreateRoomDialog *ui;
};

#endif // CREATEROOMDIALOG_H
