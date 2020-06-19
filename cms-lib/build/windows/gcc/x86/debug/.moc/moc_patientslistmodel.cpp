/****************************************************************************
** Meta object code from reading C++ file 'patientslistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../source/controllers/patientslistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientslistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cms__controllers__PatientsListModel_t {
    QByteArrayData data[13];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cms__controllers__PatientsListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cms__controllers__PatientsListModel_t qt_meta_stringdata_cms__controllers__PatientsListModel = {
    {
QT_MOC_LITERAL(0, 0, 35), // "cms::controllers::PatientsLis..."
QT_MOC_LITERAL(1, 36, 11), // "beginInsert"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 9), // "endInsert"
QT_MOC_LITERAL(4, 59, 12), // "beginRemoval"
QT_MOC_LITERAL(5, 72, 10), // "endRemoval"
QT_MOC_LITERAL(6, 83, 12), // "nothingFound"
QT_MOC_LITERAL(7, 96, 13), // "deletePatient"
QT_MOC_LITERAL(8, 110, 11), // "editPatient"
QT_MOC_LITERAL(9, 122, 6), // "update"
QT_MOC_LITERAL(10, 129, 5), // "clear"
QT_MOC_LITERAL(11, 135, 8), // "doSearch"
QT_MOC_LITERAL(12, 144, 10) // "searchText"

    },
    "cms::controllers::PatientsListModel\0"
    "beginInsert\0\0endInsert\0beginRemoval\0"
    "endRemoval\0nothingFound\0deletePatient\0"
    "editPatient\0update\0clear\0doSearch\0"
    "searchText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cms__controllers__PatientsListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x02 /* Public */,
       8,    0,   70,    2, 0x02 /* Public */,
       9,    0,   71,    2, 0x02 /* Public */,
      10,    0,   72,    2, 0x02 /* Public */,
      11,    1,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void cms::controllers::PatientsListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PatientsListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beginInsert(); break;
        case 1: _t->endInsert(); break;
        case 2: _t->beginRemoval(); break;
        case 3: _t->endRemoval(); break;
        case 4: _t->nothingFound(); break;
        case 5: _t->deletePatient(); break;
        case 6: _t->editPatient(); break;
        case 7: _t->update(); break;
        case 8: _t->clear(); break;
        case 9: _t->doSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PatientsListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientsListModel::beginInsert)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PatientsListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientsListModel::endInsert)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PatientsListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientsListModel::beginRemoval)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PatientsListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientsListModel::endRemoval)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PatientsListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientsListModel::nothingFound)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cms::controllers::PatientsListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_cms__controllers__PatientsListModel.data,
    qt_meta_data_cms__controllers__PatientsListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cms::controllers::PatientsListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cms::controllers::PatientsListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cms__controllers__PatientsListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int cms::controllers::PatientsListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void cms::controllers::PatientsListModel::beginInsert()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cms::controllers::PatientsListModel::endInsert()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cms::controllers::PatientsListModel::beginRemoval()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void cms::controllers::PatientsListModel::endRemoval()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void cms::controllers::PatientsListModel::nothingFound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
