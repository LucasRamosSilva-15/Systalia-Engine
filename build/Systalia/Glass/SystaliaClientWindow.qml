import QtQuick
import QtQuick.Controls
import QtWayland.Compositor

Item {
    id: clientChassis

    required property var xdgSurface
    required property var toplevel
    property var compositor
    property Item backdropSource
    property int themeMode: toplevel && toplevel.appId ? (toplevel.appId.length % 2) : 0
    property color accentColor: themeMode === 0 ? "#00E5FF" : "#A5F3FC"
    property bool resizing: false

    signal requestRaise()

    width: 800
    height: 520
    z: 1
    clip: true

    function sendSizeConfigure() {
        if (!toplevel)
            return
        toplevel.sendConfigure(
            Qt.size(Math.max(320, Math.round(clientSurface.width)),
                    Math.max(200, Math.round(clientSurface.height))),
            toplevel.states)
    }

    function beginResize(mouseArea) {
        requestRaise()
        resizing = true
        mouseArea.startWidth = width
        mouseArea.startHeight = height
        mouseArea.startX = clientChassis.x
        mouseArea.startY = clientChassis.y
        mouseArea.pressX = mouseArea.mouseX
        mouseArea.pressY = mouseArea.mouseY
    }

    function updateResize(mouseArea) {
        var deltaX = mouseArea.mouseX - mouseArea.pressX
        var deltaY = mouseArea.mouseY - mouseArea.pressY
        var nextWidth = mouseArea.startWidth
        var nextHeight = mouseArea.startHeight
        var nextX = mouseArea.startX
        var nextY = mouseArea.startY

        if (mouseArea.resizeEdges & Qt.LeftEdge) {
            nextWidth = mouseArea.startWidth - deltaX
            nextX = mouseArea.startX + deltaX
        } else if (mouseArea.resizeEdges & Qt.RightEdge) {
            nextWidth = mouseArea.startWidth + deltaX
        }

        if (mouseArea.resizeEdges & Qt.TopEdge) {
            nextHeight = mouseArea.startHeight - deltaY
            nextY = mouseArea.startY + deltaY
        } else if (mouseArea.resizeEdges & Qt.BottomEdge) {
            nextHeight = mouseArea.startHeight + deltaY
        }

        var minimumWidth = Math.max(320, toplevel && toplevel.minSize.width > 0 ? toplevel.minSize.width : 320)
        var minimumHeight = Math.max(238, toplevel && toplevel.minSize.height > 0 ? toplevel.minSize.height + titleBar.height : 238)
        if (nextWidth < minimumWidth) {
            if (mouseArea.resizeEdges & Qt.LeftEdge)
                nextX -= minimumWidth - nextWidth
            nextWidth = minimumWidth
        }
        if (nextHeight < minimumHeight) {
            if (mouseArea.resizeEdges & Qt.TopEdge)
                nextY -= minimumHeight - nextHeight
            nextHeight = minimumHeight
        }

        x = nextX
        y = nextY
        width = nextWidth
        height = nextHeight
        sendSizeConfigure()
    }

    SystaliaGlassItem {
        id: glassLayer
        anchors.fill: parent
        backdropSource: clientChassis.backdropSource
        themeMode: clientChassis.themeMode
        blurRadius: 18
        blurIterations: 4
        causticIntensity: themeMode === 0 ? 0.72 : 0.46
        cornerRadius: 34
        accentColor: clientChassis.accentColor
        time: 0
    }

    Rectangle {
        id: titleBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 38
        color: Qt.rgba(2 / 255, 6 / 255, 23 / 255, 0.45)
        z: 2

        Text {
            anchors.left: parent.left
            anchors.leftMargin: 14
            anchors.right: controlRow.left
            anchors.verticalCenter: parent.verticalCenter
            text: toplevel && toplevel.title ? toplevel.title : qsTr("Wayland application")
            color: "#E2F8FF"
            font.pixelSize: 12
            font.weight: Font.DemiBold
            elide: Text.ElideRight
        }

        Row {
            id: controlRow
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.verticalCenter: parent.verticalCenter
            spacing: 4

            Button {
                width: 24
                height: 24
                text: "−"
                onClicked: {
                    requestRaise()
                    if (toplevel)
                        toplevel.setMinimized()
                }
            }

            Button {
                width: 24
                height: 24
                text: toplevel && toplevel.maximized ? "❐" : "□"
                onClicked: {
                    requestRaise()
                    if (!toplevel)
                        return
                    if (toplevel.maximized)
                        toplevel.unsetMaximized()
                    else
                        toplevel.setMaximized()
                }
            }

            Button {
                width: 24
                height: 24
                text: "×"
                onClicked: if (toplevel) toplevel.sendClose()
            }
        }

        MouseArea {
            anchors.left: parent.left
            anchors.right: controlRow.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 6
            acceptedButtons: Qt.LeftButton
            drag.target: clientChassis
            drag.axis: Drag.XAndYAxis
            onPressed: {
                requestRaise()
                sendSizeConfigure()
            }
        }
    }

    ShellSurfaceItem {
        id: clientSurface
        anchors.top: titleBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        shellSurface: clientChassis.xdgSurface
        inputEventsEnabled: true
        focusOnClick: true
        onSurfaceDestroyed: clientChassis.destroy()
    }

    Component.onCompleted: sendSizeConfigure()

    MouseArea {
        id: topLeftResize
        property int resizeEdges: Qt.LeftEdge | Qt.TopEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        x: 0
        y: 0
        width: 12
        height: 12
        z: 4
        cursorShape: Qt.SizeFDiagCursor
        onPressed: beginResize(topLeftResize)
        onPositionChanged: if (pressed) updateResize(topLeftResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: topResize
        property int resizeEdges: Qt.TopEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.top: parent.top
        anchors.left: topLeftResize.right
        anchors.right: topRightResize.left
        height: 8
        z: 4
        cursorShape: Qt.SizeVerCursor
        onPressed: beginResize(topResize)
        onPositionChanged: if (pressed) updateResize(topResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: topRightResize
        property int resizeEdges: Qt.RightEdge | Qt.TopEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.top: parent.top
        anchors.right: parent.right
        width: 12
        height: 12
        z: 4
        cursorShape: Qt.SizeBDiagCursor
        onPressed: beginResize(topRightResize)
        onPositionChanged: if (pressed) updateResize(topRightResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: leftResize
        property int resizeEdges: Qt.LeftEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.left: parent.left
        anchors.top: topLeftResize.bottom
        anchors.bottom: bottomLeftResize.top
        width: 8
        z: 4
        cursorShape: Qt.SizeHorCursor
        onPressed: beginResize(leftResize)
        onPositionChanged: if (pressed) updateResize(leftResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: rightResize
        property int resizeEdges: Qt.RightEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.right: parent.right
        anchors.top: topRightResize.bottom
        anchors.bottom: bottomRightResize.top
        width: 8
        z: 4
        cursorShape: Qt.SizeHorCursor
        onPressed: beginResize(rightResize)
        onPositionChanged: if (pressed) updateResize(rightResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: bottomLeftResize
        property int resizeEdges: Qt.LeftEdge | Qt.BottomEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 12
        height: 12
        z: 4
        cursorShape: Qt.SizeBDiagCursor
        onPressed: beginResize(bottomLeftResize)
        onPositionChanged: if (pressed) updateResize(bottomLeftResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: bottomResize
        property int resizeEdges: Qt.BottomEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.bottom: parent.bottom
        anchors.left: bottomLeftResize.right
        anchors.right: bottomRightResize.left
        height: 8
        z: 4
        cursorShape: Qt.SizeVerCursor
        onPressed: beginResize(bottomResize)
        onPositionChanged: if (pressed) updateResize(bottomResize)
        onReleased: clientChassis.resizing = false
    }

    MouseArea {
        id: bottomRightResize
        property int resizeEdges: Qt.RightEdge | Qt.BottomEdge
        property real startWidth: 0
        property real startHeight: 0
        property real startX: 0
        property real startY: 0
        property real pressX: 0
        property real pressY: 0
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 12
        height: 12
        z: 4
        cursorShape: Qt.SizeFDiagCursor
        onPressed: beginResize(bottomRightResize)
        onPositionChanged: if (pressed) updateResize(bottomRightResize)
        onReleased: clientChassis.resizing = false
    }
}
