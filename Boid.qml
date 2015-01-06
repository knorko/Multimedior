import QtQuick 2.0

Rectangle {
    id: rectangle1
    width: 15
    height: 15
    color: "#c5ff2d"
    radius: 8
    border.color: "#78b303"
    border.width: 2

    onColorChanged: border.color = invertColor(color.toString())

    function invertColor(hexTripletColor) {
        var color2 = hexTripletColor;
        color2 = color2.slice(1, 7);
        console.log(color2)
        color2 = parseInt(color2, 16);          // convert to integer
        color2 = 0xFFFFFF ^ color2;             // invert three bytes
        color2 = color2.toString(16);           // convert to hex
        color2 = ("000000" + color2).slice(-6); // pad with leading zeros
        color2 = "#" + color2;                  // prepend #
        return color2;
    }
}
