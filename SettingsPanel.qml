import QtQuick 2.0

Item {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    id: settings_root
    width: 260
    height: 480
    z: 1

    Rectangle {
        id: settings_background
        color: sysPalette.window
        border.color: sysPalette.mid
        radius: 4
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        BoidSettings {
            id: boidSettings1
            x: 8
            y: 8

            MouseArea {
                id: select_boidsettings
                enabled: true
                anchors.fill: parent

                onClicked: {
                    boidSettings1.state = "VISIBLE"
                    predatorSettings1.state = ""
                    miscSettings1.state = ""
                    select_predatorsettings.enabled = true
                    select_miscsettings.enabled = true
                    enabled = false
                }
            }
        }

        MiscSettings {
            id: miscSettings1
            x: 8
            anchors.top: predatorSettings1.bottom
            anchors.topMargin: 6

            MouseArea {
                id: select_miscsettings
                anchors.fill: parent

                onClicked: {
                    boidSettings1.state = ""
                    predatorSettings1.state = ""
                    miscSettings1.state = "VISIBLE"
                    select_boidsettings.enabled = true
                    select_predatorsettings.enabled = true
                    enabled = false
                }
            }
        }

        PredatorSettings {
            id: predatorSettings1
            x: 8
            anchors.top: boidSettings1.bottom
            anchors.topMargin: 6

            MouseArea {
                id: select_predatorsettings
                anchors.fill: parent

                onClicked: {
                    boidSettings1.state = ""
                    predatorSettings1.state = "VISIBLE"
                    miscSettings1.state = ""
                    select_boidsettings.enabled = true
                    select_miscsettings.enabled = true
                    enabled = false
                }
            }
        }
    }

    MouseArea {
        id: showSettings
        x: 242
        width: 18
        anchors.rightMargin: -260
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.right: settings_background.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top

        hoverEnabled: true

        onClicked: {
            settings_root.state = (settings_root.state == "") ? "HIDDEN" : ""
        }

        onHoveredChanged: cursorShape = Qt.PointingHandCursor

        Text {
            id: hideText
            x: -179
            y: 232
            text: qsTr("Hide Settings")
            color: sysPalette.text
            rotation: 270
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        Text {
            id: showText
            x: -150
            y: 232
            text: qsTr("Show Settings")
            anchors.horizontalCenterOffset: 32
            opacity: 0
            color: sysPalette.text
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            rotation: 270
            font.pixelSize: 12
        }
    }


    states: [
        State {
            name: "HIDDEN"

            PropertyChanges {
                target: hideText
                anchors.horizontalCenterOffset: -32
                opacity: 0
            }

            PropertyChanges {
                target: settings_root
                x: -242
            }

            PropertyChanges {
                target: showText
                anchors.horizontalCenterOffset: 0
                anchors.verticalCenterOffset: 0
                opacity: 1
            }
        }
    ]

    transitions: [
        Transition {
            SequentialAnimation {
                NumberAnimation {
                    easing.type: Easing.OutExpo
                    properties: {"x, height"}
                }

                NumberAnimation {
                    duration: 300
                    easing.type: Easing.OutExpo
                    properties: {"horizontalCenterOffset, opacity"}
                }
            }
        }
    ]
}
