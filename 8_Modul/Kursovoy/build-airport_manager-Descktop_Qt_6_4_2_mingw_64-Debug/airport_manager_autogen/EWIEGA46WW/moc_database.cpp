/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../airport_manager/database.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    uint offsetsAndSizes[58];
    char stringdata0[9];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[27];
    char stringdata5[16];
    char stringdata6[14];
    char stringdata7[14];
    char stringdata8[25];
    char stringdata9[22];
    char stringdata10[10];
    char stringdata11[4];
    char stringdata12[8];
    char stringdata13[35];
    char stringdata14[34];
    char stringdata15[12];
    char stringdata16[34];
    char stringdata17[32];
    char stringdata18[10];
    char stringdata19[12];
    char stringdata20[7];
    char stringdata21[7];
    char stringdata22[23];
    char stringdata23[7];
    char stringdata24[12];
    char stringdata25[13];
    char stringdata26[18];
    char stringdata27[15];
    char stringdata28[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DataBase_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DataBase_t qt_meta_stringdata_DataBase = {
    {
        QT_MOC_LITERAL(0, 8),  // "DataBase"
        QT_MOC_LITERAL(9, 12),  // "sig_sendData"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 4),  // "data"
        QT_MOC_LITERAL(28, 26),  // "sig_SendDataFromDBQueryMod"
        QT_MOC_LITERAL(55, 15),  // "QSqlQueryModel*"
        QT_MOC_LITERAL(71, 13),  // "tableQueryMod"
        QT_MOC_LITERAL(85, 13),  // "numberRequest"
        QT_MOC_LITERAL(99, 24),  // "sig_SendStatusConnection"
        QT_MOC_LITERAL(124, 21),  // "sig_SendStatusRequest"
        QT_MOC_LITERAL(146, 9),  // "QSqlError"
        QT_MOC_LITERAL(156, 3),  // "err"
        QT_MOC_LITERAL(160, 7),  // "request"
        QT_MOC_LITERAL(168, 34),  // "sig_SendDataFromDBQueryForCom..."
        QT_MOC_LITERAL(203, 33),  // "QList<std::pair<QString,QStri..."
        QT_MOC_LITERAL(237, 11),  // "airportList"
        QT_MOC_LITERAL(249, 33),  // "sig_SendDataFromDBQueryForGra..."
        QT_MOC_LITERAL(283, 31),  // "QList<std::pair<QDateTime,int>>"
        QT_MOC_LITERAL(315, 9),  // "statistic"
        QT_MOC_LITERAL(325, 11),  // "AddDataBase"
        QT_MOC_LITERAL(337, 6),  // "driver"
        QT_MOC_LITERAL(344, 6),  // "nameDB"
        QT_MOC_LITERAL(351, 22),  // "DisconnectFromDataBase"
        QT_MOC_LITERAL(374, 6),  // "nameDb"
        QT_MOC_LITERAL(381, 11),  // "RequestToDB"
        QT_MOC_LITERAL(393, 12),  // "GetLastError"
        QT_MOC_LITERAL(406, 17),  // "ConnectToDataBase"
        QT_MOC_LITERAL(424, 14),  // "dataForConnect"
        QT_MOC_LITERAL(439, 16)   // "ReadAnswerFromDB"
    },
    "DataBase",
    "sig_sendData",
    "",
    "data",
    "sig_SendDataFromDBQueryMod",
    "QSqlQueryModel*",
    "tableQueryMod",
    "numberRequest",
    "sig_SendStatusConnection",
    "sig_SendStatusRequest",
    "QSqlError",
    "err",
    "request",
    "sig_SendDataFromDBQueryForComboBox",
    "QList<std::pair<QString,QString>>",
    "airportList",
    "sig_SendDataFromDBQueryForGraphic",
    "QList<std::pair<QDateTime,int>>",
    "statistic",
    "AddDataBase",
    "driver",
    "nameDB",
    "DisconnectFromDataBase",
    "nameDb",
    "RequestToDB",
    "GetLastError",
    "ConnectToDataBase",
    "dataForConnect",
    "ReadAnswerFromDB"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DataBase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       4,    2,  101,    2, 0x06,    3 /* Public */,
       8,    1,  106,    2, 0x06,    6 /* Public */,
       9,    3,  109,    2, 0x06,    8 /* Public */,
      13,    2,  116,    2, 0x06,   12 /* Public */,
      16,    2,  121,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    2,  126,    2, 0x0a,   18 /* Public */,
      19,    1,  131,    2, 0x2a,   21 /* Public | MethodCloned */,
      22,    1,  134,    2, 0x0a,   23 /* Public */,
      22,    0,  137,    2, 0x2a,   25 /* Public | MethodCloned */,
      24,    2,  138,    2, 0x0a,   26 /* Public */,
      25,    0,  143,    2, 0x0a,   29 /* Public */,
      26,    1,  144,    2, 0x0a,   30 /* Public */,
      28,    2,  147,    2, 0x0a,   32 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QStringList, QMetaType::Int,   11,   12,    7,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int,   15,    7,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Int,   18,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,   12,    7,
    0x80000000 | 10,
    QMetaType::Void, QMetaType::QStringList,   27,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,   12,    7,

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
        // method 'sig_sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'sig_SendDataFromDBQueryMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_SendStatusConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_SendStatusRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_SendDataFromDBQueryForComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPair<QString,QString>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_SendDataFromDBQueryForGraphic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPair<QDateTime,int>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'AddDataBase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'AddDataBase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DisconnectFromDataBase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DisconnectFromDataBase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RequestToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'GetLastError'
        QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>,
        // method 'ConnectToDataBase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'ReadAnswerFromDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void DataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_sendData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 1: _t->sig_SendDataFromDBQueryMod((*reinterpret_cast< std::add_pointer_t<QSqlQueryModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->sig_SendStatusConnection((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->sig_SendStatusRequest((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->sig_SendDataFromDBQueryForComboBox((*reinterpret_cast< std::add_pointer_t<QList<std::pair<QString,QString>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->sig_SendDataFromDBQueryForGraphic((*reinterpret_cast< std::add_pointer_t<QList<std::pair<QDateTime,int>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->AddDataBase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->AddDataBase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->DisconnectFromDataBase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->DisconnectFromDataBase(); break;
        case 10: _t->RequestToDB((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: { QSqlError _r = _t->GetLastError();
            if (_a[0]) *reinterpret_cast< QSqlError*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->ConnectToDataBase((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 13: _t->ReadAnswerFromDB((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataBase::*)(QVector<QString> );
            if (_t _q_method = &DataBase::sig_sendData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(QSqlQueryModel * , int );
            if (_t _q_method = &DataBase::sig_SendDataFromDBQueryMod; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(bool );
            if (_t _q_method = &DataBase::sig_SendStatusConnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(QSqlError , QVector<QString> , int );
            if (_t _q_method = &DataBase::sig_SendStatusRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(QList<QPair<QString,QString>> , int );
            if (_t _q_method = &DataBase::sig_SendDataFromDBQueryForComboBox; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataBase::*)(QList<QPair<QDateTime,int>> , int );
            if (_t _q_method = &DataBase::sig_SendDataFromDBQueryForGraphic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DataBase::sig_sendData(QVector<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataBase::sig_SendDataFromDBQueryMod(QSqlQueryModel * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBase::sig_SendStatusConnection(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataBase::sig_SendStatusRequest(QSqlError _t1, QVector<QString> _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataBase::sig_SendDataFromDBQueryForComboBox(QList<QPair<QString,QString>> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataBase::sig_SendDataFromDBQueryForGraphic(QList<QPair<QDateTime,int>> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
