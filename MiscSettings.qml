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
                management.setSize(value)
                label_currentsize.text = value
            }
        }
        opacity: 0
    }

    Item {
        id: flock_settings
        x: 8
        y: 81
        width: 200
        height: 200
        opacity: 0

        Slider {
            id: slider_flocking
            opacity: 0

            onValueChanged: {
                management.setFlockingFactor(value)
                label_currentflocking.text = value
            }
        }

        Label {
            id: label_FLOCKING
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label_currentflocking
            text: qsTr("Label")
            opacity: 0
        }
    }

    Item {
        id: avoidance_settings
        x: 8
        y: 130
        width: 200
        height: 200
        opacity: 0

        Label {
            id: label_AVOIDANCE
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label_currentavoidance
            x: 182
            y: 5
            text: qsTr("Label")
            opacity: 0
        }

        Slider {
            id: slider_avoidance
            x: 38
            y: 0
            opacity: 0

            onValueChanged: {
                management.setAvoidanceFactor(value)
                label_currentavoidance.text = value
            }
        }
    }

    Item {
        id: velocity_settings
        x: 8
        y: 155
        width: 200
        height: 200
        opacity: 0

        Label {
            id: label_VELOCITY
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label_currentvelocity
            x: 182
            y: 3
            text: qsTr("Label")
            opacity: 0
        }

        Slider {
            id: slider_velocity
            x: 38
            y: 0
            opacity: 0

            onValueChanged: {
                management.setVelocityFactor(value)
                label_currentvelocity.text = value
            }
        }
    }

    Item {
        id: mouse_importance
        x: 8
        y: 170
        width: 200
        height: 200
        opacity: 0

        Label {
            id: label_MOUSE
            x: 1
            y: 3
            text: qsTr("Label")
            opacity: 0
        }

        Label {
            id: label_currentmouse
            x: 182
            y: 3
            text: qsTr("Label")
            opacity: 0
        }

        Slider {
            id: slider_mouse
            x: 37
            y: 0
            opacity: 0

            onValueChanged: {
                management.setMouseFactor(value)
                label_currentmouse.text = value
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
                    anchors.leftMargin: 9
                    opacity: 1
                }

                PropertyChanges {
                    target: flock_settings
                    x: 8
                    y: 86
                    width: 212
                    height: 22
                    visible: true
                    opacity: 1
                }

                PropertyChanges {
                    target: slider_flocking
                    x: 45
                    y: 0
                    width: 136
                    height: 22
                    minimumValue: 1
                    value: 100
                    maximumValue: 100
                    opacity: 1
                }

                PropertyChanges {
                    target: label_currentflocking
                    x: 187
                    y: 3
                    width: 25
                    height: 17
                    text: qsTr("100")
                    opacity: 1
                }

                PropertyChanges {
                    target: label_FLOCKING
                    x: 0
                    y: 3
                    text: qsTr("Flock")
                    opacity: 1
                    activeFocusOnTab: false
                }

                PropertyChanges {
                    target: avoidance_settings
                    x: 8
                    y: 114
                    width: 212
                    height: 22
                    opacity: 1
                }

                PropertyChanges {
                    target: velocity_settings
                    x: 8
                    y: 142
                    width: 212
                    height: 22
                    opacity: 1
                }

                PropertyChanges {
                    target: label_AVOIDANCE
                    text: qsTr("Avoid")
                    opacity: 1
                }

                PropertyChanges {
                    target: label_VELOCITY
                    text: qsTr("Velocity")
                    opacity: 1
                }

                PropertyChanges {
                    target: label_currentavoidance
                    x: 198
                    y: 0
                    text: qsTr("20")
                    opacity: 1
                }

                PropertyChanges {
                    target: label_currentvelocity
                    x: 198
                    y: 0
                    text: qsTr("50")
                    opacity: 1
                }

                PropertyChanges {
                    target: mouse_importance
                    width: 212
                    height: 22
                    opacity: 1
                }

                PropertyChanges {
                    target: label_MOUSE
                    text: qsTr("Goal")
                    opacity: 1
                }

                PropertyChanges {
                    target: label_currentmouse
                    x: 187
                    y: 3
                    text: qsTr("25")
                    opacity: 1
                }

                PropertyChanges {
                    target: slider_avoidance
                    x: 45
                    width: 136
                    height: 22
                    minimumValue: 1
                    value: 20
                    maximumValue: 100
                    opacity: 1
                }

                PropertyChanges {
                    target: slider_velocity
                    x: 45
                    width: 136
                    minimumValue: 1
                    value: 50
                    maximumValue: 100
                    opacity: 1
                }

                PropertyChanges {
                    target: slider_mouse
                    x: 45
                    width: 136
                    minimumValue: 1
                    value: 25
                    maximumValue: 100
                    opacity: 1
                }

                PropertyChanges {
                    target: label_currentsize
                    textFormat: Text.PlainText
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
