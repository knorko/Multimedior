import QtQuick 2.1
import QtQuick.Window 2.0

Window {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

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
    }
}
