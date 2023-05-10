/****************************************************************************
** Meta object code from reading C++ file 'scrollbar_c.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/cpp_code/custom_qml_elements/scrollbar_c.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrollbar_c.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSScrollBar_CENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSScrollBar_CENDCLASS = QtMocHelpers::stringData(
    "ScrollBar_C",
    "QML.Element",
    "auto",
    "backgroundColorChanged",
    "",
    "handleColorChanged",
    "foregroundColorChanged",
    "backgroundColor",
    "handleColor",
    "foregroundColor"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSScrollBar_CENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[23];
    char stringdata4[1];
    char stringdata5[19];
    char stringdata6[23];
    char stringdata7[16];
    char stringdata8[12];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSScrollBar_CENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSScrollBar_CENDCLASS_t qt_meta_stringdata_CLASSScrollBar_CENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "ScrollBar_C"
        QT_MOC_LITERAL(12, 11),  // "QML.Element"
        QT_MOC_LITERAL(24, 4),  // "auto"
        QT_MOC_LITERAL(29, 22),  // "backgroundColorChanged"
        QT_MOC_LITERAL(52, 0),  // ""
        QT_MOC_LITERAL(53, 18),  // "handleColorChanged"
        QT_MOC_LITERAL(72, 22),  // "foregroundColorChanged"
        QT_MOC_LITERAL(95, 15),  // "backgroundColor"
        QT_MOC_LITERAL(111, 11),  // "handleColor"
        QT_MOC_LITERAL(123, 15)   // "foregroundColor"
    },
    "ScrollBar_C",
    "QML.Element",
    "auto",
    "backgroundColorChanged",
    "",
    "handleColorChanged",
    "foregroundColorChanged",
    "backgroundColor",
    "handleColor",
    "foregroundColor"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSScrollBar_CENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       3,   37, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   34,    4, 0x06,    4 /* Public */,
       5,    0,   35,    4, 0x06,    5 /* Public */,
       6,    0,   36,    4, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QColor, 0x00015103, uint(0), 0,
       8, QMetaType::QColor, 0x00015103, uint(1), 0,
       9, QMetaType::QColor, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ScrollBar_C::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSScrollBar_CENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSScrollBar_CENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'backgroundColor'
        QColor,
        // property 'handleColor'
        QColor,
        // property 'foregroundColor'
        QColor,
        // Q_OBJECT / Q_GADGET
        ScrollBar_C,
        // method 'backgroundColorChanged'
        void,
        // method 'handleColorChanged'
        void,
        // method 'foregroundColorChanged'
        void
    >,
    nullptr
} };

void ScrollBar_C::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScrollBar_C *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backgroundColorChanged(); break;
        case 1: _t->handleColorChanged(); break;
        case 2: _t->foregroundColorChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScrollBar_C::*)();
            if (_t _q_method = &ScrollBar_C::backgroundColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScrollBar_C::*)();
            if (_t _q_method = &ScrollBar_C::handleColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScrollBar_C::*)();
            if (_t _q_method = &ScrollBar_C::foregroundColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScrollBar_C *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getHandleColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getForegroundColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ScrollBar_C *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setHandleColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *ScrollBar_C::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrollBar_C::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSScrollBar_CENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int ScrollBar_C::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScrollBar_C::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScrollBar_C::handleColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ScrollBar_C::foregroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
