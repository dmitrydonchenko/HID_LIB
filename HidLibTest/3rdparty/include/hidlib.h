#ifndef HIDLIB_H
#define HIDLIB_H

#include "hidlib_global.h"
#include "hidreceiver.h"
#include "receiverdata.h"
#include "hidnotfoundexception.h"
#include "hidapi.h"
#include <QApplication>

class HIDLIBSHARED_EXPORT HidLib
{
public:
    HidLib();

    static void closeHid(HidReceiver receiver);
    static HidReceiver openHid(unsigned short VID, unsigned short PID, QString serialNumber);
    static QVector <HidReceiver> getHidList();
    static ReceiverData readData(HidReceiver receiver);
    static int writeData(HidReceiver receiver, QVector <unsigned char> data);
    static QString getPath(HidReceiver receiver);
};

#endif // HIDLIB_H
