import QtQuick 2.0

Rectangle {
    id: root
    property string time: "Time"
    property color textColor: "black"
    border.color: "black"
    border.width: 2

    Text {
        id: _timerText
        text: parent.time
        color: parent.textColor
        anchors.centerIn: parent
        font.pointSize: Math.min(parent.width,parent.height)/6
        wrapMode:Text.WordWrap
    }

    function receiveTime(value){
        time = value
    }
}
