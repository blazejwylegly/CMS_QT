import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import assets 1.0
import CMS 1.0

Item {
    id: patientsList
    objectName: "patientsList"
    visible: true

    Connections{
        target: patientsModel
        onNothingFound: {
            console.log("Nothing found")
        }
    }

    Connections {
        target: patientAdditionController
        onAdditionSuccessful: {
            reload();
        }

    }

    PatientsListModel {
        id: patientsModel
    }

    function reload() {
        patientsModel.clear();
        patientsModel.update();
    }

    function filterModel(searchText){
        patientsModel.doSearch(searchText)
    }

    function show() {
        if(list.contentItem.children.length > 0) {
            visible = true;
        }
    }

    Component.onCompleted: {
        show();
    }


    ListView {
        id: list
        orientation: ListView.Vertical
        ScrollBar.vertical: ScrollBar { id: scrollBar }

        spacing: 20

        anchors.fill: parent

        anchors.margins: 30
        anchors.bottomMargin: 20


        clip: true

        model: patientsModel

        delegate: Rectangle {

            id: listItem

            states: [

                State {
                    name: "hover"
                    PropertyChanges {
                        target: listItem
                        color: Style.colorPrimaryTheme

                    }
                }

            ]

            color: Style.colorItemBackground
            border.color: "transparent"

            radius: Style.radiusItemBorder

            height: 60
            width: parent.width

            anchors.left: parent.left
            anchors.leftMargin: 10

            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: dataText
                anchors.top: listItem.top
                anchors.left: parent.left
                anchors.right: parent.right

                anchors.topMargin: 10
                anchors.leftMargin: 20
                anchors.rightMargin: 20

                height: 30
                font.pixelSize: 14

                font.family: "Verdana"

                color: "black"

                text: model.name + "\n" + model.pesel
                wrapMode: Text.WrapAnywhere
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: listItem.state = "hover"
                onExited: listItem.state = ""
            }


        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:4;anchors_width:640}
}
##^##*/
