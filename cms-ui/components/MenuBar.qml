import QtQuick 2.12
import QtQuick.Controls 2.12

import assets 1.0
import components 1.0

Item {
    id: root

    objectName: "menu"

    property bool isCollapsed: true
    width: isCollapsed ? Style.widthMenuBarCollapsed : Style.widthMenuBarExpanded

    Rectangle {
        id: rectangle

        color: Style.colorMenuBarBackground

        anchors.fill: parent

        ScrollView {
            id: scrollView

            anchors.fill: parent

            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

            Column {
                id: buttons
                width: rectangle.width

                MenuButton {
                    iconCharacter: "\uf0c9"
                    description: ""
                    hoverColor: "#993333"
                    onMenuButtonClicked: root.isCollapsed = !root.isCollapsed
                }

                MenuBarLabel {
                    id: patientsLabel
                    text: "Patients"
                }

                MenuButton {
                    iconCharacter: "\uf015"
                    description: "Dashboard"
                    onMenuButtonClicked:
                        menuBarController.goDashboardView();
                }
                MenuButton {
                    iconCharacter: "\uf234"
                    description: "New Patient"
                    onMenuButtonClicked:
                        menuBarController.loadPatientAddition();
                }

                MenuButton{
                    iconCharacter: "\uf2b9"
                    description: "Patients register"
                    onMenuButtonClicked:
                        menuBarController.loadPatientsDisplay();
                }

                MenuBarLabel {
                    id: proceduresLabel
                    text: "Procedures"
                }

                MenuBarLabel {
                    id: doctorsLabel
                    text: "Doctors"
                }

                MenuBarLabel {
                    id: accountsLabel
                    text: "Accounts"
                }

        }



        }


    }
}


