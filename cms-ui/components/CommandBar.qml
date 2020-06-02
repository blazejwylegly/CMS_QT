import QtQuick 2.12
import assets 1.0
import QtQuick.Layouts 1.3

Item {
    property alias commandList: commandRepeater.model

    anchors {
        left: parent.left
        bottom: parent.bottom
        right: parent.right
    }

    height: Style.heightCommandBar


    Rectangle {
        anchors.fill: parent
        color: Style.colorCommandBarBackground

        RowLayout {
            id: layout
            layoutDirection: Qt.LeftToRight
            anchors {
                top: parent.top
                bottom: parent.bottom
                right: parent.right
            }
//            CommandButton {
//                command: modelData
//            }

//            ListModel {
//                id: nameModel
//                ListElement { ui_iconCharacter: "0fc7"; ui_description: "Save" }
//                ListElement { ui_iconCharacter: "0fc7"; ui_description: "Save" }
//                ListElement { ui_iconCharacter: "0fc7"; ui_description: "Save" }
//            }

            Repeater {
                model: nameModel
                id: commandRepeater
                delegate: CommandButton {
                    command: modelData
                }
            }

        }
    }

    Component.onCompleted: {
        console.log("Loading command bar completed")
    }

}
