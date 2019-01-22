#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void acceptConnection();

    void replyToClient();

private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *serverSocket;

    QNetworkAccessManager *manager; //http server
};

#endif // MAINWINDOW_H
