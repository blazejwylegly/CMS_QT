import QtQuick 2.12
import QtQuick.Controls 2.13
import assets 1.0

Button {
    property alias textColor: contentText.color
    width: 120
    height: 30
    id: pushButton
    objectName: "pushButton"
    font.family: "Rubik"
    display: AbstractButton.TextOnly
    text: qsTr("Text")
    font.pixelSize: Style.pixelSizeTextLabel

    contentItem: Text {
        id: contentText
        text: pushButton.text
        font: pushButton.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "black"
    }

    background: Rectangle {
        color: pushButton.pressed ? "#b9edfe" : pushButton.hovered ? Style.colorPrimaryTheme : "white"
        border.color: "transparent"
        radius: Style.radiusItemBorder
    }
}
