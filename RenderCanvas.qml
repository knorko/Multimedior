import QtQuick 2.0

Item {
    id: canvas_root
    objectName: "canvas"
    height: 200
    width: 200

    property bool continuous: false
    onContinuousChanged: {
        mouseArea1.hoverEnabled = continuous
        mouseTarget1.opacity = continuous ? 0.0 : 1.0
    }

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
                if(mouse.button == Qt.LeftButton) {
                    management.setMousePosition(mouseX, mouseY)
                    mouseTarget1.x = mouseX - 24
                    mouseTarget1.y = mouseY - 24
                    mouseTarget1.opacity = 1.0
                }
                else {
                    management.setMousePosition(0, 0)
                    mouseTarget1.opacity = 0.0
                }
            }
        }

        onPositionChanged: {
            if(continuous) management.setMousePosition(mouseX, mouseY)
        }

        onExited: {
            if(continuous) management.setMousePosition(0, 0)
        }

        MouseTarget {
            id: mouseTarget1
            x: 76
            y: 76
            opacity: 0

            Behavior on opacity { NumberAnimation { duration: 750; easing.type: Easing.OutExpo } }
        }
    }
}
