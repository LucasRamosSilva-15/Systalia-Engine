import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
import QtQuick.Layouts

Item {
    id: root

    property Item backdropSource
    property int themeMode: 0
    property real blurRadius: 16
    property int blurIterations: 4
    property real causticIntensity: 0.72
    property real cornerRadius: 42
    property color accentColor: themeMode === 0 ? "#00E5FF" : "#A5F3FC"
    property bool springEnabled: true
    property real time: 0
    property real padding: 18

    signal themeModeRequested(int mode)
    signal blurRadiusRequested(real radius)
    signal blurIterationsRequested(int iterations)
    signal causticIntensityRequested(real intensity)
    signal cornerRadiusRequested(real radius)
    signal springEnabledRequested(bool enabled)
    signal resetRequested()

    implicitWidth: 380
    Layout.minimumWidth: 320
    implicitHeight: contentColumn.implicitHeight + (padding * 2)
    clip: true

    SystaliaGlassItem {
        id: glassSurface
        anchors.fill: parent
        backdropSource: root.backdropSource
        themeMode: root.themeMode
        blurRadius: root.blurRadius
        blurIterations: root.blurIterations
        causticIntensity: root.causticIntensity
        cornerRadius: root.cornerRadius
        accentColor: root.accentColor
        time: root.time
        Accessible.ignored: true
    }

    Rectangle {
        anchors.fill: parent
        radius: root.cornerRadius
        color: Qt.rgba(0.04, 0.08, 0.14, 0.16)
        border.width: 1
        border.color: Qt.rgba(root.accentColor.r, root.accentColor.g, root.accentColor.b, 0.48)
    }

    Item {
        id: contentFrame
        anchors.fill: parent
        anchors.margins: root.padding
        clip: true

        Flickable {
            id: contentViewport
            anchors.fill: parent
            contentWidth: width
            contentHeight: contentColumn.implicitHeight
            clip: true
            boundsBehavior: Flickable.StopAtBounds

            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AsNeeded
            }

            ColumnLayout {
                id: contentColumn
                width: contentViewport.width
                spacing: 10

                Item {
                    id: dragHeader
                    Layout.fillWidth: true
                    Layout.preferredHeight: 54

                    DragHandler {
                        target: root
                        grabPermissions: PointerHandler.CanTakeOverFromAnything
                    }

                    RowLayout {
                        anchors.fill: parent
                        spacing: 12

                        Rectangle {
                            Layout.preferredWidth: 10
                            Layout.preferredHeight: 10
                            radius: 5
                            color: root.accentColor
                            opacity: 0.92
                        }

                        ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 0

                            Text {
                                text: qsTr("SYSTALIA GLASS SURFACE")
                                color: "#F4FBFF"
                                font.pixelSize: 13
                                font.weight: Font.DemiBold
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                            }

                            Text {
                                text: root.themeMode === 0
                                    ? qsTr("VALO · optical crystal")
                                    : qsTr("SOAR · volumetric mist")
                                color: "#A5B7CC"
                                font.pixelSize: 11
                                elide: Text.ElideRight
                                Layout.fillWidth: true
                            }
                        }

                        Text {
                            text: qsTr("DRAG")
                            color: "#8196AE"
                            font.pixelSize: 9
                            font.weight: Font.DemiBold
                            font.letterSpacing: 1.1
                        }
                    }
                }

                RowLayout {
                    Layout.fillWidth: true

                    Text {
                        text: qsTr("Theme")
                        color: "#E2E8F0"
                        font.pixelSize: 13
                        elide: Text.ElideRight
                        Layout.fillWidth: true
                    }

                    ComboBox {
                        id: themeCombo
                        Layout.preferredWidth: 140
                        Layout.minimumWidth: 120
                        Layout.preferredHeight: 34
                        model: [qsTr("VALO"), qsTr("SOAR")]
                        currentIndex: root.themeMode
                        onActivated: root.themeModeRequested(currentIndex)

                        background: Rectangle {
                            radius: 8
                            color: Qt.rgba(15 / 255, 23 / 255, 42 / 255, 0.60)
                            border.width: 1
                            border.color: Qt.rgba(0.65, 0.95, 1.0, 0.30)
                        }

                        contentItem: Text {
                            leftPadding: 12
                            rightPadding: 34
                            text: themeCombo.displayText
                            color: "#F4FBFF"
                            font.pixelSize: 12
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        indicator: Text {
                            x: themeCombo.width - width - 12
                            anchors.verticalCenter: parent.verticalCenter
                            text: "⌄"
                            color: "#A5F3FC"
                            font.pixelSize: 16
                        }
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 4

                    RowLayout {
                        Layout.fillWidth: true

                        Text {
                            text: qsTr("Backdrop blur")
                            color: "#E2E8F0"
                            font.pixelSize: 13
                            elide: Text.ElideRight
                            Layout.fillWidth: true
                        }

                        Text {
                            text: qsTr("%1 px").arg(Math.round(root.blurRadius))
                            color: "#94A3B8"
                            font.pixelSize: 13
                            horizontalAlignment: Text.AlignRight
                            Layout.preferredWidth: 64
                        }
                    }

                    Slider {
                        id: blurSlider
                        Layout.fillWidth: true
                        from: 0
                        to: 36
                        stepSize: 1
                        value: root.blurRadius
                        onMoved: root.blurRadiusRequested(value)
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 4

                    RowLayout {
                        Layout.fillWidth: true

                        Text {
                            text: qsTr("Kawase iterations")
                            color: "#E2E8F0"
                            font.pixelSize: 13
                            elide: Text.ElideRight
                            Layout.fillWidth: true
                        }

                        Text {
                            text: blurIterationsSlider.value.toFixed(0)
                            color: "#94A3B8"
                            font.pixelSize: 13
                            horizontalAlignment: Text.AlignRight
                            Layout.preferredWidth: 64
                        }
                    }

                    Slider {
                        id: blurIterationsSlider
                        Layout.fillWidth: true
                        from: 1
                        to: 8
                        stepSize: 1
                        value: root.blurIterations
                        onMoved: root.blurIterationsRequested(Math.round(value))
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 4

                    RowLayout {
                        Layout.fillWidth: true

                        Text {
                            text: qsTr("Caustic intensity")
                            color: "#E2E8F0"
                            font.pixelSize: 13
                            elide: Text.ElideRight
                            Layout.fillWidth: true
                        }

                        Text {
                            text: causticSlider.value.toFixed(2)
                            color: "#94A3B8"
                            font.pixelSize: 13
                            horizontalAlignment: Text.AlignRight
                            Layout.preferredWidth: 64
                        }
                    }

                    Slider {
                        id: causticSlider
                        Layout.fillWidth: true
                        from: 0
                        to: 1.5
                        stepSize: 0.01
                        value: root.causticIntensity
                        enabled: root.themeMode === 0
                        onMoved: root.causticIntensityRequested(value)
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 4

                    RowLayout {
                        Layout.fillWidth: true

                        Text {
                            text: qsTr("G2 corner radius")
                            color: "#E2E8F0"
                            font.pixelSize: 13
                            elide: Text.ElideRight
                            Layout.fillWidth: true
                        }

                        Text {
                            text: cornerRadiusSlider.value.toFixed(0) + qsTr(" px")
                            color: "#94A3B8"
                            font.pixelSize: 13
                            horizontalAlignment: Text.AlignRight
                            Layout.preferredWidth: 64
                        }
                    }

                    Slider {
                        id: cornerRadiusSlider
                        Layout.fillWidth: true
                        from: 12
                        to: 100
                        stepSize: 1
                        value: root.cornerRadius
                        onMoved: root.cornerRadiusRequested(value)
                    }
                }

                RowLayout {
                    Layout.fillWidth: true

                    Text {
                        text: qsTr("Spring-damper drag")
                        color: "#E2E8F0"
                        font.pixelSize: 13
                        elide: Text.ElideRight
                        Layout.fillWidth: true
                    }

                    Switch {
                        checked: root.springEnabled
                        onToggled: root.springEnabledRequested(checked)
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 38
                    text: qsTr("Restore optical defaults")
                    onClicked: root.resetRequested()
                }
            }
        }
    }

    Behavior on x {
        enabled: root.springEnabled
        SpringAnimation {
            spring: 2.8
            damping: 0.72
            mass: 0.85
            epsilon: 0.25
        }
    }

    Behavior on y {
        enabled: root.springEnabled
        SpringAnimation {
            spring: 2.8
            damping: 0.72
            mass: 0.85
            epsilon: 0.25
        }
    }
}
