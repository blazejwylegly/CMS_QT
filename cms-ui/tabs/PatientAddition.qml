import QtQuick 2.0
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.14
import components 1.0
import assets 1.0

Item {
    id: rootElement
    objectName: "patientAddition"
    visible: true

    Connections {
        target: patientAdditionController
        onAdditionSuccessful: {
            popup.message = "Addition successful!"
            popup.open();
        }

        onAdditionFailed: {
            popup.message = "Addition failed!"
            popup.open();
        }

        onInvalidInput: {
            popup.message = "Invalid inputs provided!"
            popup.open();

        }
    }

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

        anchors.top: tabTitle.bottom
        anchors.topMargin: 20

        anchors.bottom: addButton.top

        anchors.left: parent.left
        anchors.leftMargin: 20

        anchors.right: parent.right
        anchors.rightMargin: 20

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

    PushButton {
        id: addButton

        objectName: "addButton"

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        anchors.right: scrollView.right
        anchors.rightMargin: 5

        width: 120
        height: 40

        font.family: "Verdana"
        text: qsTr("Add Patient")
        font.pointSize: 10

        display: AbstractButton.TextOnly

        onClicked: {
            patientAdditionRequested(firstNameInput.inputText, secondNameInput.inputText, surnameInput.inputText, peselInput.inputText, docIdInput.inputText);
        }
    }

    Text {
        id: tabTitle

        x: 0
        y: 33
        width: 212
        height: 43

        anchors.top: parent.top
        anchors.topMargin: 30

        anchors.left: parent.left
        anchors.leftMargin: 30

        color: "#393e46"
        text: "Patients addition"
        font.family: "Verdana"

        font.weight: Font.Medium

        font.pixelSize: 30

        verticalAlignment: Text.AlignVCenter
    }

    InfoPopup {
        id: popup
        anchors.centerIn: parent
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.8999999761581421;height:480;width:640}
}
##^##*/
