/****************************************************************************
** Meta object code from reading C++ file 'navigation-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/navigation-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigation-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cms__controllers__NavigationController_t {
    QByteArrayData data[8];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cms__controllers__NavigationController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cms__controllers__NavigationController_t qt_meta_stringdata_cms__controllers__NavigationController = {
    {
QT_MOC_LITERAL(0, 0, 38), // "cms::controllers::NavigationC..."
QT_MOC_LITERAL(1, 39, 19), // "goCreatePatientView"
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 15), // "goDashboardView"
QT_MOC_LITERAL(4, 76, 17), // "goEditPatientView"
QT_MOC_LITERAL(5, 94, 21), // "cms::models::Patient*"
QT_MOC_LITERAL(6, 116, 7), // "patient"
QT_MOC_LITERAL(7, 124, 17) // "goFindPatientView"

    },
    "cms::controllers::NavigationController\0"
    "goCreatePatientView\0\0goDashboardView\0"
    "goEditPatientView\0cms::models::Patient*\0"
    "patient\0goFindPatientView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cms__controllers__NavigationController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       7,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void cms::controllers::NavigationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavigationController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goCreatePatientView(); break;
        case 1: _t->goDashboardView(); break;
        case 2: _t->goEditPatientView((*reinterpret_cast< cms::models::Patient*(*)>(_a[1]))); break;
        case 3: _t->goFindPatientView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavigationController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goCreatePatientView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavigationController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goDashboardView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavigationController::*)(cms::models::Patient * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goEditPatientView)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NavigationController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goFindPatientView)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cms::controllers::NavigationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cms__controllers__NavigationController.data,
    qt_meta_data_cms__controllers__NavigationController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cms::controllers::NavigationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cms::controllers::NavigationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cms__controllers__NavigationController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cms::controllers::NavigationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cms::controllers::NavigationController::goCreatePatientView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cms::controllers::NavigationController::goDashboardView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cms::controllers::NavigationController::goEditPatientView(cms::models::Patient * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cms::controllers::NavigationController::goFindPatientView()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
