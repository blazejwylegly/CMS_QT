import QtQuick 2.12
import QtQuick.Controls 2.12

import assets 1.0

Item {
    id: rootElement
    objectName: "dashboardView"
    width: parent.width
    height: parent.height

    visible: true

    Rectangle {
        id: background

        anchors.fill: parent
        color: "white"
    }

    Text{
        id: mainLabel

        anchors.centerIn: parent

        color: "#393e46"
        text: "Welcome to Clinic Management System!"
        font.family: "Verdana"

        font.weight: Font.Medium

        font.pixelSize: 30

        verticalAlignment: Text.AlignVCenter

    }

    Text {
        x: 130
        font.family: Style.solid
        text: "\uf7f2"
        anchors.topMargin: 15

        font.pixelSize: 100
        width: 100
        height: 100

        anchors.top: mainLabel.bottom
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
