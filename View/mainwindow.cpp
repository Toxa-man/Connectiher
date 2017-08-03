#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connectBtn, &QPushButton::clicked, this, &MainWindow::connectBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showErrorMessage(GuiErrorMessage errorType)
{
    //TODO: Show user error message with error text
}

void MainWindow::newRoomCreated(const Room &newRoom)
{
    //TODO: Draw new room in crated section
}

void MainWindow::connectBtnClicked()
{

}

void MainWindow::createBtnClicked()
{
    emit CreateRoomSignal(QString("Name"), QString("Pass"));
}
