import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 15
    height: 15
    radius: 8
    color: "#ff2d2d"
    border.color: "#b30303"
    border.width: 2

    Rectangle {
        id: rectangle2
        x: -230
        y: -92
        width: 17
        height: 17
        color: "#00000000"
        radius: 0
        border.color: "#80ed0000"
        border.width: 2
        rotation: 45
        z: -1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
