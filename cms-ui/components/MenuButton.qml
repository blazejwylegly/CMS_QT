import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.2
import assets 1.0

Item {

    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text
    property color hoverColor: Style.colorMenuBarBackground

    signal menuButtonClicked()

    width: parent.width
    height: Style.heightMenuButton

    Rectangle {
        id: background
        color: Style.colorMenuBarBackground
        anchors.fill: parent
        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: Style.colorPrimaryTheme
                }
            }

        ]

        Row {
            //Button character
            Text {
                id: textIcon

                width: Style.widthMenuButtonIcon
                height: Style.heightMenuButtonIcon

                font {
                    family: Style.solid
                    pixelSize: Style.pixelSizeMenuBarIcon
                }

                color: Style.colorMenuBarFont

                text: "\uf11a"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            //Button description
            Text {
                id: textDescription

                width: Style.widthMenuButtonDescription
                height: Style.heightMenuButtonDescription

                font.pixelSize: Style.pixelSizeMenuBarText
                color: Style.colorMenuBarFont

                text: "Text unset"
                verticalAlignment: Text.AlignVCenter
            }
        }

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: menuButtonClicked()
        }

    }




}

