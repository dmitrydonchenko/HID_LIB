#ifndef HIDNOTFOUNDEXCEPTION_H
#define HIDNOTFOUNDEXCEPTION_H

#include "hidlib_global.h"
#include <QException>

class HIDLIBSHARED_EXPORT HidNotFoundException : public QException
{
public:
    void raise() const;
    HidNotFoundException *clone() const;
};

#endif // HIDNOTFOUNDEXCEPTION_H
