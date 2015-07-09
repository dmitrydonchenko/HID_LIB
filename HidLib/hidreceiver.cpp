#include "hidreceiver.h"


HidReceiver::HidReceiver()
{
}

HidReceiver::HidReceiver(unsigned short VID, unsigned short PID, QString serialNumber, hid_device *hidDevice)
{
    this->VID = VID;
    this->PID = PID;
    this->serialNumber = serialNumber;
    this->hidDevice = hidDevice;
}

QString HidReceiver::getSerialNumber()
{
    return serialNumber;
}

unsigned short HidReceiver::getPid()
{
    return PID;
}

unsigned short HidReceiver::getVid()
{
    return VID;
}

hid_device *HidReceiver::getHidDevice()
{
    return this->hidDevice;
}


