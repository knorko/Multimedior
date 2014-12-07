import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    Label {
        id: label_title
        x: 77
        y: 8
        text: "Miscellaneous"
        opacity: 1
    }

    id: rectangle1
    width: 228
    height: 32
    color: sysPalette.window
    radius: 1
    border.color: sysPalette.mid

    states: [
        State {
            name: "VISIBLE"

            PropertyChanges {
                target: rectangle1
                height: 225
            }

            PropertyChanges {
                target: label_title
                x: 8
                y: 8
                text: "Miscellaneous:"
                anchors.verticalCenterOffset: -97
                anchors.horizontalCenterOffset: -67
            }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation {
                easing.type: Easing.OutExpo
                properties: {"x, y, opacity, height"}
            }
        }
    ]
}
