/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../08_DataBaseLect/mainwindow.h"
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
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[17];
    char stringdata5[12];
    char stringdata6[5];
    char stringdata7[12];
    char stringdata8[28];
    char stringdata9[7];
    char stringdata10[25];
    char stringdata11[10];
    char stringdata12[4];
    char stringdata13[13];
    char stringdata14[25];
    char stringdata15[25];
    char stringdata16[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "sig_RequestToDb"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 7),  // "request"
        QT_MOC_LITERAL(36, 16),  // "ScreenDataFromDB"
        QT_MOC_LITERAL(53, 11),  // "QTableView*"
        QT_MOC_LITERAL(65, 4),  // "view"
        QT_MOC_LITERAL(70, 11),  // "typeRequest"
        QT_MOC_LITERAL(82, 27),  // "ReceiveStatusConnectionToDB"
        QT_MOC_LITERAL(110, 6),  // "status"
        QT_MOC_LITERAL(117, 24),  // "ReceiveStatusRequestToDB"
        QT_MOC_LITERAL(142, 9),  // "QSqlError"
        QT_MOC_LITERAL(152, 3),  // "err"
        QT_MOC_LITERAL(156, 12),  // "requestIndex"
        QT_MOC_LITERAL(169, 24),  // "on_act_addData_triggered"
        QT_MOC_LITERAL(194, 24),  // "on_act_connect_triggered"
        QT_MOC_LITERAL(219, 21)   // "on_pb_request_clicked"
    },
    "MainWindow",
    "sig_RequestToDb",
    "",
    "request",
    "ScreenDataFromDB",
    "QTableView*",
    "view",
    "typeRequest",
    "ReceiveStatusConnectionToDB",
    "status",
    "ReceiveStatusRequestToDB",
    "QSqlError",
    "err",
    "requestIndex",
    "on_act_addData_triggered",
    "on_act_connect_triggered",
    "on_pb_request_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   59,    2, 0x0a,    3 /* Public */,
       8,    1,   64,    2, 0x0a,    6 /* Public */,
      10,    2,   67,    2, 0x0a,    8 /* Public */,
      14,    0,   72,    2, 0x08,   11 /* Private */,
      15,    0,   73,    2, 0x08,   12 /* Private */,
      16,    0,   74,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::UInt,    6,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::UInt,   12,   13,
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
        // method 'ScreenDataFromDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableView *, std::false_type>,
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
        case 1: _t->ScreenDataFromDB((*reinterpret_cast< std::add_pointer_t<QTableView*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint32>>(_a[2]))); break;
        case 2: _t->ReceiveStatusConnectionToDB((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->ReceiveStatusRequestToDB((*reinterpret_cast< std::add_pointer_t<QSqlError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint32>>(_a[2]))); break;
        case 4: _t->on_act_addData_triggered(); break;
        case 5: _t->on_act_connect_triggered(); break;
        case 6: _t->on_pb_request_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
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
