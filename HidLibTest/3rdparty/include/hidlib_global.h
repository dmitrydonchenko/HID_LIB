#ifndef HIDLIB_GLOBAL_H
#define HIDLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HIDLIB_LIBRARY)
#  define HIDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HIDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HIDLIB_GLOBAL_H
