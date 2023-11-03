import QtQuick 2.15
import QtQuick.Controls

import "qrc:/scripts/Colors.js" as Colors
import "../custom_components"
import Managers

Item {

    DescriptionWindowManager {
        id: desc

        onDisplay: loader.active = true

        Component.onCompleted: LogManager.setDescWindowManager(desc)
    }

    Rectangle {
        anchors.fill: parent
        color: Colors.DarkSegment

        Loader {
            id: loader
            anchors.fill: parent
            sourceComponent: component
            active: false
        }

        Component {
            id: component
            DescriptionPage {
                anchors.fill: parent
            }
        }
    }
}
//
