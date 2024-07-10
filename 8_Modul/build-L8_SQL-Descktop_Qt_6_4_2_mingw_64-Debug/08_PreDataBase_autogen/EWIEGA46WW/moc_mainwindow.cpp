/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../L8_SQL/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[42];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[25];
    char stringdata5[16];
    char stringdata6[14];
    char stringdata7[25];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[12];
    char stringdata11[28];
    char stringdata12[7];
    char stringdata13[25];
    char stringdata14[10];
    char stringdata15[4];
    char stringdata16[13];
    char stringdata17[25];
    char stringdata18[25];
    char stringdata19[22];
    char stringdata20[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "sig_RequestToDb"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 7),  // "request"
        QT_MOC_LITERAL(36, 24),  // "ScreenDataFromDBTableMod"
        QT_MOC_LITERAL(61, 15),  // "QSqlTableModel*"
        QT_MOC_LITERAL(77, 13),  // "tableTableMod"
        QT_MOC_LITERAL(91, 24),  // "ScreenDataFromDBQueryMod"
        QT_MOC_LITERAL(116, 15),  // "QSqlQueryModel*"
        QT_MOC_LITERAL(132, 13),  // "tableQueryMod"
        QT_MOC_LITERAL(146, 11),  // "typeRequest"
        QT_MOC_LITERAL(158, 27),  // "ReceiveStatusConnectionToDB"
        QT_MOC_LITERAL(186, 6),  // "status"
        QT_MOC_LITERAL(193, 24),  // "ReceiveStatusRequestToDB"
        QT_MOC_LITERAL(218, 9),  // "QSqlError"
        QT_MOC_LITERAL(228, 3),  // "err"
        QT_MOC_LITERAL(232, 12),  // "requestIndex"
        QT_MOC_LITERAL(245, 24),  // "on_act_addData_triggered"
        QT_MOC_LITERAL(270, 24),  // "on_act_connect_triggered"
        QT_MOC_LITERAL(295, 21),  // "on_pb_request_clicked"
        QT_MOC_LITERAL(317, 19)   // "on_pb_clear_clicked"
    },
    "MainWindow",
    "sig_RequestToDb",
    "",
    "request",
    "ScreenDataFromDBTableMod",
    "QSqlTableModel*",
    "tableTableMod",
    "ScreenDataFromDBQueryMod",
    "QSqlQueryModel*",
    "tableQueryMod",
    "typeRequest",
    "ReceiveStatusConnectionToDB",
    "status",
    "ReceiveStatusRequestToDB",
    "QSqlError",
    "err",
    "requestIndex",
    "on_act_addData_triggered",
    "on_act_connect_triggered",
    "on_pb_request_clicked",
    "on_pb_clear_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   71,    2, 0x0a,    3 /* Public */,
       7,    2,   74,    2, 0x0a,    5 /* Public */,
      11,    1,   79,    2, 0x0a,    8 /* Public */,
      13,    2,   82,    2, 0x0a,   10 /* Public */,
      17,    0,   87,    2, 0x08,   13 /* Private */,
      18,    0,   88,    2, 0x08,   14 /* Private */,
      19,    0,   89,    2, 0x08,   15 /* Private */,
      20,    0,   90,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::UInt,    9,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::UInt,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'sig_RequestToDb'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ScreenDataFromDBTableMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlTableModel *, std::false_type>,
        // method 'ScreenDataFromDBQueryMod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint32, std::false_type>,
        // method 'ReceiveStatusConnectionToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ReceiveStatusRequestToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlError, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint32, std::false_type>,
        // method 'on_act_addData_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_act_connect_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_request_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_RequestToDb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->ScreenDataFromDBTableMod((*reinterpret_cast< std::add_pointer_t<QSqlTableModel*>>(_a[1]))); break;
        case 2: _t->ScreenDataFromDBQueryMod((*reinterpret_cast< std::add_pointer_t<QSqlQueryModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint32>>(_a[2]))); break;
        case 3: _t->ReceiveStatusConnectionToDB((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->ReceiveStatusRequestToDB((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint32>>(_a[2]))); break;
        case 5: _t->on_act_addData_triggered(); break;
        case 6: _t->on_act_connect_triggered(); break;
        case 7: _t->on_pb_request_clicked(); break;
        case 8: _t->on_pb_clear_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlTableModel* >(); break;
            }
            break;
        case 2:
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
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::sig_RequestToDb; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_RequestToDb(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
