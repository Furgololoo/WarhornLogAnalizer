import QtQuick 2.15

import "qrc:/scripts/Colors.js" as Colors
import "../custom_components"

Item {

    Rectangle {
        anchors.fill: parent
        color: Colors.DarkSegment

        Column {
            width: parent.width
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.topMargin: 8
            anchors.bottomMargin: 8
            spacing: 4

            Repeater {
                id: repeater
                LogGroup {
                    mainText: modelData.title
                    type: modelData.type
                    count: modelData.count
                    rectColor: logTypeToColor(modelData.type)
                    width: parent.width
                    initialHeight: 35
                }
            }
        }

        Connections {
            target: LogAnalizer
            function onEndRead() {
                repeater.model = LogManager.getGameplayShortcut()
            }
        }
    }

    function logTypeToColor(logType: string) {
        switch(logType) {
        case "Warhorn_FatalError": return Colors.Red;
        case "Warhorn_Error": return Colors.Orange;
        case "Warhorn_Warning": return Colors.Yellow;
        case "Warhorn_Info": return Colors.Green;
        }
    }
}
