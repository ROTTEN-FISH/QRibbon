#ifndef AIV_GLOBAL_H
#define AIV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AIV_LIBRARY)
#  define AIV_EXPORT Q_DECL_EXPORT
#else
#  define AIV_EXPORT Q_DECL_IMPORT
#endif

#endif // AIV_GLOBAL_H
