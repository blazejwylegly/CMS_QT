import QtQuick 2.12
import QtQuick.Controls 2.12
import assets 1.0
import components 1.0

Item {

    id: loginView
    signal loginClicked(string textField_usr, string textField_pwd);

    signal userLoginSuccessful();
    signal adminLoginSuccessful();

    signal loginSuccessful();
    signal loginFailed();

    objectName: "loginView"

    Connections {
        target: loginController

        onAdminLoginSuccessful: {
            adminLoginSuccessful()
        }

        onUserLoginSuccessful: {
            userLoginSuccessful()
        }

        onLoginFailed: {
            console.log("Failed")
            infoPopup.message = "Login attempt failed!"
            infoPopup.open()
        }
    }


    GroupBox {
        id: loginGroupBox
        anchors.centerIn: parent
        width: 300
        height: 304
        background: Rectangle {
            color: "transparent"
            border.color: "transparent"
        }

        //Username label
        Text {
            id: username_label
            width: 70
            height: 16
            text: qsTr("Username")

            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 95

            font.pixelSize: Style.pixelSizeTextLabel

        //Username input
        }

        TextField {
            id: username_textField

            placeholderText: "Enter username"

            x: 0
            y: 118
            width: 200
            height: 36

            font.pixelSize: Style.pixelSizeTextFieldInput

            background: Rectangle {
                border.width: Style.widthItemBorder
                border.color: Style.colorItemBorder
                radius: Style.radiusItemBorder
            }

        }

        //Password label
        Text {
            id: password_label

            x: 0
            y: 169
            width: 70
            height: 16

            text: qsTr("Password")
            font.pixelSize: Style.pixelSizeTextLabel


        }
        //Password input
        TextField {
            id: password_textInput

            x: 0
            y: 191
            width: 200
            height: 36

            placeholderText: qsTr("Enter password")
            echoMode: TextInput.Password

            font.pixelSize: Style.pixelSizeTextFieldInput

            background: Rectangle {
                border.width: Style.widthItemBorder
                border.color: Style.colorItemBorder
                radius: Style.radiusItemBorder
            }

        }


        Button {
            id: button
            objectName: "proceed_button"
            x: 186
            y: 246
            width: 90
            height: 30

            background: Rectangle {
                border.width: Style.widthItemBorder
                border.color: Style.colorItemBorder
                radius: Style.radiusItemBorder
            }

            text: qsTr("Proceed")
            font.pixelSize: Style.pixelSizeTextFieldInput
            onClicked: {
                loginController.loginButtonClicked(username_textField.text, password_textInput.text)
            }
        }


    }

    InfoPopup {
        id: infoPopup
        anchors.centerIn: parent
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:4;anchors_x:0;anchors_y:96}
}
##^##*/
