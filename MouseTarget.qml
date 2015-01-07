import QtQuick 2.0

Item {
    id: item1
    width: 48
    height: 48

    Rectangle {
        id: rectangle1
        x: 17
        y: 17
        width: 32
        height: 32
        color: "#00000000"
        border.color: "#80ff0909"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        rotation: 45
        border.width: 2
    }
}

