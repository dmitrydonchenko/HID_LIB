#include "receiverdata.h"
#include <stdio.h>
#include "bytebuffer.h"

ReceiverData::ReceiverData()
{

}

ReceiverData::ReceiverData(unsigned char *data)
{
   for(int i = 0; i < 64; i++)
   {
       this->data.append(data[i]);
   }
   ByteBuffer byteBuffer = ByteBuffer(data);
   messageId = byteBuffer.getUChar();
   receiverId = byteBuffer.getUShort();
   pultId = byteBuffer.getUShort();
   pultReceiverId = byteBuffer.getUShort();
   batteryValue = byteBuffer.getUShort();
   keyCode = byteBuffer.getUCharHex();
   keyIndex = byteBuffer.getUChar();
   T2 = byteBuffer.getUChar();
   keyDataLength = byteBuffer.getUChar();
   for(int i = 0; i < keyDataLength; i++)
   {
       keyData.append(byteBuffer.getUCharHex());
   }
   byteBuffer.setCurPos(byteBuffer.getCurPos() + 26 - keyDataLength);
   bufferInsertIndex = byteBuffer.getUChar();
   bufferExtractIndex = byteBuffer.getUChar();
   isUniversal = byteBuffer.getUChar();
   packetCount = byteBuffer.getUInt();
   RSSI = byteBuffer.getUChar();
}

unsigned short ReceiverData::getBatteryValue()
{
    return this->batteryValue;
}

unsigned char ReceiverData::getBufferExtractIndex()
{
    return this->bufferExtractIndex;
}

unsigned char ReceiverData::getBufferInsertIndex()
{
    return this->bufferInsertIndex;
}

QVector <unsigned char> ReceiverData::getData()
{
    return this->data;
}

unsigned char ReceiverData::getIsUniversal()
{
    return this->isUniversal;
}

QString ReceiverData::getKeyCode()
{
    return this->keyCode;
}

QVector<QString> ReceiverData::getKeyData()
{
    return this->keyData;
}

unsigned char ReceiverData::getKeyDataLength()
{
    return this->keyDataLength;
}

unsigned char ReceiverData::getKeyIndex()
{
    return this->keyIndex;
}

unsigned char ReceiverData::getMessageId()
{
    return this->messageId;
}

unsigned int ReceiverData::getPacketCount()
{
    return this->packetCount;
}

unsigned short ReceiverData::getPultId()
{
    return this->pultId;
}

unsigned short ReceiverData::getPultReceiverId()
{
    return this->pultReceiverId;
}

unsigned short ReceiverData::getReceiverId()
{
    return this->receiverId;
}

unsigned char ReceiverData::getRSSI()
{
    return this->RSSI;
}

unsigned char ReceiverData::getT2()
{
    return this->T2;
}
