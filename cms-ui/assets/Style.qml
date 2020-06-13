pragma Singleton
import QtQuick 2.12

Item {

    readonly property color colorBackground: "#efefef"

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

    //Navigation bar properties
    readonly property color colorNavigationBarBackground: "#000000"
    readonly property color colorNavigationBarFont: "#ffffff"
    readonly property int pixelSizeNavigationBarIcon: 42
    readonly property int pixelSizeNavigationBarText: 22

    //Navigation button icon properties
    readonly property real widthNavigationButtonIcon: 80
    readonly property real heightNavigationButtonIcon: widthNavigationButtonIcon

    //Navigation button description properties
    readonly property real widthNavigationButtonDescription: 160
    readonly property real heightNavigationButtonDescription: heightNavigationButtonIcon

    //Navigation button properties
    readonly property real widthNavigationButton: widthNavigationButtonDescription +
                                                  widthNavigationButtonIcon
    readonly property real heightNavigationButton: Math.max(heightNavigationButtonIcon,
                                                            heightNavigationButtonDescription)
    //Collapsed menu sizing
    readonly property real widthNavigationBarCollapsed: widthNavigationButtonIcon
    readonly property real widthNavigationBarExpanded: widthNavigationButton

    //Command buttons color properties
    readonly property color colorCommandBarBackground: "#cecece"
    readonly property color colorCommandBarFont: "#131313"
    readonly property color colorCommandBarFontDisabled: "#636363"

    //Command bar size properties
    readonly property real heightCommandBar: heightCommandButton
    readonly property int pixelSizeCommandBarIcon: 32
    readonly property int pixelSizeCommandBarText: 12

    //Command button size properties
    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton

    //TextFields and Controlls colorProperites
    readonly property color colorItemBorder: "#65d1d1"

    //TextFields and Buttons text styling properties
    readonly property int pixelSizeTextFieldInput: 12
    readonly property int pixelSizeTextLabel: 18

    //TextFields and Controlls shaping properties
    readonly property int widthItemBorder: 2
    readonly property int radiusItemBorder: 20
}
