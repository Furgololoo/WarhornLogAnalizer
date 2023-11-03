import QtQuick 2.15

import "qrc:/scripts/Colors.js" as Colors

Item {

    //property string

    Item {
        id: header
        Text {
            id: name
            width: 200
            height: 75
        }
    }

    Item {
        id: content

    }

    Rectangle {
        width: 30
        height: 30
        color: Colors.Red
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 5
        anchors.rightMargin: 5

        Image {
            id: closeImg
            anchors.fill: parent
            source: "qrc:/icons/close.png"
        }
    }

}
