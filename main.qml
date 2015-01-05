import QtQuick 2.1
import QtQuick.Window 2.0

Window {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    property int oldMaxHeight: 0
    property int oldMaxWidth: 0

    property int boidHeight: 10
    property int boidWidth: 10

    property bool running: false
    onRunningChanged: {
        settingsPanel1.changeRunning(running)
        controls1.changeRunning(running)

        if(running) {
            oldMaxHeight = maximumHeight
            oldMaxWidth = maximumWidth
            minimumHeight = height
            minimumWidth = width
            maximumHeight = height
            maximumWidth = width

            updateTick.start()
        }
        else {
            minimumHeight = 480
            minimumWidth = 640
            maximumHeight = oldMaxHeight
            maximumWidth = oldMaxWidth

            updateTick.stop()
            management.clear()
        }
    }

    signal init(int boidCount, int predatorCount, int size)
    onInit: {
        management.init(boidCount, predatorCount, size)
    }

    signal pause(bool pause)
    onPause: {
        if(running) {
            if(pause) {
                updateTick.paused = true
                updateTick.stop()
            }
            else {
                updateTick.paused = false
                updateTick.start()
            }
        }
    }


    id: root
    objectName: "rootWindow"
    visible: true
    height: 480
    width: 640
    minimumHeight: 480
    minimumWidth: 640
    color: sysPalette.window

    SettingsPanel {
        id: settingsPanel1
        x: 4
        y: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 2
        anchors.top: parent.top
        anchors.topMargin: 2
    }

    Rectangle {
        id: background
        color: sysPalette.window
        radius: 4
        border.color: sysPalette.mid
        anchors.rightMargin: 2
        anchors.leftMargin: 22
        anchors.bottomMargin: 2
        anchors.topMargin: 2
        anchors.fill: parent

        RenderCanvas {
            id: renderCanvas1
            anchors.rightMargin: 2
            anchors.leftMargin: 2
            anchors.bottomMargin: 2
            anchors.topMargin: 2
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: parent.top
        }

        Controls {
            id: controls1
            x: 217
            y: 429
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
        }
    }

    Timer {
        id: updateTick
        interval: 16

        property bool paused: false

        onTriggered: {
            if(!paused) {
                var startTime = Date.now()
                management.run()

                startTime = (16 - (Date.now() - startTime))
                if(startTime < 1)
                    startTime = 1

                interval = startTime
                start()
            }
        }
    }
}
