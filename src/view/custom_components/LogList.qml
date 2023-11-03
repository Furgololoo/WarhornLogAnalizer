import QtQuick 2.15
import QtQuick.Controls

import "qrc:/scripts/Colors.js" as Colors

Item {
    id: root
    property color logColor: "white"

    function setLogsArray(arr) {
        repeater.model = arr
    }

    signal openDescriptionWindow(index: int)

    Rectangle {
        id: scrollRect
        anchors.fill: parent
        color: Colors.DarkSegment

        ScrollBar_C {
            id: scrollBar
            height: flickable.height
            width: parent.width * 0.08
            anchors.top: parent.top
            anchors.right: parent.right

            onMoveToBegin: {
                flickable.contentY = 0
            }

            onMoveToEnd: {
                flickable.contentY = column.implicitHeight - flickable.height
            }

            onMoved: (value) => {
                         flickable.contentY += value
                     }
        }
    }

    Flickable {
        id: flickable
        height: parent.height
        width: parent.width * 0.92
        anchors.top: parent.top
        anchors.left: parent.left
        contentHeight: column.implicitHeight
        contentWidth: parent.width * 0.9

        boundsBehavior: Flickable.StopAtBounds
        interactive: true
        clip: true

        onContentYChanged: scrollBar.moveSlider(flickable.contentY)

        Column {
            id: column
            anchors.fill : parent
            spacing: 4

            onImplicitHeightChanged: {
                // console.log("column implicitHeight: " + column.implicitHeight)
                // console.log("        column height: " + flickable.height)
                if(column.implicitHeight === flickable.height) {
                    scrollBar.disableScrollBar()
                    flickable.width = root.width
                    flickable.contentWidth = root.width
                }
                else
                    scrollBar.setHandleSize(column.implicitHeight / flickable.height)
            }

            Repeater {
                id: repeater
                anchors.fill: parent

                LogEntry {
                    mainText: modelData.title
                    rectColor: logColor
                    width: parent.width
                    height: 25
                    onOpenDescriptionWindow: root.openDescriptionWindow(index)
                }
            }
        }
    }

}
