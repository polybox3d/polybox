/****************************************************************************
** Meta object code from reading C++ file 'CheckerModele.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CheckerModele.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CheckerModele.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CheckerModele_t {
    QByteArrayData data[7];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CheckerModele_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CheckerModele_t qt_meta_stringdata_CheckerModele = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 8),
QT_MOC_LITERAL(4, 41, 7),
QT_MOC_LITERAL(5, 49, 16),
QT_MOC_LITERAL(6, 66, 15)
    },
    "CheckerModele\0setContentWidget\0\0"
    "QWidget*\0content\0on_close_clicked\0"
    "on_help_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckerModele[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a,
       5,    0,   32,    2, 0x08,
       6,    0,   33,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CheckerModele::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CheckerModele *_t = static_cast<CheckerModele *>(_o);
        switch (_id) {
        case 0: _t->setContentWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->on_close_clicked(); break;
        case 2: _t->on_help_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject CheckerModele::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CheckerModele.data,
      qt_meta_data_CheckerModele,  qt_static_metacall, 0, 0}
};


const QMetaObject *CheckerModele::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckerModele::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckerModele.stringdata))
        return static_cast<void*>(const_cast< CheckerModele*>(this));
    return QDialog::qt_metacast(_clname);
}

int CheckerModele::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
