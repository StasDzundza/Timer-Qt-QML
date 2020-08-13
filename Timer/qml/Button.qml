import QtQuick 2.0

Rectangle {
    property string buttonText: ""
    radius: 10
    color: enabled ? "white":"#c0c4c1"

    Text {
        id: valueText
        text: parent.buttonText
        font.bold: true
        font.pointSize: Math.min(parent.width,parent.height) / 4
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.border.width = 2;
            parent.border.color = "black"
        }
        onExited:  {
            parent.border.color = "transparent"
            parent.border.width = 0
        }
    }
}
