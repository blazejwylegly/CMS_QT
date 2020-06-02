import QtQuick 2.12
import QtQuick.Controls 2.12
import assets 1.0
import CMS 1.0

Item {

    id: loginView
    signal loginClicked(string textField_usr, string textField_pwd);
    signal loginSuccessful();

    anchors.centerIn: parent

    objectName: "loginView"

    Connections {
        target: loginController
        onLoginSuccessful : {
            loginSuccessful()
        }
        onLoginFailed: {console.log("Failed") }
    }


    GroupBox {
        id: loginGroupBox
        anchors.centerIn: parent
        width: 300
        height: 300

        //Username
        Text {
            id: username_label
            x: 0
            y: 96
            width: 70
            height: 16
            text: qsTr("Username")
            font.pixelSize: 12

        }

        TextField {
            id: username_textField

            placeholderText: "Enter username"

            x: 0
            y: 118
            width: 200
            height: 36

            background: Rectangle {
                border.width: 2
                border.color: "#00ffff"
                radius: 20
            }

        }

        //Password
        Text {
            id: password_label

            x: 0
            y: 169
            width: 70
            height: 16

            text: qsTr("Password")
            font.pixelSize: 12


        }

        TextField {
            id: password_textInput

            x: 0
            y: 191
            width: 200
            height: 36

            placeholderText: qsTr("Enter password")
            echoMode: TextInput.Password
            passwordCharacter: "*"
            font.pixelSize: 12

            background: Rectangle {
                border.width: 2
                border.color: "#00eeee"
                radius: 20
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
                border.width: 2
                border.color: "#00ffff"
                radius: 20
            }

            text: qsTr("Proceed")

            onClicked: {
                loginController.loginButtonClicked(username_textField.text, password_textInput.text)
            }
        }




    }

}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
