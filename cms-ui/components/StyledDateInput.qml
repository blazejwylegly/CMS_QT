
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

StyledInput{
    id: dateInput
    placeholder: "01.01.1990"
    inputMask: "99.99.9999;0"
}
