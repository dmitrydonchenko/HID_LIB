#include "receiverthread.h"
#include "hidlib.h"
#include "hidnotfoundexception.h"
#include "receiverdata.h"
#include <QMessageBox>

Q_DECLARE_METATYPE(ReceiverData)
Q_DECLARE_METATYPE(HidReceiver)

ReceiverThread::ReceiverThread(HidReceiver receiver)
{
    qRegisterMetaType <ReceiverData> ("ReceiverData");
    qRegisterMetaType <HidReceiver> ("HidReceiver");
    this->receiver = receiver;
}

void ReceiverThread::run()
{
    int oldBufferInsertIndex = -1, oldBufferExtractIndex = -1;
    while(true)
    {
        ReceiverData receiverData;
        try
        {
            receiverData = HidLib::readData(receiver);
            if(receiverData.getBufferInsertIndex() != oldBufferInsertIndex &&
                    receiverData.getBufferExtractIndex() != oldBufferExtractIndex)
            {
                emit newMessage(receiverData);
                oldBufferInsertIndex = receiverData.getBufferInsertIndex();
                oldBufferExtractIndex = receiverData.getBufferExtractIndex();
            }
        }
        catch (HidNotFoundException e)
        {
            QApplication* pApp = NULL;
            int argc = 0;char* argv[1];
            *argv = "";
            pApp = new QApplication(argc, argv);
            if(!reconnectToReceiver())
            {
                delete pApp;
                this->terminate();
            }
            delete pApp;
        }
    }
}

bool ReceiverThread::reconnectToReceiver()
{
    QMessageBox msgBox;
    msgBox.setWindowIconText("Ошибка устройства");
    msgBox.setInformativeText("Usb ресивер был отключен во время работы. Подключите ресивер и нажмите \"ОК\" для повторной попытки, \"Отмена\" для выхода");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    bool isConnected = false;
    switch (ret)
    {
    case QMessageBox::Ok:
        try
        {
            receiver = HidLib::openHid(receiver.getVid(), receiver.getPid(), receiver.getSerialNumber());
            isConnected = true;
        }
        catch(HidNotFoundException e)
        {
            return reconnectToReceiver();
        }
        break;
    }
    return isConnected;
}

