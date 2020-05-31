import QtQuick 2.12
import assets 1.0
import components 1.0

Item {
    id: root
    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    property bool isCollapsed: true

    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.widthNavigationBarExpanded

    Rectangle {
        color: Style.colorNavigationBarBackground
        anchors.fill: parent

        Column {
            id: buttons
            width: parent.width
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColor: "#993333"
                onNavigationButtonClicked: root.isCollapsed = !root.isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                hoverColor: "#dc8a00"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goDashboardView();
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Patient"
                hoverColor: "#dccd00"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goCreatePatientView();
            }
            NavigationButton{
                iconCharacter: "\uf002"
                description: "Find Patient"
                hoverColor: "#8aef63"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goFindPatientView()

            }

        }


    }
}


