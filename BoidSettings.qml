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
    height: 57
    visible: false
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
    visible: false
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
                management.setVelocity(value);
            }
        }

    }
}

GroupBox {
    id: mouseFollowBox
    x: 8
    width: 212
    visible: false
    anchors.top: velocityBox.bottom
    anchors.topMargin: -84
    opacity: 0
    title: qsTr("Mouse following")

    Item {
        id: continuous_settings
        height: 25
        anchors.top: parent.top
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
    height: 139
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
            text: "50"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_flock
            x: 45
            width: 117
            value: 50
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
            text: "100"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_avoid
            x: 45
            width: 117
            minimumValue: 0
            value: 100
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
            text: "100"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_match
            x: 45
            width: 117
            value: 100
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
            text: "25"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Slider {
            id: slider_beh_target
            x: 45
            width: 117
            value: 25
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
            height: 367
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
                target: miscBox
                visible: true
                opacity: 1
            }

            PropertyChanges {
                target: velocityBox
                width: 212
                height: 57
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: label_AVG
                x: 0
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
                width: 212
                height: 57
                visible: true
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: continuous_settings
                width: 200
                opacity: 1
            }

            PropertyChanges {
                target: behaviorBox
                anchors.topMargin: 6
                opacity: 1
            }

            PropertyChanges {
                target: beh_avoidBox
                opacity: 1
                anchors.topMargin: 6
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
