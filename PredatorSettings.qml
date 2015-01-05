import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    signal changeRunning(bool value)
    onChangeRunning: {
        miscBox.enabled = !value
    }

    Label {
        id: label_title
        x: 89
        y: 8
        text: "Predators"
        opacity: 1
    }

    GroupBox {
        id: miscBox
        x: 8
        y: 30
        width: 212
        height: 57
        visible: false
        title: qsTr("Misc.")
        opacity: 0

        Item {
            id: count_settings
            height: 22
            anchors.right: parent.right
            anchors.left: parent.left

            Label {
                id: label_COUNT
                text: "Count:"
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: label_currentcount
                x: 187
                text: "0"
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
            }

            Slider {
                id: slider_count
                x: 45
                width: 136
                minimumValue: 0
                value: 0
                activeFocusOnPress: true
                stepSize: 1
                maximumValue: 10
                anchors.verticalCenter: parent.verticalCenter

                onValueChanged: {
                    controls1.predatorCount = value
                    label_currentcount.text = value
                }
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
                text: "Predators:"
                anchors.verticalCenterOffset: -97
                anchors.horizontalCenterOffset: -67
            }

            PropertyChanges {
                target: miscBox
                visible: true
                opacity: 1
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
