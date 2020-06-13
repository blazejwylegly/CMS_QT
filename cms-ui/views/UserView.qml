import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import components 1.0
import tabs 1.0
import assets 1.0
Item {
    id: root
    objectName: "userView"
    visible: true

    width: parent.width
    height: parent.height

    signal logOut()

    StackView {
           id: contentFrame
           anchors.top: parent.top
           anchors.topMargin: 0
           anchors.bottom: parent.bottom
           anchors.bottomMargin: 0
           anchors.right: parent.right
           anchors.rightMargin: 0
           anchors.left: parent.left
           anchors.leftMargin: 30

           initialItem: patientAddition
    }


//    NavigationBar {
//        id: navigationBar
//    }


    PatientAddition {
        id: patientAddition

        height: contentFrame.height
        width: contentFrame.width

        visible: true
    }

//    Rectangle {
//        anchors.fill: contentFrame
//        color: Style.colorBackground
//        Text {
//            anchors.centerIn: parent
//            text: "user view"
//        }
//    }

    ListModel {
        id: menuModel
        ListElement {
            buttonText: "Add Patient"
            buttonIcon: ""
        }
    }

}
