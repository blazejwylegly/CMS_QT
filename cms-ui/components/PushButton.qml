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
    contentItem: Text {
        id: contentText
        text: pushButton.text
        font: pushButton.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "black"
    }
    background: Rectangle {
        color: pushButton.pressed ? "#b9edfe" : pushButton.hovered ? "#b1ebfd" : "white"
        border.color: Style.colorItemBorder
        radius: 25
    }
}
