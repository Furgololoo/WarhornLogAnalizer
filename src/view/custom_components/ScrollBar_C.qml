import QtQuick 2.15

import "qrc:/scripts/Colors.js" as Colors

Item {
    id: root

    property real minHandleSize: 8
    property real handleSize: 8
    property real ratio: 0

    function setHandleSize(_ratio) {
        ratio = _ratio
        if(background.height / _ratio < minHandleSize)
            handleSize = minHandleSize
        else
            handleSize = background.height / _ratio
    }

    function moveSlider(yVal) {
        handle.y = yVal / ratio
    }

    function disableScrollBar() {
        root.width = 0
    }

    signal moved(value: real)
    signal moveToEnd()
    signal moveToBegin()

    Rectangle {
        id: background
        anchors.fill: parent
        color: Colors.MainBGDark
        radius: width / 4

        Rectangle {
            id: handle
            anchors.horizontalCenter: parent.horizontalCenter
            y: 0
            width: parent.width * 0.9
            height: handleSize

            radius: width / 4
            color: Colors.MainAccent

            MouseArea{
                anchors.fill: parent

                property real firstPoint: 0

                onPressed: firstPoint = mouseY

                onMouseYChanged: {
                    let yVal =  mouseY - firstPoint

                    if(handle.y + yVal <= 0) {
                        handle.y = 0
                        moveToBegin()
                    }
                    else if(handle.y + yVal >= background.height - handle.height) {
                        handle.y = background.height - handle.height
                        moveToEnd()
                    }
                    else {
                        handle.y += yVal
                        moved(yVal * ratio)
                    }
                }
            }
        }
    }
}
