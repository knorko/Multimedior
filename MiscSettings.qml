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
        visible: false
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
            text: "1.00"
            anchors.right: parent.right
            horizontalAlignment: Text.AlignRight
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
        id: awareness_rad_settings
        height: 22
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.top: size_settings.bottom
        anchors.topMargin: -22
        visible: false
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_RADIUS
            y: 183
            text: qsTr("Radius:")
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            opacity: 0
        }

        Label {
            id: label_currentradius
            text: qsTr("20")
            horizontalAlignment: Text.AlignRight
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            opacity: 0
        }

        Slider {
            id: slider_awarenessRadius
            x: 45
            width: 136
            maximumValue: root.width
            stepSize: 1
            minimumValue: 7
            value: 100
            activeFocusOnPress: true
            tickmarksEnabled: false
            updateValueWhileDragging: true
            opacity: 0
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                __handlePos = value
                management.setAwarenessRadius(value)
                label_currentradius.text = value
            }
        }
    }

    Item {
        id: size_settings
        height: 22
        visible: false
        anchors.topMargin: -22
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: speed_settings.bottom
        Label {
            id: label_SIZE
            text: "Size:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentsize
            x: 187
            text: "7"
            anchors.right: parent.right
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
            maximumValue: 10
            value: 7

            onValueChanged: {
                management.setSize(value)
                label_currentsize.text = value
            }
        }
        opacity: 0
    }


    CheckBox {
        id: toggle_showRadius
        x: 8
        text: qsTr("Show radius")
        anchors.top: awareness_rad_settings.bottom
        anchors.topMargin: -21
        activeFocusOnPress: true
        opacity: 0

        onCheckedChanged: management.setAwarenessRadiusVisualization(checked)
    }


    GroupBox {
        id: color_settings
        x: 8
        width: 212
        height: 149
        visible: false
        anchors.topMargin: -149
        anchors.top: toggle_showRadius.bottom
        opacity: 0
        title: qsTr("Boid color")

        ColorPicker {
            id: colorPicker1
            anchors.right: parent.right
            anchors.left: parent.left
            opacity: 0
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
                height: 335
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
                visible: true
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
                y: 58
                height: 22
                anchors.topMargin: 6
                visible: true
                anchors.rightMargin: 8
                anchors.leftMargin: 8
                opacity: 1
            }

            PropertyChanges {
                target: colorPicker1
                width: 197
                anchors.horizontalCenterOffset: 2
                opacity: 1
            }

            PropertyChanges {
                target: color_settings
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: slider_awarenessRadius
                anchors.verticalCenterOffset: 0
                opacity: 1
            }

            PropertyChanges {
                target: label_RADIUS
                opacity: 1
            }

            PropertyChanges {
                target: awareness_rad_settings
                anchors.topMargin: 6
                visible: true
                opacity: 1
            }

            PropertyChanges {
                target: label_currentradius
                opacity: 1
            }

            PropertyChanges {
                target: toggle_showRadius
                anchors.topMargin: 6
                opacity: 1
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
