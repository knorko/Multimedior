import QtQuick 2.0
import QtQuick.Controls 1.2

Item {
    x: 0
    y: 0
    width: 200
    height: 122



    Boid {
        id: boid_preview
        x: 84
        y: 84
        width: 32
        height: 32
        radius: 16
        rad: 0
        border.width: 5
    }

    Item {
        id: color_red
        height: 22
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        Label {
            id: label_R
            y: 3
            text: qsTr("R:")
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.verticalCenter: parent.verticalCenter
        }

        Text {
            id: label_currentred
            x: 160
            y: 28
            text: qsTr("0.50")
            horizontalAlignment: Text.AlignRight
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        Slider {
            id: slider_red
            x: 18
            width: 150
            stepSize: 0
            value: 0.5
            maximumValue: 1

            onValueChanged: {
                label_currentred.text = value.toFixed(2)
                boid_preview.color = Qt.rgba(value, slider_green.value, slider_blue.value, 1)
                boid_preview.border.color = Qt.rgba(1-value, 1-slider_green.value, 1-slider_blue.value, 1)
                management.setColor(boid_preview.color, boid_preview.border.color)
            }
        }

    }

    Item {
        id: color_green
        height: 22
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: color_red.bottom
        anchors.topMargin: 6

        Label {
            id: label_G
            y: 37
            text: qsTr("G:")
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Text {
            id: label_currentgreen
            x: 160
            y: 36
            text: "1.00"
            horizontalAlignment: Text.AlignRight
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        Slider {
            id: slider_green
            x: 18
            width: 150
            value: 1
            stepSize: 0
            maximumValue: 1

            onValueChanged: {
                label_currentgreen.text = value.toFixed(2)
                boid_preview.color = Qt.rgba(slider_red.value, value, slider_blue.value, 1)
                boid_preview.border.color = Qt.rgba(1-slider_red.value, 1-value, 1-slider_blue.value, 1)
                management.setColor(boid_preview.color, boid_preview.border.color)
            }
        }
    }

    Item {
        id: color_blue
        height: 22
        anchors.top: color_green.bottom
        anchors.topMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        Label {
            id: label_B
            x: 0
            y: 3
            text: qsTr("B:")
        }

        Text {
            id: label_currentblue
            x: 160
            text: "0.25"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 12
        }

        Slider {
            id: slider_blue
            x: 18
            width: 150
            value: 0.25
            stepSize: 0
            maximumValue: 1

            onValueChanged: {
                label_currentblue.text = value.toFixed(2)
                boid_preview.color = Qt.rgba(slider_red.value,slider_green.value,value,1)
                boid_preview.border.color = Qt.rgba(1-slider_red.value,1-slider_green.value,1-value,1)
                management.setColor(boid_preview.color, boid_preview.border.color)
            }
        }
    }

}
