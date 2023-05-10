import QtCore
import QtQuick
import QtQuick.Dialogs

import "qrc:/scripts/Colors.js" as Colors

Item {

    Rectangle {
        anchors.fill: parent
        color: Colors.DarkSegment

        MouseArea {
            anchors.fill: parent

            onClicked: {
                fileDialog.open()
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Choose Log File"
        // currentFolder: StandardPaths.standardLocations(StandardPaths.DownloadLocation)[0]
        currentFolder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        onAccepted: FileManager.openFile(selectedFile)
    }
}
