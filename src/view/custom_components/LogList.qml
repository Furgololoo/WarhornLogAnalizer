import QtQuick 2.15
import QtQuick.Controls

import "qrc:/scripts/Colors.js" as Colors

Item {
    property color logColor: "white"

    function setLogsArray(arr) {
        repeater.model = arr
    }

    Rectangle {
        anchors.fill: parent
        color: Colors.DarkSegment

        ScrollBar_C {
            id: scrollBar
            height: flickable.height
            width: parent.width * 0.08
            anchors.top: parent.top
            anchors.right: parent.right
        }
    }

    Flickable {
        id: flickable
        height: parent.height
        width: parent.width * 0.92
        contentHeight: column.implicitHeight
        contentWidth: parent.width * 0.9
        anchors.top: parent.top
        anchors.left: parent.left

        boundsBehavior: Flickable.StopAtBounds
        interactive: true
        clip: true

        Column {
            id: column
            anchors.fill : parent
            spacing: 4

            Repeater {
                id: repeater
                anchors.fill: parent
                LogEntry {
                    mainText: modelData.title
                    rectColor: logColor
                    width: parent.width
                    height: 25
                }
            }

        }
    }

}
