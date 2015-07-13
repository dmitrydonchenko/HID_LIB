#ifndef HIDNOTFOUNDEXCEPTION_H
#define HIDNOTFOUNDEXCEPTION_H

#include "hidlib_global.h"
#include <exception>

class HIDLIBSHARED_EXPORT HidNotFoundException : public std::exception
{
public:
    void raise() const;
    HidNotFoundException *clone() const;
};

#endif // HIDNOTFOUNDEXCEPTION_H
