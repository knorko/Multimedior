import QtQuick 2.0

Rectangle {
    property real rad: 10

    onRadChanged: {
        awarenessRadius.height = rad
        awarenessRadius.width = rad
    }

    id: rectangle1
    width: 15
    height: 15
    color: "#c6ff2e"
    radius: 8
    z: 1
    border.color: "#77b300"
    border.width: 2

    Rectangle {
        id: awarenessRadius
        x: -92
        y: -92
        width: 50
        height: 50
        color: "#00000000"
        radius: 25
        border.width: 1
        border.color: "#f5ce00"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        z: -1

        onWidthChanged: radius = width / 2
    }
}
