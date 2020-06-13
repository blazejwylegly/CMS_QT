import QtQuick 2.0
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.14
import components 1.0
import assets 1.0

Item {
    id: rootElement
    objectName: "patientAddition"
    visible: true

    anchors.fill: parent

    signal patientAdditionRequested(string firstName, string secondName, string surname, string pesel, int docId);

    Rectangle {
        id: background
        color: "#eeeeee"
        border.width: 0
        border.color: "#eeeeee"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }


    ScrollView {
        id: scrollView
        rightPadding: 10

        anchors.top: parent.top
        anchors.topMargin: 108

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 28

        anchors.left: parent.left
        anchors.leftMargin: 49

        anchors.right: parent.right
        anchors.rightMargin: 37

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff


        Column {

            id: inputsColumn
            spacing: 15
            width: scrollView.width



            StyledInput {
                id: firstNameInput
                height: 80

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin: 5

                placeholder: "first name"
                titleText: "First Name"

            }

            StyledInput {
                id: secondNameInput
                height: 80

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin:5

                placeholder: "second name"
                titleText: "Second name"
            }

            StyledInput {
                id: surnameInput
                height: 80

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin: 5

                placeholder: "surname"
                titleText: "Surname"
            }

            StyledInput {
                id: peselInput

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin: 5

                placeholder: "pesel number"
                titleText: "Pesel number"
            }

            StyledInput {
                id: docIdInput
                height: 80

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin: 5

                placeholder: "doctor in charge"
                titleText: "Doctor in charge"
            }

        }

    }

    Rectangle {
        id: scrollViewMaskBottom
        x: 0
        y: 624
        color: background.color

        anchors.top: scrollView.bottom
        anchors.topMargin: 0

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        anchors.left: parent.left
        anchors.leftMargin: 0

        anchors.right: parent.right
        anchors.rightMargin: 0
    }

    Rectangle {

        id: scrollViewMaskTop
        x: 4
        y: -4
        color: background.color

        anchors.top: parent.top
        anchors.topMargin: 0

        anchors.bottom: scrollView.top
        anchors.bottomMargin: 0

        anchors.right: parent.right
        anchors.rightMargin: 0

        anchors.left: parent.left
        anchors.leftMargin: 0

    }

    PushButton {
        id: addButton

        objectName: "addButton"

        anchors.top: parent.top
        anchors.topMargin: 25


        anchors.right: scrollView.right
        anchors.rightMargin: 5

        width: 120
        height: 40

        font.family: "Verdana"
        text: qsTr("Add Patient")
        font.pointSize: 10

        display: AbstractButton.TextOnly

        onClicked: {
            console.log("Button clicked")
            patientAdditionRequested(firstNameInput.inputText, secondNameInput.inputText, surnameInput.inputText, peselInput.inputText, docIdInput.inputText);
        }
    }

}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.8999999761581421;height:480;width:640}
}
##^##*/
