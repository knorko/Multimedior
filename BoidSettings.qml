import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 100
    height: 62
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: rectangle1
                height: 106
            }
        }
    ]
}
