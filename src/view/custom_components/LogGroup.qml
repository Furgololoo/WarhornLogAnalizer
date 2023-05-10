import QtQuick 2.15

import "qrc:/scripts/Colors.js" as Colors
import "qrc:/scripts/Fonts.js" as Fonts

Item {
    id: root

    property color rectColor: "green"
    property string mainText: "unnamed"
    property string type: "Unknown"
    property int count: 0
    property bool isExpanded: false
    property int initialHeight: 35
    property int componentHeight: 125

    height: initialHeight

    Rectangle {
        id: mainRect
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        width: parent.width * 0.94
        height: initialHeight
        color: rectColor
        opacity: 0.95

        Image {
            id: icon
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: 30

            source: "qrc:/icons/more.png"
        }

        Text {
            id: mainTextLabel
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: icon.right
            anchors.right: parent.right
            anchors.leftMargin: 20
            anchors.rightMargin: parent.width * 0.25
            verticalAlignment: Text.AlignVCenter

            elide: Text.ElideRight
            font: Fonts.getFont(14, true, false)
            color: Colors.DarkSegment
            text: mainText
        }

        Text {
            id: countLabel
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 20
            verticalAlignment: Text.AlignVCenter
            font: Fonts.getFont(14, true, false)
            color: Colors.DarkSegment
            text: count
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                if(!isExpanded) {
                    icon.source = "qrc:/icons/less.png"
                    let list = listComponent.createObject(listItem)
                    let arr = LogManager.getGameplayLogsTitle(root.type)

                    if(arr.length < 4)
                        root.componentHeight = 25 * arr.length + 4 * (arr.length-1)
                    else
                        root.componentHeight = 125

                    root.height = componentHeight + initialHeight + 6
                    console.log(root.height)

                    listItem.children[0].setLogsArray(arr)
                }
                else {
                    icon.source = "qrc:/icons/more.png"
                    root.height = initialHeight
                    listItem.children[0].destroy()
                }
                isExpanded = !isExpanded
            }
        }
    }

    Item {
        id: listItem
        width: parent.width * 0.94
        anchors.right: mainRect.right
        anchors.top: mainRect.bottom
        anchors.topMargin: 5
        anchors.bottom: root.bottom
    }

    Component {
        id: listComponent
        LogList {
            id: logList
            width: listItem.width
            height: componentHeight
            logColor: rectColor
        }
    }

}
