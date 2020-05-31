import QtQuick 2.12
import assets 1.0
import components 1.0

Item {

    Rectangle {
        anchors.fill: parent
        color: Style.colorBackground
        Text {
            anchors.centerIn: parent
            text: "Create patient view"
        }
    }

    CommandBar {
        commandList: masterController.ui_commandController.ui_createPatientViewContextCommands


    }

}

