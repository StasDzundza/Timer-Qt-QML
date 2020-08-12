import QtQuick 2.0

Column {
    id: _buttonsColumn
    property int buttonWidth: 0
    property int buttonHeight: 0

    Button{
        property string curText: "Start"
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "green"
        internalText : curText


        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(parent.curText === "Start"){
                    parent.curText = "Pause";
                    parent.color = "red"
                }else{
                    parent.curText = "Start";
                    parent.color = "green"
                }
            }
        }
    }

    Button{
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "orange"
        internalText: "Tap"
    }

    Button{
        id: _resetButton
        property bool isEnabled: true
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "lightblue"
        internalText : "Reset"
        enabled: isEnabled
    }

    Button{
        property bool isEnabled: true
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "purple"
        internalText: "Load timer data"
        enabled: isEnabled
    }

    Button{
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "brown"
        internalText: "Save current time"
    }
}
