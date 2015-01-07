import QtQuick 2.0

Rectangle {
    property bool visualizeRadius: false
    onVisualizeRadiusChanged: awarenessRadius.opacity = visualizeRadius ? 1.0 : 0.0

    property real rad: 10

    onRadChanged: {
        awarenessRadius.height = rad
        awarenessRadius.width = rad
    }

    id: rectangle1
    width: 7
    height: 7
    color: "#c5ff2d"
    radius: 4
    border.color: "#78b303"
    border.width: 2

    onWidthChanged: radius = width * 0.5
    onColorChanged: invertBorder()

    // Sets border color to the inverted main color
    function invertBorder() {
        var mainColor = color.toString();
        mainColor = mainColor.slice(1, 7);              // Remove leading #
        mainColor = parseInt(mainColor, 16);            // Convert to int
        mainColor = 0xFFFFFF ^ mainColor;               // Invert 3 bytes
        mainColor = mainColor.toString(16);             // Convert to hex
        mainColor = ("000000" + mainColor).slice(-6);   // Pad with leading zeros
        mainColor = "#" + mainColor;
        border.color = mainColor;
    }

    Rectangle {
        id: awarenessRadius
        x: -92
        y: -92
        width: 50
        height: 50
        color: "#00000000"
        radius: 25
        opacity: 0
        border.width: 1
        border.color: "#805ff500"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        z: -1

        onWidthChanged: radius = width * 0.5

        Behavior on opacity { NumberAnimation { duration: 750;  easing.type: Easing.OutExpo} }
    }
}
