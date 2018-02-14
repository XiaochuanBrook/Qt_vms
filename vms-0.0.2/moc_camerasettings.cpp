/****************************************************************************
** Meta object code from reading C++ file 'camerasettings.h'
**
** Created: Thu May 21 20:18:43 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "camerasettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camerasettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraSettings[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      33,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraSettings[] = {
    "CameraSettings\0\0setStoragePath()\0"
    "CMDchange()\0"
};

const QMetaObject CameraSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraSettings,
      qt_meta_data_CameraSettings, 0 }
};

const QMetaObject *CameraSettings::metaObject() const
{
    return &staticMetaObject;
}

void *CameraSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraSettings))
	return static_cast<void*>(const_cast< CameraSettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int CameraSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setStoragePath(); break;
        case 1: CMDchange(); break;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
