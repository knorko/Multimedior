import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
     SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    id: rectangle1
    width: 150
    height: 150
    color: "#f0f0f0"
    visible: true

    GroupBox {
        id: easterBox1
        x: 13
        y: 12
        width: 125
        height: 126

        ComboBox {
            id: easterComboBox1
            x: -5
            y: 38
            width: 114
            height: 20

            model: ListModel {
                id: globalTarget2
                ListElement { text: "Boring Mode"; property string value: "Awesome" }
                ListElement { text: "Awesome Mode"; property string value: "" }
            }

            onCurrentIndexChanged: {
                management.setState(globalTarget2.get(currentIndex).value)
            }
        }

    }
}
