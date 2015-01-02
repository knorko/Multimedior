import QtQuick 2.0

Item {
    id: canvas_root
    objectName: "canvas"
    height: 200
    width: 200

    property bool continuous: false
    onChildrenChanged: mouseArea1.hoverEnabled = continuous

    Rectangle {
        id: canvas_background
        color: "#ffffff"
        anchors.rightMargin: 1
        anchors.leftMargin: 1
        anchors.bottomMargin: 1
        anchors.topMargin: 1
        anchors.fill: parent
        border.width: 0

        property bool rdy: false

        Component.onCompleted: rdy = true

        onHeightChanged: {
            if(rdy)
                management.setCanvasHeight(height)
        }
        onWidthChanged: {
            if(rdy)
                management.setCanvasWidth(width)
        }
    }

    MouseArea {
        id: mouseArea1
        hoverEnabled: true
        anchors.fill: parent

        onClicked: {
            if(!continuous)
                management.setMousePosition(mouseX, mouseY)
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
