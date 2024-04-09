/****************************************************************************
** Meta object code from reading C++ file 'tratining_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/Tratining/Form/tratining_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tratining_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tratining_Form_t {
    QByteArrayData data[13];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tratining_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tratining_Form_t qt_meta_stringdata_Tratining_Form = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Tratining_Form"
QT_MOC_LITERAL(1, 15, 18), // "sl_selectDirection"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "sl_currentEKG"
QT_MOC_LITERAL(4, 49, 13), // "sl_currentEMG"
QT_MOC_LITERAL(5, 63, 13), // "sl_currentEEG"
QT_MOC_LITERAL(6, 77, 19), // "sl_curentDiogramEKG"
QT_MOC_LITERAL(7, 97, 14), // "ListData::Mode"
QT_MOC_LITERAL(8, 112, 4), // "mode"
QT_MOC_LITERAL(9, 117, 13), // "ListData::Vid"
QT_MOC_LITERAL(10, 131, 3), // "vid"
QT_MOC_LITERAL(11, 135, 19), // "sl_curentDiogramEMG"
QT_MOC_LITERAL(12, 155, 19) // "sl_curentDiogramEEG"

    },
    "Tratining_Form\0sl_selectDirection\0\0"
    "sl_currentEKG\0sl_currentEMG\0sl_currentEEG\0"
    "sl_curentDiogramEKG\0ListData::Mode\0"
    "mode\0ListData::Vid\0vid\0sl_curentDiogramEMG\0"
    "sl_curentDiogramEEG"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tratining_Form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    2,   53,    2, 0x0a /* Public */,
      11,    1,   58,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void Tratining_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tratining_Form *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sl_selectDirection(); break;
        case 1: _t->sl_currentEKG(); break;
        case 2: _t->sl_currentEMG(); break;
        case 3: _t->sl_currentEEG(); break;
        case 4: _t->sl_curentDiogramEKG((*reinterpret_cast< ListData::Mode(*)>(_a[1])),(*reinterpret_cast< ListData::Vid(*)>(_a[2]))); break;
        case 5: _t->sl_curentDiogramEMG((*reinterpret_cast< ListData::Vid(*)>(_a[1]))); break;
        case 6: _t->sl_curentDiogramEEG((*reinterpret_cast< ListData::Vid(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tratining_Form::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Tratining_Form.data,
    qt_meta_data_Tratining_Form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tratining_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tratining_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tratining_Form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tratining_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
