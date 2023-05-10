import QtQuick 2.15
import QtQuick.Controls
import CustomElements

import "qrc:/scripts/Colors.js" as Colors
import "../custom_components"

Item {

    Rectangle {
        anchors.fill: parent
        color: Colors.DarkSegment


        Item {
            anchors.top: parent.top
            anchors.left: parent.left
            width: 250
            height: 300

            Rectangle {
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
                contentHeight: column.implicitHeight
                contentWidth: parent.width * 0.9
                anchors.top: parent.top
                anchors.left: parent.left

                boundsBehavior: Flickable.StopAtBounds
                interactive: true
                clip: true

                onContentYChanged: scrollBar.moveSlider(flickable.contentY)

                Column {
                    id: column
                    anchors.fill : parent
                    spacing: 4

                    Component.onCompleted: {
                        console.log("column implicitHeight: " + column.implicitHeight)
                        console.log("        column height: " + flickable.height)
                        scrollBar.setHandleSize(column.implicitHeight / flickable.height)
                    }

                    Repeater {
                        id: repeater
                        anchors.fill: parent
                        model: 61
                        Rectangle {
                            color: "red"
                            width: parent.width
                            height: 25
                        }
                    }

                }
            }


        }
    }
}
