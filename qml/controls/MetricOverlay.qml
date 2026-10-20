import QtQuick

Item {
    id: root

    property real frameTimeMs: 6.94
    property real gpuLatencyMs: 0.72
    property string backendName: qsTr("Vulkan")
    implicitWidth: metricsColumn.implicitWidth + 28
    implicitHeight: metricsColumn.implicitHeight + 22

    Rectangle {
        anchors.fill: parent
        radius: 14
        color: Qt.rgba(0.02, 0.04, 0.09, 0.72)
        border.width: 1
        border.color: Qt.rgba(0.48, 0.90, 0.95, 0.24)
    }

    Column {
        id: metricsColumn
        anchors.fill: parent
        anchors.margins: 14
        spacing: 4

        Text {
            text: qsTr("RENDER TELEMETRY")
            color: "#A5F3FC"
            font.pixelSize: 10
            font.weight: Font.DemiBold
            font.letterSpacing: 1.2
        }

        Text {
            text: qsTr("%1 · %2 ms frame").arg(root.backendName).arg(root.frameTimeMs.toFixed(2))
            color: "#F4FBFF"
            font.pixelSize: 13
        }

        Text {
            text: qsTr("GPU latency %1 ms").arg(root.gpuLatencyMs.toFixed(2))
            color: "#9FB3C8"
            font.pixelSize: 11
        }
    }
}
