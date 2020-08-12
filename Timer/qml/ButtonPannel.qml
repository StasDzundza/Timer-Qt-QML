import QtQuick 2.0
import Timers 1.0

Column {
    id: _buttonsColumn
    property int buttonWidth: 0
    property int buttonHeight: 0

    Timer{
        id: _timer
        onTimeLeftTextChanged: {
            console.log(timeLeftText)
        }

        onTimeout: {
            _startPauseButton.color = "green";
            _startPauseButton.curText = "Start"
        }

        onIsActiveChanged: {
            //set enabled buttons(load, reset, tap)
        }
    }

    Button{
        id: _startPauseButton
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
                _timer.turnOnOf()
            }
        }
    }

    Button{
        id: _tapButton
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
        id: _loadButton
        property bool isEnabled: true
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "purple"
        internalText: "Load timer data"
        enabled: isEnabled

        MouseArea{
            anchors.fill: parent
            onClicked: {
                _timer.loadTime();
            }
        }
    }

    Button{
        id: _saveButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "brown"
        internalText: "Save current time"
    }
}
