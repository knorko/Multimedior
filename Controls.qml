import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    property int count: 5

    property int size: 10

    signal changeRunning(bool value)
    onChangeRunning: {
        if(value) {
            background.state = "PLAYBACK"
        }
        else {
            background.state = ""
        }
    }

    id: background
    width: 150
    height: 39
    color: sysPalette.dark
    radius: 4
    border.color: sysPalette.mid

    Behavior on opacity { NumberAnimation{ duration: 350; easing.type: Easing.InExpo} }


    MouseArea {
        id: showArea
        enabled: false
        anchors.bottomMargin: -8
        hoverEnabled: true
        anchors.rightMargin: -8
        anchors.leftMargin: -8
        anchors.topMargin: -8
        anchors.fill: parent

        onEntered: background.opacity = 1.0
        onExited: background.opacity = 0.1

        Button {
            id: startButton
            x: 16
            y: 16
            height: 23
            text: "Start"
            enabled: true
            opacity: 1
            anchors.rightMargin: 16
            anchors.leftMargin: 16
            anchors.right: parent.right
            anchors.left: parent.left

            onClicked: {
                init(count, size)
                running = true
            }
        }

        Button {
            id: pauseButton
            x: 16
            y: 16
            width: 64
            text: "Pause"
            enabled: false
            opacity: 0
            checkable: true

            onCheckedChanged: pause(checked)
        }

        Button {
            id: stopButton
            x: 86
            y: 16
            width: 64
            text: "Stop"
            enabled: false
            opacity: 0

            onClicked: {
                pauseButton.checked = false;
                pauseButton.enabled = false;
                running = false;
            }
        }

    }
    states: [
        State {
            name: "PLAYBACK"

            PropertyChanges {
                target: showArea
                enabled: true
            }

            PropertyChanges {
                target: background
                opacity: 0.1
            }

            PropertyChanges {
                target: pauseButton
                enabled: true
                opacity: 1
            }

            PropertyChanges {
                target: startButton
                enabled: true
                opacity: 0
            }

            PropertyChanges {
                target: stopButton
                opacity: 1
                enabled: true
            }
        }
    ]
}
