#include "hidnotfoundexception.h"

void HidNotFoundException::raise() const
{
    throw *this;
}

HidNotFoundException *HidNotFoundException::clone() const
{
    return new HidNotFoundException(*this);
}
