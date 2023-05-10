import QtQuick

import "qrc:/scripts/Colors.js" as Colors
import "pages/"

Window {
    width: 1080
    height: 680
    visible: true
    title: qsTr("The Warhorn Log Analizer")
    color: Colors.MainBGDark

    ManageWindow {
        id: manageWindow
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        anchors.leftMargin: 8
        anchors.rightMargin: 8
        anchors.topMargin: 8

        height: 75
    }

    LogExplorer {
        id: logExplorer
        anchors.left: parent.left
        anchors.top: manageWindow.bottom
        anchors.bottom: parent.bottom

        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        anchors.topMargin: 8

        width: 250
    }

    DescriptionWindow {
        id: descriptionWindow
        anchors.left: logExplorer.right
        anchors.right: parent.right
        anchors.top: manageWindow.bottom
        anchors.bottom: parent.bottom

        anchors.leftMargin: 8
        anchors.rightMargin: 8
        anchors.topMargin: 8
        anchors.bottomMargin: 8
    }

}
