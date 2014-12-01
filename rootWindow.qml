import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    property SystemPalette sysPalette: null
    property string oldState: "BOID_SETTINGS"

    width: 640
    height: 480
    color: sysPalette.window
    radius: 4
    border.color: sysPalette.mid

    anchors.fill: parent
    anchors.leftMargin: 24
    anchors.topMargin: 2
    anchors.rightMargin: 2
    anchors.bottomMargin: 2

    Item {
        id: settings_root
        x: -262
        width: 260
        z: 1
        anchors.bottom: parent.bottom
        anchors.top: parent.top

        Rectangle {
            id: settings_background
            color: sysPalette.window
            border.color: sysPalette.mid
            radius: 4
            anchors.fill: parent

            Rectangle {
                id: settings_boid
                x: -177
                y: 8
                width: 229
                height: 32
                color: sysPalette.window
                radius: 4
                border.color: sysPalette.mid
                border.width: 1

                Label {
                    id: label_BOID
                    x: 235
                    y: 8
                    text: qsTr("Boids")
                }

                MouseArea {
                    id: select_boid
                    anchors.fill: parent
                    enabled: false

                    onClicked: root.state = "BOID_SETTINGS"
                }

                Item {
                    id: row_count
                    y: 30
                    height: 16
                    anchors.right: parent.right
                    anchors.rightMargin: 8
                    anchors.left: parent.left
                    anchors.leftMargin: 8

                    Label {
                        id: label_COUNT
                        text: qsTr("Label")
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 8
                        opacity: 0
                    }

                    Label {
                        id: count_label
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignRight
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                    }

                    Slider {
                        id: count_slider
                        x: 50
                        width: 130
                        height: 22
                        anchors.verticalCenter: parent.verticalCenter
                        activeFocusOnPress: true
                        maximumValue: 25
                        stepSize: 1
                        opacity: 0

                        onValueChanged: {10
                            count_label.text = value
                        }
                    }
                }

                Item {
                    id: row_speed
                    height: 16
                    anchors.top: row_count.bottom
                    anchors.topMargin: -16
                    anchors.rightMargin: 8
                    anchors.leftMargin: 8
                    anchors.right: parent.right
                    anchors.left: parent.left

                    Label {
                        id: label_SPEED
                        text: qsTr("Speed:")
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        anchors.leftMargin: 8
                        anchors.left: parent.left
                    }

                    Label {
                        id: speed_label
                        text: qsTr("0.00")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                    }

                    Slider {
                        id: speed_slider
                        x: 50
                        width: 103
                        height: 22
                        minimumValue: 0.1
                        value: 1
                        maximumValue: 2
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        activeFocusOnPress: true

                        onValueChanged: {
                            speed_label.text = value.toFixed(2)
                        }
                    }
                }

                Item {
                    id: row_fov
                    height: 16
                    anchors.top: row_speed.bottom
                    anchors.topMargin: -16
                    anchors.leftMargin: 8
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    anchors.left: parent.left

                    Label {
                        id: label_FOV
                        text: qsTr("Speed:")
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        anchors.leftMargin: 8
                        anchors.left: parent.left
                    }

                    Label {
                        id: fov_label
                        text: qsTr("60")
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        anchors.rightMargin: 0
                        anchors.right: parent.right
                    }

                    Slider {
                        id: fov_slider
                        x: 50
                        width: 103
                        height: 22
                        stepSize: 1
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        minimumValue: 60
                        value: 60
                        activeFocusOnPress: true
                        maximumValue: 90

                        onValueChanged: {
                            fov_label.text = value
                        }
                    }
                }

                Item {
                    id: row_followtarget
                    x: -8
                    height: 16
                    anchors.top: row_fov.bottom
                    anchors.rightMargin: 8
                    anchors.leftMargin: 8
                    Label {
                        id: label_FOLLOW
                        text: qsTr("Speed:")
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0
                        anchors.leftMargin: 8
                        anchors.left: parent.left
                    }

                    ComboBox {
                        id: comboBox1
                        x: 50
                        width: 130
                        activeFocusOnPress: true
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0

                        model: ListModel {
                            id: follow_target
                            ListElement { text: "Mouse"}
                            ListElement { text: "Point"}
                            ListElement { text: "Track"}
                        }
                    }
                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.topMargin: -16
                }
            }

            Rectangle {
                id: settings_misc
                x: -177
                width: 229
                height: 32
                color: sysPalette.window
                radius: 2
                anchors.top: settings_boid.bottom
                anchors.topMargin: 6
                border.color: sysPalette.mid
                Label {
                    id: label_MISC
                    x: 235
                    y: 8
                    text: qsTr("Miscellaneous")
                }

                MouseArea {
                    id: select_misc
                    anchors.fill: parent
                    enabled: false

                    onClicked: root.state = "MISC_SETTINGS"
                }
                border.width: 1
            }
        }

        MouseArea {
            id: showSettings
            anchors.left: parent.left
            anchors.leftMargin: 242
            anchors.right: parent.right
            hoverEnabled: true
            anchors.bottom: parent.bottom
            anchors.top: parent.top

            onClicked: {
                if(root.state == "") {
                    root.state = oldState
                }
                else {
                    oldState = root.state
                    root.state = ""
                }
            }

            onHoveredChanged: {
                cursorShape = Qt.PointingHandCursor
            }

            Text {
                id: showText
                text: qsTr("Show Settings")
                color: sysPalette.text
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rotation: 270
                font.pixelSize: 12
            }

            Text {
                id: hideText
                text: qsTr("Hide Settings")
                color: sysPalette.text
                anchors.horizontalCenterOffset: -32
                opacity: 0
                rotation: 270
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 12
            }
        }
    }

    Item {
        id: canvas_root
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        anchors.bottomMargin: 2
        anchors.topMargin: 2
        anchors.fill: parent

        Rectangle {
            id: canvas_background
            color: "#ffffff"
            anchors.rightMargin: 2
            anchors.leftMargin: 2
            anchors.bottomMargin: 2
            anchors.topMargin: 2
            anchors.fill: parent
        }
    }

    states: [
        State {
            name: "BOID_SETTINGS"

            PropertyChanges {
                target: settings_root
                x: -24
                anchors.bottomMargin: 0
                anchors.topMargin: 0
            }

            PropertyChanges {
                target: showText
                anchors.horizontalCenterOffset: 32
                opacity: 0
            }

            PropertyChanges {
                target: hideText
                anchors.horizontalCenterOffset: 0
                opacity: 1
            }

            PropertyChanges {
                target: settings_background
            }

            PropertyChanges {
                target: settings_misc
                x: -177
                y: 214
                height: 32
            }

            PropertyChanges {
                target: label_MISC
                x: 235
                y: 8
            }

            PropertyChanges {
                target: select_misc
                enabled: true
            }

            PropertyChanges {
                target: settings_boid
                x: 8
                height: 200
                radius: 1
            }

            PropertyChanges {
                target: label_BOID
                x: 8
                y: 8
                text: qsTr("Boids:")
            }

            PropertyChanges {
                target: count_slider
                width: 130
                anchors.leftMargin: 6
                stepSize: 1
                maximumValue: 25
                opacity: 1
            }

            PropertyChanges {
                target: label_COUNT
                x: 8
                y: 0
                text: qsTr("Count:")
                opacity: 1
            }

            PropertyChanges {
                target: count_label
                x: 144
                y: 0
                height: 16
                horizontalAlignment: Text.AlignRight
                opacity: 1
            }

            PropertyChanges {
                target: row_count
                x: 8
                y: 30
                anchors.rightMargin: 8
                anchors.leftMargin: 8
            }

            PropertyChanges {
                target: row_speed
                y: 52
                anchors.topMargin: 6
                anchors.rightMargin: 8
                anchors.leftMargin: 8
            }

            PropertyChanges {
                target: label_SPEED
                opacity: 1
            }

            PropertyChanges {
                target: speed_slider
                width: 130
                anchors.verticalCenterOffset: 0
                opacity: 1
            }

            PropertyChanges {
                target: speed_label
                opacity: 1
            }

            PropertyChanges {
                target: row_fov
                y: 74
                anchors.topMargin: 6
                anchors.rightMargin: 8
                anchors.leftMargin: 8
            }

            PropertyChanges {
                target: label_FOV
                text: qsTr("FoV:")
                opacity: 1
            }

            PropertyChanges {
                target: fov_slider
                width: 130
                opacity: 1
            }

            PropertyChanges {
                target: fov_label
                opacity: 1
            }

            PropertyChanges {
                target: label_FOLLOW
                text: qsTr("Follow:")
                opacity: 1
            }

            PropertyChanges {
                target: comboBox1
                x: 83
                anchors.verticalCenterOffset: 0
                opacity: 1
            }

            PropertyChanges {
                target: row_followtarget
                anchors.topMargin: 16
            }
        },
        State {
            name: "MISC_SETTINGS"
            PropertyChanges {
                target: settings_root
                x: "-24"
                anchors.bottomMargin: 0
                anchors.topMargin: 0
            }

            PropertyChanges {
                target: showText
                opacity: 0
                anchors.horizontalCenterOffset: 32
            }

            PropertyChanges {
                target: hideText
                opacity: 1
                anchors.horizontalCenterOffset: 0
            }

            PropertyChanges {
                target: select_boid
                enabled: true
            }

            PropertyChanges {
                target: settings_boid
                x: -177
                height: 32
                radius: 2
            }

            PropertyChanges {
                target: label_BOID
                x: 235
                y: 8
            }

            PropertyChanges {
                target: settings_misc
                x: 8
                height: 200
                radius: 1
            }

            PropertyChanges {
                target: label_MISC
                x: 8
                y: 8
            }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation {
                duration: 250
                easing.type: Easing.OutExpo

                properties: {"x, y, height, horizontalCenterOffset"}
            }

            NumberAnimation {
                duration: 250
                easing.type: Easing.InExpo

                properties: {"horizontalCenterOffset"}
            }
        }
    ]
}
