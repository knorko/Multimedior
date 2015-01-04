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
        x: 98
        y: 8
        text: "Boids"
    }

GroupBox {
    id: miscBox
    x: 8
    y: 30
    width: 212
    height: 84
    title: qsTr("Misc.")
    opacity: 0

    Item {
        id: count_settings
        height: 22
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_COUNT
            text: "Count:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentcount
            x: 187
            text: "5"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_count
            x: 45
            width: 136
            minimumValue: 5
            value: 5
            activeFocusOnPress: true
            stepSize: 1
            maximumValue: 100
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                controls1.count = value
                label_currentcount.text = value
            }
        }
    }

    Item {
        id: size_settings
        y: -99
        height: 22
        anchors.topMargin: 6
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: count_settings.bottom
        Label {
            id: label_SIZE
            text: "Size:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentsize
            x: 187
            text: "10"
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
            maximumValue: 15
            value: 10

            onValueChanged: {
                controls1.size = value
                label_currentsize.text = value
            }
        }
        opacity: 0
    }
}

GroupBox {
    id: velocityBox
    x: 8
    width: 212
    height: 84
    anchors.top: miscBox.bottom
    anchors.topMargin: -84
    title: qsTr("Velocity")
    opacity: 0

    Item {
        id: speed_avg_settings
        y: -57
        height: 22
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_AVG
            x: -8
            y: -20
            text: "Average:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentspeedavg
            x: 187
            text: "0.00"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_speed_avg
            x: 45
            width: 117
            updateValueWhileDragging: false
            activeFocusOnPress: true
            minimumValue: 0.1
            value: 1
            maximumValue: 2
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentspeedavg.text = value.toFixed(2)
                management.setVelocity(value, slider_speed_var.value);
            }
        }

    }

    Item {
        id: speed_var_settings
        x: 0
        y: 28
        height: 22
        anchors.top: speed_avg_settings.bottom
        anchors.topMargin: -22
        anchors.left: parent.left
        opacity: 0
        anchors.right: parent.right
        Label {
            id: label_VAR
            x: -8
            y: -20
            text: "Variance:"
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentspeedvar
            x: 187
            text: "0.00"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_speed_var
            x: 45
            width: 117
            updateValueWhileDragging: false
            value: 0.1
            maximumValue: 0.5
            activeFocusOnPress: true
            minimumValue: 0
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentspeedvar.text = value.toFixed(2)
                management.setVelocity(slider_speed_avg.value, value);
            }
        }
    }
}

GroupBox {
    id: targetBox
    x: 8
    width: 212
    height: 160
    anchors.top: velocityBox.bottom
    anchors.topMargin: -84
    opacity: 0
    title: qsTr("Target")

    Item {
        id: globalTarget_settings
        height: 25
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_GLOBAL
            y: 8
            text: qsTr("Global")
            anchors.verticalCenter: parent.verticalCenter
            opacity: 0
        }

        ComboBox {
            id: comboBox1
            currentIndex: 0
            width: 152
            anchors.right: parent.right
            anchors.rightMargin: 0

            model: ListModel {
                id: globalTarget
                ListElement { text: "Mouse (click)"; property bool value: false }
                ListElement { text: "Mouse (continuous)"; property bool value: true }
            }
            onCurrentIndexChanged: renderCanvas1.continuous = globalTarget.get(currentIndex).value
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
            height: 384
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
                width: 125
                height: 22
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 9
            }

            PropertyChanges {
                target: count_settings
                width: 180
                height: 22
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.horizontalCenterOffset: 8
                opacity: 1
            }

            PropertyChanges {
                target: speed_avg_settings
                y: 0
                anchors.horizontalCenterOffset: 8
                anchors.topMargin: 127
                opacity: 1
            }

            PropertyChanges {
                target: slider_speed_avg
                x: 53
                width: 117
                height: 22
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: label_currentspeedavg
                x: 172
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

            PropertyChanges {
                target: miscBox
                opacity: 1
            }

            PropertyChanges {
                target: slider_size
                width: 125
                height: 22
            }

            PropertyChanges {
                target: label_currentsize
                x: 182
            }

            PropertyChanges {
                target: velocityBox
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: label_AVG
                x: 0
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: speed_var_settings
                y: 28
                anchors.topMargin: 6
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                opacity: 1
            }

            PropertyChanges {
                target: label_VAR
                x: 0
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: slider_speed_var
                x: 53
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: label_currentspeedvar
                x: 172
                width: 24
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: label_currentcount
                x: 185
                anchors.verticalCenterOffset: 0
                anchors.rightMargin: 0
            }

            PropertyChanges {
                target: targetBox
                width: 212
                height: 160
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: globalTarget_settings
                width: 200
                opacity: 1
            }

            PropertyChanges {
                target: label_GLOBAL
                anchors.verticalCenterOffset: 0
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
