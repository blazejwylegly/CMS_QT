import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import assets 1.0

ToolBar {

    id: root
    objectName: "searchBar"

    property bool busyIndicatorRunning : false
    property bool searchBarVisbile: true


    signal doSearch(string searchText)
//    signal searchTextChanged(string searchText)
//    signal showCategories()
    signal goBack()
    signal showMap()

    onSearchBarVisbileChanged: {
        searchBar.opacity = searchBarVisbile ? 1 : 0
        backBar.opacity = searchBarVisbile ? 0 : 1
    }

//    function showSearch(text) {
//        if (text !== null) {
//            searchText.ignoreTextChange = true
//            searchText.text = text
//            searchText.ignoreTextChange = false
//        }
//    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colorBackground
    }


    RowLayout {
        id: searchBar

        anchors.fill: parent
        width: parent.width

        Behavior on opacity { NumberAnimation{} }
        visible: opacity ? true : false

        TextField {

            id: searchText
            Behavior on opacity { NumberAnimation{} }
            visible: opacity ? true : false
            property bool ignoreTextChange: false
            transformOrigin: Item.Center

            placeholderText: qsTr("Enter surname ...")
            placeholderTextColor: Style.colorPrimaryTheme

            Layout.fillWidth: true
            Layout.fillHeight: true

//            onTextChanged: {
//                if (!ignoreTextChange)
//                    searchTextChanged(text)
//            }
            onAccepted: doSearch(searchText.text)
        }


        PushButton {

            id: searchButton
            font {
                family: Style.solid
                pixelSize: 14
            }

            text: "\uf002"
            onClicked: doSearch(searchText.text)
        }


    }

    RowLayout {
        id: backBar
        width: parent.width
        height: parent.height
        opacity: 0
        Behavior on opacity { NumberAnimation{} }
        visible: opacity ? true : false
        ToolButton {
            id: backButton
            onClicked: goBack()
        }
        ToolButton {
            id: mapButton
            onClicked: showMap()
        }
        Item {
             Layout.fillWidth: true
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
