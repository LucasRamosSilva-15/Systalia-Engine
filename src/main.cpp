#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSGRendererInterface>

#include <cstdlib>
#include <cstring>
#include <vector>

#include <vulkan/vulkan.h>

#ifndef NDEBUG
namespace {

bool hasVulkanValidationLayer()
{
    uint32_t layerCount = 0;
    if (vkEnumerateInstanceLayerProperties(&layerCount, nullptr) != VK_SUCCESS)
        return false;

    if (layerCount == 0)
        return false;

    std::vector<VkLayerProperties> layers(layerCount);
    if (vkEnumerateInstanceLayerProperties(&layerCount, layers.data()) != VK_SUCCESS)
        return false;

    for (const VkLayerProperties &layer : layers) {
        if (std::strcmp(layer.layerName, "VK_LAYER_KHRONOS_validation") == 0)
            return true;
    }
    return false;
}

} // namespace
#endif

int main(int argc, char *argv[])
{
    qputenv("QSG_RHI_BACKEND", QByteArrayLiteral("vulkan"));
    qputenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", QByteArrayLiteral("1"));

#ifndef NDEBUG
    if (hasVulkanValidationLayer()) {
        qputenv("VK_INSTANCE_LAYERS", QByteArrayLiteral("VK_LAYER_KHRONOS_validation"));
        qputenv("QSG_RHI_DEBUG_LAYER", QByteArrayLiteral("1"));
    }
#endif

    QQuickWindow::setGraphicsApi(QSGRendererInterface::Vulkan);

    QGuiApplication application(argc, argv);
    application.setApplicationName(QStringLiteral("Systalia Glass Engine"));
    application.setApplicationVersion(QStringLiteral("0.1.0"));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &application,
        [] { QCoreApplication::exit(EXIT_FAILURE); },
        Qt::QueuedConnection);

    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/Systalia/Glass/compositor.qml")));
    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    return application.exec();
}
