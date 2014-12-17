import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    signal changeRunning(bool value)
    onChangeRunning: {
        count_settings.enabled = !value
        size_settings.enabled = !value
    }

    Label {
        id: label_title
        x: 98
        y: 8
        text: "Boids"
    }

    Item {
        id: count_settings
        x: 8
        y: 30
        width: 212
        height: 22
        anchors.horizontalCenter: parent.horizontalCenter
        opacity: 0

        Label {
            id: label_COUNT
            text: "Count:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentcount
            x: 187
            text: "0"
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_count
            x: 45
            width: 136
            activeFocusOnPress: true
            stepSize: 1
            maximumValue: 25
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                controls1.count = value
                label_currentcount.text = value
            }
        }
    }

Item {
    id: speed_settings
        x: 8
        width: 212
        height: 22
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: -22
        anchors.top: count_settings.bottom
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

Item {
    id: size_settings
    x: 8
    y: 30
    width: 212
    height: 22
    anchors.top: speed_settings.bottom
    Label {
        id: label_SIZE
        text: "Speed:"
        anchors.verticalCenter: parent.verticalCenter
    }

    Label {
        id: label_currentsize
        x: 187
        text: "10"
        anchors.verticalCenter: parent.verticalCenter
    }

    Slider {
        id: slider_size
        x: 45
        width: 136
        activeFocusOnPress: true
        tickmarksEnabled: true
        updateValueWhileDragging: true
        stepSize: 1
        minimumValue: 5
        anchors.verticalCenter: parent.verticalCenter
        maximumValue: 15
        value: 10

        onValueChanged: {
            controls1.size = value
            label_currentsize.text = value
        }
    }
    anchors.horizontalCenter: parent.horizontalCenter
    opacity: 0
    anchors.topMargin: -22
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
                text: "Boids:"
                anchors.verticalCenterOffset: -97
                anchors.horizontalCenterOffset: -90
            }

            PropertyChanges {
                target: slider_count
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 9
            }

            PropertyChanges {
                target: count_settings
                opacity: 1
            }

            PropertyChanges {
                target: label_currentcount
                anchors.verticalCenterOffset: 0
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

            PropertyChanges {
                target: size_settings
                anchors.horizontalCenterOffset: 0
                opacity: 1
                anchors.topMargin: 6
            }

            PropertyChanges {
                target: label_SIZE
                text: "Size:"
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
