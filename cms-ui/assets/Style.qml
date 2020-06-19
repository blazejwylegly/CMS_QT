pragma Singleton
import QtQuick 2.12

Item {

    readonly property color colorPrimaryTheme: "#35acfe"
    readonly property color colorSecondaryTheme: "#051aa5"
    readonly property color colorBackground: "#ececec"

    //Initializing fonts
    readonly property FontLoader fontAwesomeSolid: FontLoader {
        source: "qrc:/assets/fa-solid.ttf"
    }
    readonly property FontLoader fontAwesomeRegular: FontLoader {
        source: "qrc:/assets/fa-regular.ttf"
    }
    readonly property FontLoader fontAwesomeBrands: FontLoader {
        source: "qrc:/assets/fa-brands.ttf"
    }

    //Fonts
    readonly property string regular: fontAwesomeRegular.name
    readonly property string brands: fontAwesomeBrands.name
    readonly property string solid: fontAwesomeSolid.name

    //Menu bar properties
    readonly property color colorMenuBarBackground: "#efefef"
    readonly property color colorMenuBarFont: "#000000"
    readonly property int pixelSizeMenuBarIcon: 36
    readonly property int pixelSizeMenuBarText: 12

    //Menu button icon properties
    readonly property real widthMenuButtonIcon: 80
    readonly property real heightMenuButtonIcon: widthMenuButtonIcon

    //Menu button description properties
    readonly property real widthMenuButtonDescription: 100
    readonly property real heightMenuButtonDescription: heightMenuButtonIcon

    //Menu button properties
    readonly property real widthMenuButton: widthMenuButtonDescription +
                                                  widthMenuButtonIcon
    readonly property real heightMenuButton: Math.max(heightMenuButtonIcon,
                                                            heightMenuButtonDescription)
    //Menu bar label properties
    readonly property real heightMenuButtonLabel: heightMenuButton

    readonly property real pixelSizeMenuButtonLabel: 16

    //Collapsed menu sizing
    readonly property real widthMenuBarCollapsed: widthMenuButtonIcon
    readonly property real widthMenuBarExpanded: widthMenuButton

//    Command buttons color properties
//    readonly property color colorCommandBarBackground: "#cecece"
//    readonly property color colorCommandBarFont: "#131313"
//    readonly property color colorCommandBarFontDisabled: "#636363"

//    Command bar size properties
//    readonly property real heightCommandBar: heightCommandButton
//    readonly property int pixelSizeCommandBarIcon: 32
//    readonly property int pixelSizeCommandBarText: 12

//    Command button size properties
//    readonly property real widthCommandButton: 80
//    readonly property real heightCommandButton: widthCommandButton

    //TextFields and Controlls colorProperites
    readonly property color colorItemBorder: "#a1c9d9"
    readonly property color colorItemBackground: "white"

    //TextFields and Buttons text styling properties
    readonly property int pixelSizeTextFieldInput: 12
    readonly property int pixelSizeTextLabel: 12

    //TextFields and Controlls shaping properties
    readonly property int widthItemBorder: 2
    readonly property int radiusItemBorder: 20



}
