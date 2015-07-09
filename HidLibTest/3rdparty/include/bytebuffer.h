#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <QString>

class ByteBuffer
{
public:
    ByteBuffer(unsigned char *bytes);

    int getCurPos();
    void setCurPos(int pos);
    int getLength();

    unsigned short getUShort();
    unsigned int getUInt();
    QString getUCharHex();
    unsigned char getUChar();

private:
    unsigned char *bytes;
    int curPos;
    int length;
};

#endif // BYTEBUFFER_H
