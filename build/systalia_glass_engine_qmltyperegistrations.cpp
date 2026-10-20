/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<EngineConfig.hpp>)
#  include <EngineConfig.hpp>
#endif
#if __has_include(<SystaliaGlassItem.hpp>)
#  include <SystaliaGlassItem.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Systalia_Glass()
{
    qmlRegisterModule("Systalia.Glass", 254, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<EngineConfig>("Systalia.Glass", 254);
    qmlRegisterEnum<EngineConfig::ThemeMode>("EngineConfig::ThemeMode");
    qmlRegisterTypesAndRevisions<SystaliaGlassItem>("Systalia.Glass", 254);
    qmlRegisterAnonymousType<QQuickItem, 254>("Systalia.Glass", 254);
    QT_WARNING_POP
    qmlRegisterModule("Systalia.Glass", 254, 254);
}

static const QQmlModuleRegistration systaliaGlassRegistration("Systalia.Glass", qml_register_types_Systalia_Glass);
