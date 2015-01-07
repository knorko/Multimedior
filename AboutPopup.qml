import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2

Window {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    id: mypopDialog
    title: "About"
    width: 579
    height: 444
    flags: Qt.Dialog
    modality: Qt.WindowModal
    color: sysPalette.window

GroupBox {
    id: mult_license
    height: 370
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.rightMargin: 2
    anchors.leftMargin: 2
    anchors.topMargin: 2
    title: qsTr("Multimedior:")

    Text {
        id: text_MIT
        color: sysPalette.text

        text: "The MIT License (MIT)

Copyright (c) 2015 Nils Gerrit Riklef Gesinn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the \"Software\"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE."
        anchors.fill: parent


        font.pixelSize: 12
    }
}

GroupBox {
    id: thrd_license
    height: 37
    anchors.left: parent.left
    anchors.leftMargin: 2
    anchors.right: parent.right
    anchors.rightMargin: 2
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 2
    anchors.top: mult_license.bottom
    anchors.topMargin: 6
    title: qsTr("Third party libraries:")

    Text {
        id: license_kdtree
        color: sysPalette.text
        text: "Qt by Qt Project: http://qt-project.org/
kdtree library by John Tsiombikas: https://code.google.com/p/kdtree/"

        anchors.fill: parent
        font.pixelSize: 12
    }
}

}
