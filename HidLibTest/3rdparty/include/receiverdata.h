#ifndef RECEIVERDATA_H
#define RECEIVERDATA_H

#include <qvector.h>
#include "hidlib_global.h"
#include <QString>

class HIDLIBSHARED_EXPORT ReceiverData
{
public:
    ReceiverData(unsigned char* data);
    ReceiverData();

    QVector <unsigned char> getData();

    unsigned char getMessageId();
    unsigned short getReceiverId();
    unsigned short getPultId();
    unsigned short getPultReceiverId();
    unsigned short getBatteryValue();
    QString getKeyCode();
    unsigned char getKeyIndex();
    unsigned char getT2();
    unsigned char getKeyDataLength();
    QVector <QString> getKeyData();
    unsigned char getBufferInsertIndex();
    unsigned char getBufferExtractIndex();
    unsigned char getIsUniversal();
    unsigned int getPacketCount();
    unsigned char getRSSI();

private:
    QVector <unsigned char> data;

    unsigned char messageId;
    unsigned short receiverId;
    unsigned short pultId;
    unsigned short pultReceiverId;
    unsigned short batteryValue;
    QString keyCode;
    unsigned char keyIndex;
    unsigned char T2;
    unsigned char keyDataLength;
    QVector <QString> keyData;
    unsigned char bufferInsertIndex;
    unsigned char bufferExtractIndex;
    unsigned char isUniversal;
    unsigned int packetCount;
    unsigned char RSSI;
};

#endif // RECEIVERDATA_H
