#include "hidlib.h"
#include <QMessageBox>
#include "receiverthread.h"
#include "HidLibConstants.h"

HidLib::HidLib()
{
}

void HidLib::closeHid(HidReceiver receiver)
{
    hid_close(receiver.getHidDevice());
}

HidReceiver HidLib::openHid(unsigned short VID, unsigned short PID, QString serialNumber)
{
    wchar_t *serialNumberWchar = new wchar_t[serialNumber.size() + 1];
    serialNumber.toWCharArray(serialNumberWchar);
    serialNumberWchar[serialNumber.size()] = L'\0';
    hid_device *receiver = hid_open(VID, PID, serialNumberWchar);
    if(receiver != NULL)
    {
        delete serialNumberWchar;
        return HidReceiver(VID, PID, serialNumber, receiver);
    }
    else
    {
        delete serialNumberWchar;
        throw HidNotFoundException();
    }
}

QVector <HidReceiver> HidLib::getHidList()
{
    unsigned short VOTUM_VID = 8137;
    unsigned short VOTUM_PID = 276;
    struct hid_device_info *devs;
    devs = hid_enumerate(0x0, 0x0);
    QVector <HidReceiver> hidList;
    while(devs)
    {
        unsigned short VID = devs->vendor_id;
        unsigned short PID = devs->product_id;
        if(VID == VOTUM_VID && PID == VOTUM_PID)
        {
            HidReceiver tmp;
            bool ok = true;
            try
            {
                tmp = openHid(devs->vendor_id, devs->product_id, QString::fromWCharArray(devs->serial_number));
            }
            catch(HidNotFoundException e)
            {
                ok = false;
            }
            if(ok)
            {
                hidList.append(tmp);
            }
        }
        devs = devs->next;
    }
    return hidList;
}

ReceiverData HidLib::readData(HidReceiver receiver)
{
    const int length = 64;
    unsigned char data[length];
    if(hid_set_nonblocking(receiver.getHidDevice(), 0) != -1)
    {
        if(hid_read(receiver.getHidDevice(), data, length) != -1)
        {
            return ReceiverData(data);
        }
        else
        {
            throw(HidNotFoundException());
            return NULL;
        }
    }
    return NULL;
}

int HidLib::writeData(HidReceiver receiver, QVector<unsigned char> data)
{
    unsigned char *dataToWrite = new unsigned char(data.length());
    for(int i = 0; i < data.length(); i++)
    {
        dataToWrite[i] = data[i];
    }
    int res = hid_write(receiver.getHidDevice(), dataToWrite, data.length());
    delete dataToWrite;
    return res;
}

QString HidLib::getPath(HidReceiver receiver)
{
    unsigned short vid = receiver.getVid();
    unsigned short pid = receiver.getPid();
    QString serialNumber = receiver.getSerialNumber();
    wchar_t *serialNumberWchar = new wchar_t[serialNumber.size() + 1];
    serialNumber.toWCharArray(serialNumberWchar);
    serialNumberWchar[serialNumber.size()]=L'\0';
    hid_device_info *devs = hid_enumerate(vid, pid);
    while(devs)
    {
        if(QString::fromWCharArray(devs->serial_number) == QString::fromWCharArray(serialNumberWchar))
        {
            delete serialNumberWchar;
            return QString(devs->path);
        }
    }
    delete serialNumberWchar;
    return NULL;
}
