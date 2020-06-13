import QtQuick 2.12
import QtQuick.Controls 2.13
import assets 1.0


Popup {
    id: popupRoot
    width: 400
    height: 200

    modal: true
    focus: true

    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    property alias message: message.text

    background: Rectangle {
        id: backgroundRectangle

        anchors.fill: parent


        border.color: Style.colorItemBorder
        color: "#7a7a7a"

        opacity: 0.8
        radius: Style.radiusItemBorder


        Button {
            id: button

            x: 371
            width: 23
            height: 21

            text: qsTr("\uf00d")
            font.family: Style.regular

            contentItem: Text {
                text: button.text

                font.pointSize: 12
                font.family: "Verdana"

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

                color: message.color
            }

            anchors.top: parent.top
            anchors.topMargin: 4

            anchors.right: parent.right
            anchors.rightMargin: 6

            background: Rectangle {
                color: "transparent"
            }

            onClicked: popupRoot.close()
        }
    }

    contentItem: Text {
        id: message
        x: 24
        y: 47
        color: "#eeeeee"
        text: qsTr("Description")

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        anchors.top: parent.top
        anchors.topMargin: 20

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        anchors.right: parent.right
        anchors.rightMargin: 20

        anchors.left: parent.left
        anchors.leftMargin: 20

        wrapMode: Text.WordWrap

        font.family: "Rubik"
        font.pixelSize: Style.pixelSizeTextLabel
    }
}
