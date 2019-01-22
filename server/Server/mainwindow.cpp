#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server");
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::Any,6666))     //监听是否后客户端连接
    {
        qDebug()<<server->errorString();
        close();
    }

    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));

    //http server
    manager = new QNetworkAccessManager(this);
    manager->connectToHost("localhost", 8080);
}


void MainWindow::acceptConnection()
{
    serverSocket = server->nextPendingConnection();
    connect(serverSocket,SIGNAL(readyRead()),this,SLOT(replyToClient()));
    connect(serverSocket,SIGNAL(disconnected()),serverSocket,SLOT(deleteLater()));
}

void MainWindow::replyToClient()
{
    QString msg = QString(serverSocket->readAll());
    QMessageBox::information(this, "来自客户端的消息", msg);
//    const char *replyMsg = "server: I am server, I got your message.";
    QByteArray replyMsg("server: I am server, I got your message.");
    serverSocket->write(replyMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
