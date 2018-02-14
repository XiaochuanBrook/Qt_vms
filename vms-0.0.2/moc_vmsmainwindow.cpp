/****************************************************************************
** Meta object code from reading C++ file 'vmsmainwindow.h'
**
** Created: Thu May 21 18:17:21 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vmsmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vmsmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VMSMainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      42,   14,   14,   14, 0x08,
      70,   14,   14,   14, 0x08,
     100,   14,   14,   14, 0x08,
     132,   14,   14,   14, 0x08,
     163,  161,   14,   14, 0x08,
     183,  180,   14,   14, 0x08,
     197,  161,   14,   14, 0x08,
     215,   14,   14,   14, 0x08,
     229,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VMSMainWindow[] = {
    "VMSMainWindow\0\0on_action_Exit_triggered()\0"
    "on_action_About_triggered()\0"
    "on_action_Options_triggered()\0"
    "on_actionTake_Photo_triggered()\0"
    "on_action_Delete_triggered()\0i\0"
    "selectThumb(int)\0th\0delThumb(int)\0"
    "thumbClicked(int)\0toggleVideo()\0"
    "takePhoto()\0"
};

const QMetaObject VMSMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VMSMainWindow,
      qt_meta_data_VMSMainWindow, 0 }
};

const QMetaObject *VMSMainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *VMSMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VMSMainWindow))
	return static_cast<void*>(const_cast< VMSMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VMSMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_action_Exit_triggered(); break;
        case 1: on_action_About_triggered(); break;
        case 2: on_action_Options_triggered(); break;
        case 3: on_actionTake_Photo_triggered(); break;
        case 4: on_action_Delete_triggered(); break;
        case 5: selectThumb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: delThumb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: thumbClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: toggleVideo(); break;
        case 9: takePhoto(); break;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
