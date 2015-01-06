import QtQuick 2.0

Rectangle {
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
}
