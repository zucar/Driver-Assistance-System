#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_comboBox_highlighted(const QString &arg1);
    void on_pushButton_4_clicked();\
    void on_srchBtn_clicked();
    void on_setPortBtn_clicked();
    void readfromAdruino() ;
    void on_parkBtn_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *SerialPort ;
    QString port_name ;
    QStringList Ports ;
    bool SerialIsAvailable = false ;
    QByteArray searchCmd = "s" ;
    QByteArray parkCmd = "p" ;
    bool validParkSpot = false ;
    QByteArray receivedData = "" ;
    bool paramReceived = false ;
    void getParam(QByteArray rcvData);

};

#endif // MAINWINDOW_H
