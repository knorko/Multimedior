import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    id: background
    width: 150
    height: 39
    color: sysPalette.dark
    radius: 4
    opacity: 0.1
    border.color: sysPalette.mid

    Behavior on opacity { NumberAnimation { easing.type: Easing.InQuint}}

    MouseArea {
        id: showArea
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
            y: 16
            width: 64
            text: "Start"
            anchors.left: parent.left
            anchors.leftMargin: 16
            //        enabled: false
            anchors.top: parent.top
            anchors.topMargin: 16

            onClicked: {
                if(updateTick.running || pauseButton.checked) {
                    pauseButton.checked = false
                    updateTick.stop()
                    pauseButton.enabled = false
                    text = "Start"
                }
                else {
                    updateTick.restart()
                    pauseButton.enabled = true
                    text = "Stop"
                }
        }
    }

        Button {
            id: pauseButton
            x: 99
            y: 16
            width: 64
            text: "Pause"
            anchors.right: parent.right
            anchors.rightMargin: 16
            anchors.top: parent.top
            anchors.topMargin: 16
            checkable: true

            onCheckedChanged: updateTick.running = !checked
        }
//        onHoveredChanged: background.opacity = containsMouse ? 1 : 0.1
    }
}
