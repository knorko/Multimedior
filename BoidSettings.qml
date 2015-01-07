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
    height: 52
    visible: false
    title: qsTr("Misc.")
    opacity: 0

    Item {
        id: count_settings
        height: 22
        anchors.verticalCenter: parent.verticalCenter
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
            text: "15"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_count
            x: 45
            width: 125
            minimumValue: 15
            value: 15
            activeFocusOnPress: true
            stepSize: 1
            maximumValue: 150
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                if(controls1)
                    controls1.boidCount = value

                label_currentcount.text = value

            }
        }
    }
}

GroupBox {
    id: velocityBox
    x: 8
    width: 212
    height: 52
    visible: false
    anchors.top: miscBox.bottom
    anchors.topMargin: -84
    title: qsTr("Velocity")
    opacity: 0

    Item {
        id: speed_max_settings
        y: -57
        height: 22
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_MAXSPEED
            y: -20
            text: "Limit:"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentspeedmax
            x: 187
            text: "1.5"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_speed_max
            x: 45
            width: 125
            updateValueWhileDragging: true
            activeFocusOnPress: true
            minimumValue: 0.5
            value: 1.5
            maximumValue: 2
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentspeedmax.text = value.toFixed(2)
                management.setVelocity(value);
            }
        }

    }
}

GroupBox {
    id: mouseFollowBox
    x: 8
    width: 212
    height: 82
    visible: false
    anchors.top: velocityBox.bottom
    anchors.topMargin: -92
    opacity: 0
    title: qsTr("Mouse following")

    Item {
        id: mouse_mode
        width: 150
        height: 22
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        opacity: 0

        ExclusiveGroup { id: mouseModeGroup }

        RadioButton {
            id: radio_follow
            text: qsTr("Follow")
            anchors.left: parent.left
            activeFocusOnPress: true
            checked: true
            anchors.top: parent.top
            opacity: 0
            exclusiveGroup: mouseModeGroup

            onCheckedChanged: management.setMouseFollowMode(checked)
        }

        RadioButton {
            id: radio_avoid
            text: qsTr("Avoid")
            anchors.right: parent.right
            activeFocusOnPress: true
            anchors.top: parent.top
            opacity: 0
            exclusiveGroup: mouseModeGroup

            onCheckedChanged: management.setMouseFollowMode(!checked)
        }
    }

    Item {
        id: continuous_settings
        height: 25
        anchors.top: mouse_mode.bottom
        anchors.topMargin: -22
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        CheckBox {
            id: checkBox1
            text: qsTr("Continuous")
            activeFocusOnPress: true
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            opacity: 0

            onCheckedChanged: {
                renderCanvas1.continuous = checked
            }
        }
    }

}

GroupBox {
    id: behaviorBox
    x: 8
    width: 212
    height: 136
    visible: false
    title: "Behavior"
    anchors.top: mouseFollowBox.bottom
    anchors.topMargin: -56
    opacity: 0


    Item {
        id: beh_flockBox
        x: 8
        y: 219
        height: 22
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
        opacity: 0

        Label {
            id: label_FLOCK
            y: -20
            text: "Flock:"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentflock
            x: 187
            text: "30"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_flock
            x: 45
            width: 117
            value: 30
            maximumValue: 100
            activeFocusOnPress: true
            minimumValue: 0
            updateValueWhileDragging: true
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentflock.text = value.toFixed(0)
                management.setFlockingFactor(value);
            }
        }
    }

    Item {
        id: beh_avoidBox
        x: 8
        y: 219
        height: 22
        anchors.topMargin: -22
        anchors.top: beh_flockBox.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        opacity: 0

        Label {
            id: label_AVOID
            y: -20
            text: "Avoid:"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentavoid
            x: 187
            text: "80"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_avoid
            x: 45
            width: 117
            minimumValue: 0
            value: 80
            maximumValue: 100
            activeFocusOnPress: true
            updateValueWhileDragging: true
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentavoid.text = value.toFixed(0)
                management.setAvoidanceFactor(value)
            }
        }
    }

    Item {
        id: beh_matchBox
        x: 17
        y: 213
        height: 22
        anchors.top: beh_avoidBox.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        opacity: 0
        anchors.topMargin: -22

        Label {
            id: label_MATCH
            y: -20
            text: "Match:"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currentmatch
            x: 187
            text: "80"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_match
            x: 45
            width: 117
            value: 80
            maximumValue: 100
            activeFocusOnPress: true
            minimumValue: 0
            updateValueWhileDragging: true
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currentmatch.text = value.toFixed(0)
                management.setVelocityMatchFactor(value)
            }
        }
    }

    Item {
        id: beh_targetBox
        x: 17
        y: 222
        height: 22
        anchors.top: beh_matchBox.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        opacity: 0
        anchors.topMargin: -22

        Label {
            id: label_beh_TARGET
            y: -20
            text: "Target:"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label_currenttarget
            x: 187
            text: "50"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_target
            x: 45
            width: 117
            value: 50
            maximumValue: 100
            minimumValue: 0
            activeFocusOnPress: true
            updateValueWhileDragging: true
            anchors.verticalCenter: parent.verticalCenter

            onValueChanged: {
                label_currenttarget.text = value.toFixed(0)
                management.setTargetFactor(value)
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
            height: 372
        }

            PropertyChanges {
                target: label_title
                x: 8
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
                width: 180
                height: 22
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.horizontalCenterOffset: 8
                opacity: 1
            }

            PropertyChanges {
                target: speed_max_settings
                y: 0
                anchors.horizontalCenterOffset: 8
                anchors.topMargin: 127
                opacity: 1
            }

            PropertyChanges {
                target: label_currentspeedmax
                x: 172
            }

            PropertyChanges {
                target: miscBox
                visible: true
                opacity: 1
            }

            PropertyChanges {
                target: velocityBox
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: label_MAXSPEED
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: label_currentcount
                x: 185
                anchors.verticalCenterOffset: 0
                anchors.rightMargin: 0
            }

            PropertyChanges {
                target: mouseFollowBox
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: continuous_settings
                width: 200
                anchors.topMargin: 6
                anchors.verticalCenterOffset: 42
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                opacity: 1
            }

            PropertyChanges {
                target: behaviorBox
                width: 212
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: beh_avoidBox
                opacity: 1
                anchors.topMargin: 6
                anchors.verticalCenterOffset: 0
            }

            PropertyChanges {
                target: beh_matchBox
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: beh_targetBox
                anchors.topMargin: 6
                x: -248
                width: 212
                visible: true
                opacity: 1
            }

            PropertyChanges {
                target: beh_flockBox
                opacity: 1
            }

            PropertyChanges {
                target: slider_beh_flock
                updateValueWhileDragging: true
            }

            PropertyChanges {
                target: checkBox1
                opacity: 1
            }

            PropertyChanges {
                target: mouse_mode
                y: 0
                height: 20
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                opacity: 1
            }

            PropertyChanges {
                target: radio_follow
                x: 0
                y: 17
                opacity: 1
            }

            PropertyChanges {
                target: radio_avoid
                x: 131
                anchors.rightMargin: 0
                anchors.leftMargin: 0
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
