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

        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        transformOrigin: Item.Center

        border.width: 0
        border.color: "#eeeeee"
    }

    ScrollView {
        id: scrollView
        transformOrigin: Item.Center

        anchors.top: topMask.bottom

        anchors.bottom: bottomMask.top

        anchors.right: parent.right

        anchors.left: parent.left

        anchors.margins: 20

        width: parent.width

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff


        Column {

            id: inputsColumn

            width: scrollView.width

            spacing: 15
            transformOrigin: Item.Center

            StyledInput {
                id: firstNameInput

                height: 80

                width: parent.width

                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin:5

                placeholder: "first name"
                titleText: "First Name"

            }

            StyledInput {
                id: secondNameInput
                height: 80

                width: parent.width

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

                width: parent.width

                anchors.left: parent.left
                anchors.leftMargin: 5

                anchors.right: parent.right
                anchors.rightMargin: 5

                placeholder: "surname"
                titleText: "Surname"
            }

            StyledInput {
                id: peselInput
                transformOrigin: Item.Center

                width: parent.width

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

                width: parent.width

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
        id: topMask
        color: background.color
        height: 80
        anchors.right: parent.right
        anchors.left: parent.left
    }


    Rectangle {
        id: bottomMask
        color: background.color
        height: 80
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
    }

    Text {
        id: tabTitle

        x: 302
        y: 33
        width: 300
        height: 60

        anchors.top: parent.top
        anchors.topMargin: 20

        anchors.right: parent.right
        anchors.rightMargin: 20

        color: "#393e46"
        text: "Patients addition"
        anchors.verticalCenter: topMask.verticalCenter

        font.family: "Verdana"

        font.weight: Font.Medium

        font.pixelSize: 30

        verticalAlignment: Text.AlignVCenter
    }

    PushButton {
        id: addButton
        y: 11351

        objectName: "addButton"

        anchors.bottom: bottomMask.bottom
        anchors.bottomMargin: 20

        anchors.top: bottomMask.top
        anchors.topMargin: 20

        anchors.right: scrollView.right

        height: 40
        width: 120

        font.family: "Verdana"
        text: qsTr("Add Patient")

        display: AbstractButton.TextOnly

        onClicked: {
            patientAdditionRequested(firstNameInput.inputText, secondNameInput.inputText, surnameInput.inputText, peselInput.inputText, docIdInput.inputText);
        }
    }

    InfoPopup {
        id: popup
        anchors.centerIn: parent
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
