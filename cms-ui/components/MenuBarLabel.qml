import QtQuick 2.12
import assets 1.0
import components 1.0

Rectangle {

    property alias text: labelText.text
    property alias textColor: labelText.color

    id: accountsLabel

    height: Style.heightMenuButtonLabel
    width: parent.width
    
    color: Style.colorMenuBarBackground
    
    Text {

        id: labelText
        text: "Label"
        color: Style.colorMenuBarFont

        anchors.centerIn: parent

        font.pixelSize: Style.pixelSizeMenuButtonLabel
        
    }
}
