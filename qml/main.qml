import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    visible: true
    width: 1440
    height: 900
    minimumWidth: 980
    minimumHeight: 680
    title: qsTr("Systalia Glass Engine · Vulkan test harness")
    color: "#070B16"

    property int themeMode: 0
    property real blurRadius: 16
    property int blurIterations: 4
    property real causticIntensity: 0.72
    property real cornerRadius: 42
    property bool springEnabled: true
    property real motionTime: 0
    property int frameCount: 0
    property real frameTimeMs: 6.94
    property real gpuLatencyMs: 0.72

    EngineConfig {
        id: engineConfig
        themeMode: root.themeMode
        blurRadius: root.blurRadius
        blurIterations: root.blurIterations
        causticGain: root.causticIntensity
        cornerRadius: root.cornerRadius
        accentColor: root.themeMode === 0 ? "#00E5FF" : "#A5F3FC"
    }

    AnimatedBackdrop {
        id: animatedBackdrop
        anchors.fill: parent
        visible: true
    }

    ShaderEffectSource {
        id: backdropSource
        anchors.fill: parent
        sourceItem: animatedBackdrop
        sourceRect: Qt.rect(0, 0, root.width, root.height)
        live: true
        hideSource: false
        visible: true
        z: -1
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        gradient: Gradient {
            GradientStop { position: 0.0; color: Qt.rgba(0.02, 0.05, 0.12, 0.20) }
            GradientStop { position: 1.0; color: Qt.rgba(0.01, 0.02, 0.06, 0.48) }
        }
    }

    GlassWindow {
        id: primaryWindow
        x: Math.max(28, (root.width - width) * 0.5)
        y: Math.max(78, (root.height - height) * 0.5)
        width: 460
        height: 520
        backdropSource: backdropSource
        themeMode: root.themeMode
        blurRadius: root.blurRadius
        blurIterations: root.blurIterations
        causticIntensity: root.causticIntensity
        cornerRadius: root.cornerRadius
        springEnabled: root.springEnabled
        time: root.motionTime
        onThemeModeRequested: root.themeMode = mode
        onBlurRadiusRequested: root.blurRadius = radius
        onBlurIterationsRequested: root.blurIterations = iterations
        onCausticIntensityRequested: root.causticIntensity = intensity
        onCornerRadiusRequested: root.cornerRadius = radius
        onSpringEnabledRequested: root.springEnabled = enabled
        onResetRequested: {
            root.themeMode = 0
            root.blurRadius = 16
            root.blurIterations = 4
            root.causticIntensity = 0.72
            root.cornerRadius = 42
        }
    }

    GlassWindow {
        id: secondaryWindow
        x: Math.min(root.width - width - 32, primaryWindow.x + 360)
        y: Math.min(root.height - height - 30, primaryWindow.y + 112)
        width: 340
        height: 312
        backdropSource: backdropSource
        themeMode: root.themeMode === 0 ? 1 : 0
        blurRadius: root.blurRadius * 0.72
        blurIterations: root.blurIterations
        causticIntensity: root.causticIntensity * 0.55
        cornerRadius: Math.max(24, root.cornerRadius - 8)
        springEnabled: root.springEnabled
        time: root.motionTime
        onThemeModeRequested: root.themeMode = mode
        onBlurRadiusRequested: root.blurRadius = radius
        onBlurIterationsRequested: root.blurIterations = iterations
        onCausticIntensityRequested: root.causticIntensity = intensity
        onCornerRadiusRequested: root.cornerRadius = radius
        onSpringEnabledRequested: root.springEnabled = enabled
        onResetRequested: primaryWindow.resetRequested()
    }

    MetricOverlay {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 24
        frameTimeMs: root.frameTimeMs
        gpuLatencyMs: root.gpuLatencyMs
    }

    Text {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 24
        text: qsTr("SYSTALIA / GLASS ENGINE  ·  SPRINT 01")
        color: Qt.rgba(0.68, 0.80, 0.90, 0.56)
        font.pixelSize: 10
        font.weight: Font.DemiBold
        font.letterSpacing: 1.2
    }

    Timer {
        interval: 16
        repeat: true
        running: root.visible
        onTriggered: {
            root.motionTime += interval / 1000
            root.frameCount += 1
        }
    }

    Timer {
        interval: 500
        repeat: true
        running: root.visible
        onTriggered: {
            root.frameTimeMs = interval / Math.max(1, root.frameCount)
            root.gpuLatencyMs = Math.min(3.4, root.frameTimeMs * 0.18)
            root.frameCount = 0
        }
    }
}
