#ifndef HIDRECEIVER_H
#define HIDRECEIVER_H

#include "hidlib_global.h"
#include <QString>

#include "hidapi.h"

class HIDLIBSHARED_EXPORT HidReceiver
{

public:
    HidReceiver();
    HidReceiver(unsigned short VID, unsigned short PID, QString serialNumber, hid_device *hidDevice);

    unsigned short getVid();
    unsigned short getPid();
    QString getSerialNumber();

    hid_device *getHidDevice();

private:
    unsigned short VID;
    unsigned short PID;
    QString serialNumber;

    hid_device *hidDevice;
};

#endif // HIDRECEIVER_H
