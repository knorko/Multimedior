import QtQuick 2.0

Item {
    id: canvas_root
    objectName: "canvas"
    height: 200
    width: 200

    property bool continuous: false
    onContinuousChanged: mouseArea1.hoverEnabled = continuous

    Rectangle {
        id: canvas_background
        color: "#ffffff"
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        anchors.bottomMargin: 1
        anchors.topMargin: 1
        anchors.fill: parent
        border.width: 0

        onHeightChanged: {
            management.setCanvasHeight(height)
        }
        onWidthChanged: {
            management.setCanvasWidth(width)
        }
    }

    MouseArea {
        id: mouseArea1
        hoverEnabled: true
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if(!continuous){
                if(mouse.button == Qt.LeftButton)
                    management.setMousePosition(mouseX, mouseY)
                else
                    management.setMousePosition(0, 0)
            }
        }

        onPositionChanged: {
            if(continuous)
                management.setMousePosition(mouseX, mouseY)
        }

        onExited: {
            if(continuous)
                management.setMousePosition(0, 0)
        }
    }
}
