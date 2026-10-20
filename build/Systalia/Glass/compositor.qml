import QtQuick
import QtQuick.Controls
import QtWayland.Compositor
import QtWayland.Compositor.XdgShell

ApplicationWindow {
    id: root

    visible: true
    width: 1920
    height: 1080
    minimumWidth: 960
    minimumHeight: 540
    title: qsTr("Systalia Glass Compositor")
    color: "#050816"

    property int highestZ: 0

    function raiseWindow(windowItem) {
        if (!windowItem)
            return
        windowItem.z = ++highestZ
    }

    WaylandCompositor {
        id: waylandCompositor
        socketName: "wayland-systalia-0"

        Component.onCompleted: console.log("Systalia Wayland compositor initialized:", socketName)

        WaylandOutput {
            compositor: waylandCompositor
            window: root
            manufacturer: "Systalia"
            model: "Glass Virtual Display"
        }

        XdgShell {
            id: xdgShell

            onToplevelCreated: function(toplevel, xdgSurface) {
                var clientWindow = clientWindowComponent.createObject(desktopSurface, {
                    "xdgSurface": xdgSurface,
                    "toplevel": toplevel,
                    "compositor": waylandCompositor,
                    "backdropSource": backdropSource
                })

                if (!clientWindow)
                    return

                clientWindow.x = Math.max(24, (desktopSurface.width - clientWindow.width) * 0.5)
                clientWindow.y = Math.max(64, (desktopSurface.height - clientWindow.height) * 0.5)
                raiseWindow(clientWindow)
                clientWindow.requestRaise.connect(function() { raiseWindow(clientWindow) })
            }
        }
    }

    Item {
        id: desktopBackdrop
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: "#050816"
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#102A43" }
                GradientStop { position: 0.46; color: "#071A2D" }
                GradientStop { position: 1.0; color: "#020617" }
            }
        }

        Repeater {
            model: 10
            delegate: Rectangle {
                required property int index
                x: (index * 211) % Math.max(1, desktopBackdrop.width)
                y: 72 + ((index * 137) % Math.max(1, desktopBackdrop.height - 120))
                width: 2
                height: Math.max(80, desktopBackdrop.height * 0.42)
                rotation: 18
                opacity: 0.10
                color: index % 2 === 0 ? "#00E5FF" : "#A855F7"
            }
        }

        Text {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 28
            text: qsTr("SYSTALIA GLASS / WAYLAND COMPOSITOR")
            color: "#D9F9FF"
            font.pixelSize: 13
            font.weight: Font.DemiBold
            font.letterSpacing: 1.4
        }

        Text {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 28
            text: qsTr("SOCKET  ·  wayland-systalia-0")
            color: "#7DD3FC"
            font.pixelSize: 11
            font.letterSpacing: 1.0
        }
    }

    ShaderEffectSource {
        id: backdropSource
        anchors.fill: parent
        sourceItem: desktopBackdrop
        sourceRect: Qt.rect(0, 0, desktopBackdrop.width, desktopBackdrop.height)
        live: true
        hideSource: false
        visible: false
    }

    Item {
        id: desktopSurface
        anchors.fill: parent
    }

    Component {
        id: clientWindowComponent
        SystaliaClientWindow { }
    }
}
