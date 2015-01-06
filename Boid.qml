import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 15
    height: 15
    color: "#c5ff2d"
    radius: 8
    states: [
        State {
            name: "Awesome"

            PropertyChanges {
                target: rectangle1
                color: "#382dff"
                border.color: "#0316b3"
            }
        }
    ]
    border.color: "#78b303"
    border.width: 2

    Behavior on color {ColorAnimation { duration: 2000 }}
}
