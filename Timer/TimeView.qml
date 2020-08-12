import QtQuick 2.0

Rectangle {
    id: root
    property string time: "Time"
    property color textColor: "black"

    Text {
        id: _timerText
        text: parent.time
        font: {
            bold: true
            //pointSize: Math.min(root.width,root.height)/3
        }
        color: parent.textColor
        anchors.centerIn: parent
    }

}
