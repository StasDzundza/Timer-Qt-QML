import QtQuick 2.0
import Timers 1.0

Column {
    id: _buttonsColumn
    property int buttonWidth: 0
    property int buttonHeight: 0
    property alias timerTarger: _timer.target

    Timer{
        id: _timer
        property TimeView target: null

        onTimeLeftTextChanged: {
            sendTimeValue(timeLeftText)
        }

        onTimeout: {
            _startPauseButton.color = "green";
            _startPauseButton.curText = "Start"
        }

        onIsActiveChanged: {
            if(isActive === true){
                _resetButton.enabled = false;
                _loadButton.enabled = false;
                _tapButton.enabled = true;
            }else{
                _resetButton.enabled = true;
                _loadButton.enabled = true;
                _tapButton.enabled = false;
            }
        }

        signal sendTimeValue(string value)
        onTargetChanged: sendTimeValue.connect(target.receiveTime)
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
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "lightblue"
        internalText : "Reset"
        enabled: true

        MouseArea{
            anchors.fill: parent
            onClicked: _timer.reset()
        }
    }

    Button{
        id: _loadButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "purple"
        internalText: "Load timer data"
        enabled: true

        MouseArea{
            anchors.fill: parent
            onClicked: _timer.loadTime();

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
