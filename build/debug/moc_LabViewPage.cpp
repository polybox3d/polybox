/****************************************************************************
** Meta object code from reading C++ file 'LabViewPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/LabViewPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LabViewPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LabViewPage_t {
    QByteArrayData data[16];
    char stringdata[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LabViewPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LabViewPage_t qt_meta_stringdata_LabViewPage = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 20),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 21),
QT_MOC_LITERAL(4, 56, 21),
QT_MOC_LITERAL(5, 78, 17),
QT_MOC_LITERAL(6, 96, 5),
QT_MOC_LITERAL(7, 102, 17),
QT_MOC_LITERAL(8, 120, 17),
QT_MOC_LITERAL(9, 138, 21),
QT_MOC_LITERAL(10, 160, 4),
QT_MOC_LITERAL(11, 165, 21),
QT_MOC_LITERAL(12, 187, 21),
QT_MOC_LITERAL(13, 209, 25),
QT_MOC_LITERAL(14, 235, 29),
QT_MOC_LITERAL(15, 265, 25)
    },
    "LabViewPage\0on_startVisu_clicked\0\0"
    "on_loadProfil_clicked\0on_saveProfil_clicked\0"
    "on_r_valueChanged\0value\0on_g_valueChanged\0"
    "on_b_valueChanged\0on_rSpin_valueChanged\0"
    "arg1\0on_gSpin_valueChanged\0"
    "on_bSpin_valueChanged\0on_intensite_valueChanged\0"
    "on_intensiteSpin_valueChanged\0"
    "on_startRecording_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabViewPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    0,   75,    2, 0x08,
       4,    0,   76,    2, 0x08,
       5,    1,   77,    2, 0x08,
       7,    1,   80,    2, 0x08,
       8,    1,   83,    2, 0x08,
       9,    1,   86,    2, 0x08,
      11,    1,   89,    2, 0x08,
      12,    1,   92,    2, 0x08,
      13,    1,   95,    2, 0x08,
      14,    1,   98,    2, 0x08,
      15,    0,  101,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void LabViewPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabViewPage *_t = static_cast<LabViewPage *>(_o);
        switch (_id) {
        case 0: _t->on_startVisu_clicked(); break;
        case 1: _t->on_loadProfil_clicked(); break;
        case 2: _t->on_saveProfil_clicked(); break;
        case 3: _t->on_r_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_g_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_b_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_rSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_gSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_bSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_intensite_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_intensiteSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_startRecording_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject LabViewPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LabViewPage.data,
      qt_meta_data_LabViewPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LabViewPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabViewPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LabViewPage.stringdata))
        return static_cast<void*>(const_cast< LabViewPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LabViewPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
