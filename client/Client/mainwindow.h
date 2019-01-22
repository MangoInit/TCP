#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTcpSocket"
#include "QMessageBox"

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
    void printServerMessage();
    void displayError(QAbstractSocket::SocketError);
    void display_disconnected();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QTcpSocket *client;
};

#endif // MAINWINDOW_H
