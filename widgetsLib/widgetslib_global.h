#ifndef WIDGETSLIB_GLOBAL_H
#define WIDGETSLIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QWidget>

#if defined(WIDGETSLIB_LIBRARY)
#  define WIDGETSLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WIDGETSLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WIDGETSLIB_GLOBAL_H
