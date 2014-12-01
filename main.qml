import QtQuick 2.1
import QtQuick.Window 2.0

Window {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    objectName: "rootWindow"

    visible: true
    height: 480
    width: 640
    minimumHeight: 480
    minimumWidth: 640

    color: sysPalette.window

    Component.onCompleted: {
        var rootWindow = Qt.createComponent("rootWindow.qml")
        rootWindow.createObject(this, {"sysPalette": sysPalette})
    }
}
