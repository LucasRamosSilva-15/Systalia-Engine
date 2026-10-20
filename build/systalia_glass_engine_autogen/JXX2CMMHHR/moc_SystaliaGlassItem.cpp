/****************************************************************************
** Meta object code from reading C++ file 'SystaliaGlassItem.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/render/SystaliaGlassItem.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SystaliaGlassItem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.2. It"
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
struct qt_meta_tag_ZN17SystaliaGlassItemE_t {};
} // unnamed namespace

template <> constexpr inline auto SystaliaGlassItem::qt_create_metaobjectdata<qt_meta_tag_ZN17SystaliaGlassItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SystaliaGlassItem",
        "QML.Element",
        "auto",
        "backdropSourceChanged",
        "",
        "themeModeChanged",
        "blurRadiusChanged",
        "blurIterationsChanged",
        "causticIntensityChanged",
        "cornerRadiusChanged",
        "accentColorChanged",
        "timeChanged",
        "setBackdropSource",
        "QQuickItem*",
        "source",
        "setThemeMode",
        "value",
        "setBlurRadius",
        "setBlurIterations",
        "setCausticIntensity",
        "setCornerRadius",
        "setAccentColor",
        "QColor",
        "setTime",
        "backdropSource",
        "themeMode",
        "blurRadius",
        "blurIterations",
        "causticIntensity",
        "cornerRadius",
        "accentColor",
        "time"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'backdropSourceChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'themeModeChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blurRadiusChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blurIterationsChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'causticIntensityChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cornerRadiusChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'accentColorChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setBackdropSource'
        QtMocHelpers::SlotData<void(QQuickItem *)>(12, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot 'setThemeMode'
        QtMocHelpers::SlotData<void(int)>(15, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'setBlurRadius'
        QtMocHelpers::SlotData<void(qreal)>(17, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 16 },
        }}),
        // Slot 'setBlurIterations'
        QtMocHelpers::SlotData<void(int)>(18, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'setCausticIntensity'
        QtMocHelpers::SlotData<void(qreal)>(19, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 16 },
        }}),
        // Slot 'setCornerRadius'
        QtMocHelpers::SlotData<void(qreal)>(20, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 16 },
        }}),
        // Slot 'setAccentColor'
        QtMocHelpers::SlotData<void(const QColor &)>(21, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 16 },
        }}),
        // Slot 'setTime'
        QtMocHelpers::SlotData<void(qreal)>(23, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'backdropSource'
        QtMocHelpers::PropertyData<QQuickItem*>(24, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'themeMode'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'blurRadius'
        QtMocHelpers::PropertyData<qreal>(26, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'blurIterations'
        QtMocHelpers::PropertyData<int>(27, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'causticIntensity'
        QtMocHelpers::PropertyData<qreal>(28, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'cornerRadius'
        QtMocHelpers::PropertyData<qreal>(29, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'accentColor'
        QtMocHelpers::PropertyData<QColor>(30, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 6),
        // property 'time'
        QtMocHelpers::PropertyData<qreal>(31, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<SystaliaGlassItem, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject SystaliaGlassItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17SystaliaGlassItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17SystaliaGlassItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17SystaliaGlassItemE_t>.metaTypes,
    nullptr
} };

void SystaliaGlassItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SystaliaGlassItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->backdropSourceChanged(); break;
        case 1: _t->themeModeChanged(); break;
        case 2: _t->blurRadiusChanged(); break;
        case 3: _t->blurIterationsChanged(); break;
        case 4: _t->causticIntensityChanged(); break;
        case 5: _t->cornerRadiusChanged(); break;
        case 6: _t->accentColorChanged(); break;
        case 7: _t->timeChanged(); break;
        case 8: _t->setBackdropSource((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1]))); break;
        case 9: _t->setThemeMode((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setBlurRadius((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 11: _t->setBlurIterations((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setCausticIntensity((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 13: _t->setCornerRadius((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 14: _t->setAccentColor((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1]))); break;
        case 15: _t->setTime((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::backdropSourceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::themeModeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::blurRadiusChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::blurIterationsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::causticIntensityChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::cornerRadiusChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::accentColorChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystaliaGlassItem::*)()>(_a, &SystaliaGlassItem::timeChanged, 7))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QQuickItem**>(_v) = _t->backdropSource(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->themeMode(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->blurRadius(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->blurIterations(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->causticIntensity(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->cornerRadius(); break;
        case 6: *reinterpret_cast<QColor*>(_v) = _t->accentColor(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->time(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackdropSource(*reinterpret_cast<QQuickItem**>(_v)); break;
        case 1: _t->setThemeMode(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setBlurRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setBlurIterations(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setCausticIntensity(*reinterpret_cast<qreal*>(_v)); break;
        case 5: _t->setCornerRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 6: _t->setAccentColor(*reinterpret_cast<QColor*>(_v)); break;
        case 7: _t->setTime(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *SystaliaGlassItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystaliaGlassItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17SystaliaGlassItemE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int SystaliaGlassItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SystaliaGlassItem::backdropSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SystaliaGlassItem::themeModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SystaliaGlassItem::blurRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SystaliaGlassItem::blurIterationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SystaliaGlassItem::causticIntensityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SystaliaGlassItem::cornerRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SystaliaGlassItem::accentColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SystaliaGlassItem::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
