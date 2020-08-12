import QtQuick 2.0

Rectangle {

    property string internalText: ""
    radius: 5

    Text {
        id: valueText
        text: parent.internalText
        font.bold: true
        //font.pointSize: Math.min(root.width,root.height)/3
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.border.width = 1;
            parent.border.color = "yellow"
        }
        onExited:  {
            parent.border.color = "transparent"
            parent.border.width = 0
        }
    }
}
