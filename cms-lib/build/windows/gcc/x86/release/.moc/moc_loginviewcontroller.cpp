/****************************************************************************
** Meta object code from reading C++ file 'loginviewcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/loginviewcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginviewcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cms__controllers__LoginViewController_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cms__controllers__LoginViewController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cms__controllers__LoginViewController_t qt_meta_stringdata_cms__controllers__LoginViewController = {
    {
QT_MOC_LITERAL(0, 0, 37), // "cms::controllers::LoginViewCo..."
QT_MOC_LITERAL(1, 38, 19), // "userLoginSuccessful"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 20), // "adminLoginSuccessful"
QT_MOC_LITERAL(4, 80, 11), // "loginFailed"
QT_MOC_LITERAL(5, 92, 18), // "loginButtonClicked"
QT_MOC_LITERAL(6, 111, 4), // "user"
QT_MOC_LITERAL(7, 116, 3) // "pwd"

    },
    "cms::controllers::LoginViewController\0"
    "userLoginSuccessful\0\0adminLoginSuccessful\0"
    "loginFailed\0loginButtonClicked\0user\0"
    "pwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cms__controllers__LoginViewController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void cms::controllers::LoginViewController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginViewController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userLoginSuccessful(); break;
        case 1: _t->adminLoginSuccessful(); break;
        case 2: _t->loginFailed(); break;
        case 3: _t->loginButtonClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginViewController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginViewController::userLoginSuccessful)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginViewController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginViewController::adminLoginSuccessful)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LoginViewController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginViewController::loginFailed)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cms::controllers::LoginViewController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_cms__controllers__LoginViewController.data,
    qt_meta_data_cms__controllers__LoginViewController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cms::controllers::LoginViewController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cms::controllers::LoginViewController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cms__controllers__LoginViewController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cms::controllers::LoginViewController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void cms::controllers::LoginViewController::userLoginSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cms::controllers::LoginViewController::adminLoginSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cms::controllers::LoginViewController::loginFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
