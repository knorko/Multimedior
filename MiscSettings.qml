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

    Item {
        id: speed_settings
        x: 8
        y: 30
        width: 212
            height: 22
            anchors.horizontalCenter: parent.horizontalCenter
            opacity: 0

            Label {
                id: label_SPEED
                text: "Speed:"
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: label_currentspeed
                x: 187
                text: "0.00"
                anchors.verticalCenter: parent.verticalCenter
            }

            Slider {
                id: slider_speed
                x: 45
                width: 136
                activeFocusOnPress: true
                minimumValue: 0.1
                value: 1
                maximumValue: 2
                anchors.verticalCenter: parent.verticalCenter

                onValueChanged: {
                    label_currentspeed.text = value.toFixed(2)
                    management.setSpeed(value)
                }
            }
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

            PropertyChanges {
                target: speed_settings
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: slider_speed
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: label_currentspeed
                anchors.verticalCenterOffset: 0
            }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation {
                easing.type: Easing.OutExpo
                properties: {"x, y, topMargin, opacity, height"}
            }
        }
    ]
}
