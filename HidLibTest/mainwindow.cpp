#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hidlib.h"
#include "receiverthread.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QVector <HidReceiver> receivers = HidLib::getHidList();
    if(receivers.size() > 0)
    {
        ReceiverThread * receiverThread = new ReceiverThread(receivers[0]);
        connect(receiverThread, SIGNAL(newMessage(ReceiverData)), this, SLOT(getNewHidData(ReceiverData)));
        receiverThread->start();
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNewHidData(ReceiverData receiverData)
{
    ui->pultIdLineEdit->setText(QString::number(receiverData.getPultId()));
    ui->messageIdLineEdit->setText(QString::number(receiverData.getMessageId()));
    ui->batteryLineEdit->setText(QString::number(receiverData.getBatteryValue()));
    ui->insertIndexLineEdit->setText(QString::number(receiverData.getBufferInsertIndex()));
    ui->extractIndexLineEdit->setText(QString::number(receiverData.getBufferExtractIndex()));
    ui->keyCodeLineEdit->setText(receiverData.getKeyCode());
    QString keyData = "";
    for(int i = 0; i < receiverData.getKeyData().length(); i++)
    {
        keyData += receiverData.getKeyData().at(i);
        keyData += ".";
    }
    ui->keyDataLineEdit->setText(keyData);
    ui->keyIndexLineEdit->setText(QString::number(receiverData.getKeyIndex()));
    ui->packetNumberLineEdit->setText(QString::number(receiverData.getPacketCount()));
    ui->pultReceiverIdLineEdit->setText(QString::number(receiverData.getPultReceiverId()));
    QString data = "";
    for(int i = 0; i < receiverData.getData().length(); i++)
    {
        data += QString::number(receiverData.getData().at(i));
        data += ".";
    }
    ui->receiverDataListWidget->insertItem(0, data);
    ui->universalLineEdit->setText(QString::number(receiverData.getIsUniversal()));
    ui->t2LineEdit->setText(QString::number(receiverData.getT2()));
    ui->receiverIdLineEdit->setText(QString::number(receiverData.getReceiverId()));
    ui->rssiLineEdit->setText(QString::number(receiverData.getRSSI()));
}
