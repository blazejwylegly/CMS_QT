import QtQuick 2.12
import CMS 1.0
import assets 1.0

Item {
    property Command command
    property alias commandButtonDescriptionText: textDescription.text
    property alias commandButtonIconText: textIcon.text


    width: Style.widthCommandButton
    height: Style.heightCommandButton

    Rectangle {
        width: Style.widthCommandButton
        height: Style.heightCommandButton

        id: background
        anchors.fill: parent
        color: Style.colorCommandBarBackground

        //Command button icon
        Text {
            id: textIcon

            anchors {
                centerIn: parent
                verticalCenterOffset: -10
            }
            font {
                family: Style.fontAwesomeSolid
                pixelSize: Style.pixelSizeCommandBarIcon
            }

            color: command.ui_canExecute ? Style.colorCommandBarFont : Style.colorCommandBarFontDisabled

            text: command.ui_iconCharacter
            horizontalAlignment: Text.AlignHCenter
        }

        //Command button description
        Text {
            id: textDescription

            anchors {
                top: textIcon.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }

            font.pixelSize: Style.pixelSizeNavigationBarText

            color: command.ui_canExecute ? Style.colorCommandBarFont : Style.colorCommandBarFontDisabled
            text: command.ui_description
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: if(command.ui_canExecute) {
                           command.executed();
                       }
        }

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: Qt.darker(Style.colorCommandBarBackground)
                }
            }

        ]
    }

    Component.onCompleted: {
        console.log("Loading command button completed");
    }

}
