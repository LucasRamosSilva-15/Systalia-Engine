/****************************************************************************
** Meta object code from reading C++ file 'EngineConfig.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/EngineConfig.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EngineConfig.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12EngineConfigE_t {};
} // unnamed namespace

template <> constexpr inline auto EngineConfig::qt_create_metaobjectdata<qt_meta_tag_ZN12EngineConfigE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EngineConfig",
        "QML.Element",
        "auto",
        "themeModeChanged",
        "",
        "blurRadiusChanged",
        "blurIterationsChanged",
        "causticGainChanged",
        "cornerRadiusChanged",
        "accentColorChanged",
        "setThemeMode",
        "ThemeMode",
        "value",
        "setBlurRadius",
        "setBlurIterations",
        "setCausticGain",
        "setCornerRadius",
        "setAccentColor",
        "QColor",
        "themeMode",
        "blurRadius",
        "blurIterations",
        "causticGain",
        "cornerRadius",
        "accentColor",
        "Valo",
        "Soar"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'themeModeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blurRadiusChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blurIterationsChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'causticGainChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cornerRadiusChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'accentColorChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setThemeMode'
        QtMocHelpers::SlotData<void(enum ThemeMode)>(10, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'setBlurRadius'
        QtMocHelpers::SlotData<void(qreal)>(13, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 12 },
        }}),
        // Slot 'setBlurIterations'
        QtMocHelpers::SlotData<void(int)>(14, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 12 },
        }}),
        // Slot 'setCausticGain'
        QtMocHelpers::SlotData<void(qreal)>(15, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 12 },
        }}),
        // Slot 'setCornerRadius'
        QtMocHelpers::SlotData<void(qreal)>(16, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 12 },
        }}),
        // Slot 'setAccentColor'
        QtMocHelpers::SlotData<void(const QColor &)>(17, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'themeMode'
        QtMocHelpers::PropertyData<enum ThemeMode>(19, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'blurRadius'
        QtMocHelpers::PropertyData<qreal>(20, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'blurIterations'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'causticGain'
        QtMocHelpers::PropertyData<qreal>(22, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'cornerRadius'
        QtMocHelpers::PropertyData<qreal>(23, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'accentColor'
        QtMocHelpers::PropertyData<QColor>(24, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 5),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ThemeMode'
        QtMocHelpers::EnumData<enum ThemeMode>(11, 11, QMC::EnumFlags{}).add({
            {   25, ThemeMode::Valo },
            {   26, ThemeMode::Soar },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<EngineConfig, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject EngineConfig::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12EngineConfigE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12EngineConfigE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12EngineConfigE_t>.metaTypes,
    nullptr
} };

void EngineConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EngineConfig *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->themeModeChanged(); break;
        case 1: _t->blurRadiusChanged(); break;
        case 2: _t->blurIterationsChanged(); break;
        case 3: _t->causticGainChanged(); break;
        case 4: _t->cornerRadiusChanged(); break;
        case 5: _t->accentColorChanged(); break;
        case 6: _t->setThemeMode((*reinterpret_cast<std::add_pointer_t<enum ThemeMode>>(_a[1]))); break;
        case 7: _t->setBlurRadius((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 8: _t->setBlurIterations((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setCausticGain((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 10: _t->setCornerRadius((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 11: _t->setAccentColor((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::themeModeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::blurRadiusChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::blurIterationsChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::causticGainChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::cornerRadiusChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineConfig::*)()>(_a, &EngineConfig::accentColorChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<enum ThemeMode*>(_v) = _t->themeMode(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->blurRadius(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->blurIterations(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->causticGain(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->cornerRadius(); break;
        case 5: *reinterpret_cast<QColor*>(_v) = _t->accentColor(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setThemeMode(*reinterpret_cast<enum ThemeMode*>(_v)); break;
        case 1: _t->setBlurRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 2: _t->setBlurIterations(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setCausticGain(*reinterpret_cast<qreal*>(_v)); break;
        case 4: _t->setCornerRadius(*reinterpret_cast<qreal*>(_v)); break;
        case 5: _t->setAccentColor(*reinterpret_cast<QColor*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *EngineConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12EngineConfigE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EngineConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EngineConfig::themeModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EngineConfig::blurRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EngineConfig::blurIterationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EngineConfig::causticGainChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EngineConfig::cornerRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EngineConfig::accentColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
