import QtQuick 2.12
import QtQuick.Controls 2.13
import assets 1.0


Popup {
    id: popupRoot
    width: 400
    height: 200

    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    property alias message: message.text

    background: Rectangle {
        id: backgroundRectangle
        color: "#7c7c7c"
        anchors.fill: parent

        radius: Style.radiusItemBorder
        border.color: Style.colorItemBorder
        opacity: 0.8
    }
}
