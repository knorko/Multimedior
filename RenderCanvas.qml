import QtQuick 2.0

Item {
    id: canvas_root
    objectName: "canvas"
    height: 200
    width: 200

Rectangle {
    id: canvas_background
    color: "#ffffff"
    anchors.rightMargin: 1
    anchors.leftMargin: 1
    anchors.bottomMargin: 1
    anchors.topMargin: 1
    anchors.fill: parent
    border.width: 0
}

}
