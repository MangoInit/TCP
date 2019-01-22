#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Client");
    client = new QTcpSocket(this);
//    client->setSocketOption(QAbstractSocket::KeepAliveOption, true);
    client->connectToHost("192.168.51.155",6666);//TCP连接
    QByteArray data = "client:hello server, I am client.";
//    const char* data = "client:hello server, I am client.";
    client->write(data);//发送
    connect(client,SIGNAL(readyRead()),this,SLOT(printServerMessage()));
//    connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(client,SIGNAL(disconnected()), this,SLOT(display_disconnected()));
}

void MainWindow::printServerMessage()
{
    QString msg = QString(client->readAll());
    QMessageBox::information(this,"message from server",msg);
}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<client->errorString();
}

void MainWindow::display_disconnected()
{
    qDebug() << "disconnected";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    client->write("Hello,World!\n");
}
