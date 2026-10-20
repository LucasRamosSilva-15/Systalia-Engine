import QtQuick

Item {
    id: root

    Repeater {
        model: 14

        delegate: Rectangle {
            required property int index

            width: 150 + (index % 5) * 34
            height: width
            radius: width * 0.5
            color: ["#12B8D6", "#6D5CF6", "#F071A8", "#8FE388", "#FFB35C"][index % 5]
            opacity: 0.15 + (index % 4) * 0.035
            x: -width + (index % 4) * root.width * 0.27
            y: root.height * (0.08 + (index % 5) * 0.19)
            transformOrigin: Item.Center

            RotationAnimator on rotation {
                from: -40 + index * 11
                to: 320 + index * 11
                duration: 7200 + index * 330
                loops: Animation.Infinite
                running: root.visible
            }

            XAnimator on x {
                from: -width
                to: root.width + width
                duration: 11000 + index * 450
                loops: Animation.Infinite
                running: root.visible
            }
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.width: 1
        border.color: Qt.rgba(0.42, 0.88, 0.94, 0.10)
    }
}
