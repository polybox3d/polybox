/****************************************************************************
** Meta object code from reading C++ file 'Led.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Led.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Led.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Led_t {
    QByteArrayData data[11];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Led_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Led_t qt_meta_stringdata_Led = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 9),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 3),
QT_MOC_LITERAL(4, 19, 2),
QT_MOC_LITERAL(5, 22, 6),
QT_MOC_LITERAL(6, 29, 12),
QT_MOC_LITERAL(7, 42, 9),
QT_MOC_LITERAL(8, 52, 7),
QT_MOC_LITERAL(9, 60, 1),
QT_MOC_LITERAL(10, 62, 1)
    },
    "Led\0updateLed\0\0off\0on\0toggle\0setActivated\0"
    "activated\0setSize\0w\0h\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Led[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    0,   47,    2, 0x0a,
       6,    1,   48,    2, 0x0a,
       8,    2,   51,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void Led::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Led *_t = static_cast<Led *>(_o);
        switch (_id) {
        case 0: _t->updateLed(); break;
        case 1: _t->off(); break;
        case 2: _t->on(); break;
        case 3: _t->toggle(); break;
        case 4: _t->setActivated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Led::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Led.data,
      qt_meta_data_Led,  qt_static_metacall, 0, 0}
};


const QMetaObject *Led::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Led::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Led.stringdata))
        return static_cast<void*>(const_cast< Led*>(this));
    return QLabel::qt_metacast(_clname);
}

int Led::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
