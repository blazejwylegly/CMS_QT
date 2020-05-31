import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.2
import assets 1.0
import components 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Clinic Management System")

    Connections {
        //Creating connection component bound to instance of navigation controller
        //Connections define behaviour of target Class signals
        target: masterController.ui_navigationController

        onGoCreatePatientView:
            contentFrame.replace("qrc:/views/CreatePatientView.qml")

        onGoDashboardView:
            contentFrame.replace("qrc:/views/DashboardView.qml")

        onGoEditPatientView:
            contentFrame.replace("qrc:/views/EditPatientView", {
                                     selectedPatient: patient
                                 })

        onGoFindPatientView:
            contentFrame.replace("qrc:/views/FindPatientView.qml")

    }

    NavigationBar {
        id: navigationBar
    }

    StackView{
        id: contentFrame
        anchors{
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }

        clip: true

        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }


    Component.onCompleted: {
       contentFrame.replace("qrc:/views/LoginView.qml")

    }




}
