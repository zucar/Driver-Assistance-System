#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <Windows.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    SerialPort = new QSerialPort ;
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        Ports.append(serialPortInfo.portName());

    }
     ui->comboBox->addItems(Ports);

   //  qDebug() << SerialPort->readAll() ;

}

MainWindow::~MainWindow()
{
    SerialPort->close();
    delete ui;
}


void MainWindow::on_setPortBtn_clicked()
{
     ui->SPOT_WIDTH->setText(ui->SPOT_WIDTH->text()+port_name) ;
     SerialIsAvailable = true ;
     if(SerialIsAvailable){

        SerialPort->setPortName(port_name);
        SerialPort->setBaudRate(QSerialPort::Baud9600);
        SerialPort->open(QSerialPort::ReadWrite);
        SerialPort->setParity(QSerialPort::NoParity);
        SerialPort->setFlowControl(QSerialPort::NoFlowControl);
        SerialPort->setDataBits(QSerialPort::Data8);
        QObject::connect(SerialPort,SIGNAL(readyRead()),this,SLOT(readfromAdruino()));

     }

}

void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    this->port_name = arg1 ;
\

}

void MainWindow::on_pushButton_4_clicked() 
{
    if(SerialIsAvailable == true){
        QByteArray data = ui->sendData->toPlainText().toUtf8();
        SerialPort->write(data);
    }


}

void MainWindow::readfromAdruino(){
   QByteArray data ;
   data =  SerialPort->readAll() ;
   receivedData = receivedData.append(data) ;
   if(receivedData.contains("\n")){
       qDebug() << receivedData ;
       paramReceived = true ;
       getParam(receivedData);
   }
}

//Send command to start search
void MainWindow::on_srchBtn_clicked()
{
    if(SerialIsAvailable == true){
        receivedData ="";
        SerialPort->write(this->searchCmd);
    }

}


void MainWindow::on_parkBtn_clicked()
{
    if(SerialIsAvailable == true && validParkSpot == true ){
        SerialPort->write(this->searchCmd);
    }
}


void MainWindow::getParam(QByteArray rcvData){
    QString rcv(rcvData);
    receivedData = "" ;
    QStringList spotData ;
    rcv = rcv.replace("(","") ;
    rcv = rcv.replace(")","");
    rcv.remove(QRegExp("[\n\r]"));
    qDebug() << "String: " << rcv ;
    spotData = rcv.split(",") ;
    ui->SPOT_X->setText("SPOT X = " +spotData[0]);
    ui->SPOT_Y->setText("SPOT Y = " +spotData[1]);
    ui->SPOT_WIDTH->setText("SPOT WIDTH = " +spotData[2]);
    ui->SPOT_DEPTH->setText("SPOT DEPTH = " +spotData[3]);

}
