import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle{
    x: 0
    y: 0
    width: 192
    height: 227
    color: "#f0f0f0"

    Slider {
        id: slider_red
        x: 47
        y: 23
        width: 100
        height: 22
        stepSize: 0
        value: 0
        maximumValue: 1

        onValueChanged: {
            label_currentred.text = value.toFixed(2)
            boid_preview.color = Qt.rgba(value,slider_green.value,slider_blue.value,1)
            boid_preview.border.color = Qt.rgba(1-slider_red.value,1-slider_green.value,1-value,1)
            management.setColor(boid_preview.color, boid_preview.border.color)
        }
    }

    Slider {
        id: slider_green
        x: 47
        y: 60
        width: 100
        value: 1
        stepSize: 0
        maximumValue: 1

        onValueChanged: {
            label_currentgreen.text = value.toFixed(2)
            boid_preview.color = Qt.rgba(slider_red.value, value, slider_blue.value,1)
            boid_preview.border.color = Qt.rgba(1-slider_red.value,1-slider_green.value,1-value,1)
            management.setColor(boid_preview.color, boid_preview.border.color)
        }
    }

    Slider {
        id: slider_blue
        x: 47
        y: 99
        width: 100
        value: 0
        stepSize: 0
        maximumValue: 1

        onValueChanged: {
            label_currentblue.text = value.toFixed(2)
            boid_preview.color = Qt.rgba(slider_red.value,slider_green.value,value,1)
            boid_preview.border.color = Qt.rgba(1-slider_red.value,1-slider_green.value,1-value,1)
            management.setColor(boid_preview.color, boid_preview.border.color)
        }
    }

    Label {
        id: label_red
        x: 9
        y: 28
        text: qsTr("Red:")
    }

    Label {
        id: label_green
        x: 9
        y: 65
        text: qsTr("Green:")
    }

    Label {
        id: label_blue
        x: 9
        y: 104
        text: qsTr("Blue:")
    }

    Label {
        id: label_preview
        x: 2
        y: 165
        width: 48
        height: 17
        text: qsTr("Preview")
    }

    Rectangle {
        id: rectangle1
        x: 42
        y: 127
        width: 107
        height: 93
        color: "#ffffff"
    }

    Boid {
        id: boid_preview
        x: 69
        y: 148
        width: 54
        height: 52
        radius: 26
    }

    Text {
        id: label_currentred
        x: 160
        y: 28
        text: qsTr("0")
        font.pixelSize: 12
    }

    Text {
        id: label_currentgreen
        x: 160
        y: 64
        text: "0"
        font.pixelSize: 12
    }

    Text {
        id: label_currentblue
        x: 160
        y: 104
        text: "0"
        font.pixelSize: 12
    }

}
