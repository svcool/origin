/****************************************************************************
** Meta object code from reading C++ file 'dbdata.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

<<<<<<< HEAD:8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/08_DataBaseLect_autogen/EWIEGA46WW/moc_dbdata.cpp
#include "../../../../dbdata.h"
=======
#include <memory>
#include "../../../L8_SQL/dbdata.h"
>>>>>>> 1:8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/08_PreDataBase_autogen/EWIEGA46WW/moc_dbdata.cpp
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
<<<<<<< HEAD:8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/08_DataBaseLect_autogen/EWIEGA46WW/moc_dbdata.cpp

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDbDataENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDbDataENDCLASS = QtMocHelpers::stringData(
=======
struct qt_meta_stringdata_DbData_t {
    uint offsetsAndSizes[10];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DbData_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DbData_t qt_meta_stringdata_DbData = {
    {
        QT_MOC_LITERAL(0, 6),  // "DbData"
        QT_MOC_LITERAL(7, 12),  // "sig_sendData"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 6),  // "dbData"
        QT_MOC_LITERAL(28, 18)   // "on_bb_Box_accepted"
    },
>>>>>>> 1:8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/08_PreDataBase_autogen/EWIEGA46WW/moc_dbdata.cpp
    "DbData",
    "sig_sendData",
    "",
    "dbData",
<<<<<<< HEAD:8_Modul/08_SQL/08_DataBaseLect/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/08_DataBaseLect_autogen/EWIEGA46WW/moc_dbdata.cpp
    "on_buttonBox_accepted"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
=======
    "on_bb_Box_accepted"
};
#undef QT_MOC_LITERAL
>>>>>>> 1:8_Modul/build-L8_SQL-Descktop_Qt_6_4_2_mingw_64-Debug/08_PreDataBase_autogen/EWIEGA46WW/moc_dbdata.cpp
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDbDataENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   29,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DbData::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSDbDataENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDbDataENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDbDataENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DbData, std::true_type>,
        // method 'sig_sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'on_bb_Box_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DbData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DbData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_sendData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 1: _t->on_bb_Box_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DbData::*)(QVector<QString> );
            if (_t _q_method = &DbData::sig_sendData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *DbData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDbDataENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DbData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DbData::sig_sendData(QVector<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
