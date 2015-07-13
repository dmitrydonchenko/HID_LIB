#include "bytebuffer.h"
#include <QString>

ByteBuffer::ByteBuffer(unsigned char *bytes)
{
    this->bytes = bytes;
    curPos = 0;
}

int ByteBuffer::getCurPos()
{
    return curPos;
}

void ByteBuffer::setCurPos(int pos)
{
    curPos = pos;
}

int ByteBuffer::getLength()
{
    return length;
}

unsigned short ByteBuffer::getUShort()
{
    unsigned short res = (bytes[curPos]) | (bytes[curPos + 1] << 8);
    curPos += 2;
    return res;
}

unsigned int ByteBuffer::getUInt()
{
    unsigned int res = (uint) bytes[curPos + 3] << 24 |
                       (uint) bytes[curPos + 2] << 16 |
                       (uint) bytes[curPos + 1] << 8  |
                       (uint) bytes[curPos];
    curPos += 4;
    return res;
}

QString ByteBuffer::getUCharHex()
{
    const char hex[] = "0123456789ABCDEF";
    QString res = "";
    res.append(hex[bytes[curPos] >> 4]);
    res.append(hex[bytes[curPos] & 0xf]);
    curPos++;
    return res;
}

unsigned char ByteBuffer::getUChar()
{
    unsigned char res = bytes[curPos];
    curPos++;
    return res;
}


