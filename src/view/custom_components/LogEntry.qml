import QtQuick 2.15

import "qrc:/scripts/Colors.js" as Colors
import "qrc:/scripts/Fonts.js" as Fonts

Item {
    id: root

    property color rectColor: "white"
    property string mainText: "unnamed"

    signal openDescriptionWindow()

    Rectangle {
        id: mainRect
        anchors.fill: parent
        color: rectColor
        opacity: 0.95

        Text {
            id: mainTextLabel
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            verticalAlignment: Text.AlignVCenter

            elide: Text.ElideRight
            font: Fonts.getFont(11, false, false)
            color: Colors.DarkSegment
            text: mainText
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                openDescriptionWindow()
            }
        }
    }
}
