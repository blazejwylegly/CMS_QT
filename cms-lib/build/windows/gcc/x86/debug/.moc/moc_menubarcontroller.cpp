/****************************************************************************
** Meta object code from reading C++ file 'menubarcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/menubarcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menubarcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cms__controllers__MenuBarController_t {
    QByteArrayData data[5];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cms__controllers__MenuBarController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cms__controllers__MenuBarController_t qt_meta_stringdata_cms__controllers__MenuBarController = {
    {
QT_MOC_LITERAL(0, 0, 35), // "cms::controllers::MenuBarCont..."
QT_MOC_LITERAL(1, 36, 15), // "goDashboardView"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 19), // "loadPatientsDisplay"
QT_MOC_LITERAL(4, 73, 19) // "loadPatientAddition"

    },
    "cms::controllers::MenuBarController\0"
    "goDashboardView\0\0loadPatientsDisplay\0"
    "loadPatientAddition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cms__controllers__MenuBarController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cms::controllers::MenuBarController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuBarController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goDashboardView(); break;
        case 1: _t->loadPatientsDisplay(); break;
        case 2: _t->loadPatientAddition(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuBarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBarController::goDashboardView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuBarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBarController::loadPatientsDisplay)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuBarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBarController::loadPatientAddition)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject cms::controllers::MenuBarController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cms__controllers__MenuBarController.data,
    qt_meta_data_cms__controllers__MenuBarController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cms::controllers::MenuBarController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cms::controllers::MenuBarController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cms__controllers__MenuBarController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cms::controllers::MenuBarController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void cms::controllers::MenuBarController::goDashboardView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cms::controllers::MenuBarController::loadPatientsDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cms::controllers::MenuBarController::loadPatientAddition()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
