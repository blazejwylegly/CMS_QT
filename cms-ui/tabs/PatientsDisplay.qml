import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

import assets 1.0
import components 1.0
import CMS 1.0


Item {
    id: patientsDisplay
    objectName: "patientsDisplay"

    signal deleteButtonClicked(int itemIndex);
    signal editButtonClicked(int itemIndex);

    visible: true

    Rectangle{
        id: background

        anchors.fill: parent
        color: Style.colorBackground
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
    }

    Text {
        id: tabTitle

        x: 0
        y: 33
        width: 99
        height: 25

        anchors.top: parent.top
        anchors.topMargin: 30

        anchors.left: parent.left
        anchors.leftMargin: 30

        color: "#393e46"
        text: "Patients register"
        font.family: "Verdana"

        font.weight: Font.Medium

        font.pixelSize: 30

        verticalAlignment: Text.AlignVCenter
    }

    SearchBar {
        id: searchBar
        objectName: "searchBar"
        width: parent.width

        anchors.top: tabTitle.bottom
        anchors.topMargin: 20

        anchors.right: parent.right
        anchors.rightMargin: 30

        anchors.left: parent.left
        anchors.leftMargin: 30

        onDoSearch: {
            //When search button (search bar component) is clicked
            //list filtering method gets called
            list.filterModel(searchText)
        }
    }

    PatientsList {
        id: list

        anchors.top: searchBar.bottom
        anchors.bottom: buttonsRow.top

        width: parent.width
        height: parent.height

        anchors.leftMargin: 10
        anchors.rightMargin: 10

    }


    Row {
        id: buttonsRow
        x: 25

        height: 70

        spacing: 20

        anchors.left: searchBar.left
        anchors.leftMargin: 10

        anchors.right: searchBar.right
        anchors.rightMargin: 10

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        layoutDirection: Qt.RightToLeft

        PushButton {
            id: editButton
            objectName: "editButton"

            width: 120
            height: 40

            font.family: "Verdana"
            text: qsTr("Edit Patient")
            font.pointSize: 10

            display: AbstractButton.TextOnly

            onClicked: {
                editButtonClicked(list.selectedItem);
            }

        }

        PushButton {
            id: deleteButton
            objectName: "deleteButton"

            width: 120
            height: 40

            font.family: "Verdana"
            text: qsTr("Delete Patient")
            font.pointSize: 10

            display: AbstractButton.TextOnly

            onClicked: {
                list.deleteCurrentItem();
            }
        }

    }



}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5;anchors_y:434}
}
##^##*/
