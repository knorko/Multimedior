import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
     SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    id: rectangle1
    width: 15
    height: 15
    color: "#f0f0f0"





    states: [
        State {
            name: "VISIBLE"

            PropertyChanges {
                target: rectangle1
                width: 150
                height: 150
                color: "#f0f0f0"
                visible: true
            }

            PropertyChanges {
                target: easterBox1
                x: 19
                y: 25
                width: 113
                height: 101
                title: qsTr("Eastereggs :")
                visible: true
                flat: false
                checked: false
                opacity: 1
            }

            PropertyChanges {
                target: easterComboBox1
                x: 0
                y: 26
                width: 97
                height: 20
                anchors.rightMargin: 0
                opacity: 1
            }
        }
    ]
    visible: true

    GroupBox {
        id: easterBox1
        x: -135
        y: -40
        width: 360
        height: 300
        title: qsTr("Group Box")
        opacity: 0

        ComboBox {
            id: easterComboBox1
            x: -165
            y: -15
            opacity: 0

            model: ListModel {
                id: globalTarget
                ListElement { text: "Boring Mode";   }
                ListElement { text: "Awesome Mode"; }
            }
        }

    }
}
