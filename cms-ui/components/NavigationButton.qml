import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.2
import assets 1.0

Item {

    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text
    property color hoverColor: Style.colorNavigationBarBackground

    signal navigationButtonClicked()

    width: parent.width
    height: Style.heightNavigationButton

    Rectangle {
        id: background
        color: Style.colorNavigationBarBackground
        anchors.fill: parent
        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColor
                }
            }

        ]

        Row {
            //Button character
            Text {
                id: textIcon

                width: Style.widthNavigationButtonIcon
                height: Style.heightNavigationButtonIcon

                font {
                    family: Style.solid
                    pixelSize: Style.pixelSizeNavigationBarIcon
                }

                color: Style.colorNavigationBarFont

                text: "\uf11a"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            //Button description
            Text {
                id: textDescription

                width: Style.widthNavigationButtonDescription
                height: Style.heightNavigationButtonDescription

                font.pixelSize: Style.pixelSizeNavigationBarText
                color: Style.colorNavigationBarFont

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
            onClicked: navigationButtonClicked()
        }

    }




}

