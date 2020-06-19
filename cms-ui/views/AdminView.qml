import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import components 1.0
import tabs 1.0
import assets 1.0

Item {
    id: root
    objectName: "adminView"
    visible: true

    signal logOut()

    Connections {
        //Creating connections component bound to instance of MenuBarController
        //These connections define behaviour for signals sent by target Class
        target: menuBarController
        onGoDashboardView: {
            contentFrame.replace("qrc:/")
        }

        onLoadPatientAddition: {
            contentFrame.replace(patientAddition)
        }

        onLoadPatientsDisplay: {
            contentFrame.replace(patientsDisplay)
        }

    }

    MenuBar {
        id: menuBar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors {
            top: parent.top
            left: parent.left
        }
    }


    StackView {

        id: contentFrame
        height: parent.height
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: menuBar.right
        anchors.leftMargin: 0


        initialItem: patientsDisplay

        PatientAddition {
            id: patientAddition

            height: parent.height
            width: parent.width

            visible: false
        }

        PatientsDisplay {
            id: patientsDisplay

            height: parent.height
            width: parent.width

            visible: false
        }

    }





}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}D{i:2;anchors_height:700;anchors_width:700;anchors_y:0}
}
##^##*/
