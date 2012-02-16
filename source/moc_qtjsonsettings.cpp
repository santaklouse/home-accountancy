/****************************************************************************
** Meta object code from reading C++ file 'qtjsonsettings.h'
**
** Created: Wed Feb 15 18:52:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "3rd_party/qtjsonsettings/qtjsonsettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtjsonsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtJsonSettings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QtJsonSettings[] = {
    "QtJsonSettings\0"
};

const QMetaObject QtJsonSettings::staticMetaObject = {
    { &QSettings::staticMetaObject, qt_meta_stringdata_QtJsonSettings,
      qt_meta_data_QtJsonSettings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtJsonSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtJsonSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtJsonSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtJsonSettings))
        return static_cast<void*>(const_cast< QtJsonSettings*>(this));
    return QSettings::qt_metacast(_clname);
}

int QtJsonSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSettings::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
