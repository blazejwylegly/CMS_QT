#ifndef CMSLIB_GLOBAL_H
#define CMSLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CMSLIB_LIBRARY)
#  define CMSLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CMSLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CMSLIB_GLOBAL_H
