/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../08_DataBaseLect/database.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_DataBase_t {
    uint offsetsAndSizes[20];
    char stringdata0[9];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[8];
    char stringdata5[6];
    char stringdata6[25];
    char stringdata7[22];
    char stringdata8[10];
    char stringdata9[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DataBase_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DataBase_t qt_meta_stringdata_DataBase = {
    {
        QT_MOC_LITERAL(0, 8),  // "DataBase"
        QT_MOC_LITERAL(9, 18),  // "sig_SendDataFromDB"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 19),  // "const QTableWidget*"
        QT_MOC_LITERAL(49, 7),  // "tableWg"
        QT_MOC_LITERAL(57, 5),  // "typeR"
        QT_MOC_LITERAL(63, 24),  // "sig_SendStatusConnection"
        QT_MOC_LITERAL(88, 21),  // "sig_SendStatusRequest"
        QT_MOC_LITERAL(110, 9),  // "QSqlError"
        QT_MOC_LITERAL(120, 3)   // "err"
    },
    "DataBase",
    "sig_SendDataFromDB",
    "",
    "const QTableWidget*",
    "tableWg",
    "typeR",
    "sig_SendStatusConnection",
    "sig_SendStatusRequest",
    "QSqlError",
    "err"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DataBase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,
       6,    1,   37,    2, 0x06,    4 /* Public */,
       7,    1,   40,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject DataBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataBase.offsetsAndSizes,
    qt_meta_data_DataBase,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DataBase_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DataBase, std::true_type>,
        // method 'sig_SendDataFromDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTableWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_SendStatusConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_SendStatusRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>
    >,
    nullptr
} };

void DataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_SendDataFromDB((*reinterpret_cast< std::add_pointer_t<const QTableWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->sig_SendStatusConnection((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->sig_SendStatusRequest((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataBase::*)(const QTableWidget * , int );
            if (_t _q_method = &DataBase::sig_SendDataFromDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(bool );
            if (_t _q_method = &DataBase::sig_SendStatusConnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(QSqlError );
            if (_t _q_method = &DataBase::sig_SendStatusRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *DataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DataBase::sig_SendDataFromDB(const QTableWidget * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataBase::sig_SendStatusConnection(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBase::sig_SendStatusRequest(QSqlError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
