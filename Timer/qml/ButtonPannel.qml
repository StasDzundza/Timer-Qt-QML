import QtQuick 2.12
import QtQuick.Dialogs 1.2
import Timer 1.0

Column {
    id: _buttonsColumn
    property int buttonWidth: 0
    property int buttonHeight: 0
    property alias textView: _timer.timeViewTarget
    property TimeMomentsView timeMomentsViewTarget: null

    signal sendTimeMoment(string value)
    signal clearTimeMoments()
    onTimeMomentsViewTargetChanged: {
        clearTimeMoments.connect(timeMomentsViewTarget.clearModel)
        sendTimeMoment.connect(timeMomentsViewTarget.addTimeMoment)
    }

    Timer{
        id: _timer
        property TimeView timeViewTarget: null

        onTimeLeftTextChanged: {
            sendTimeValue(timeLeftText)
        }

        onTimeout: {
            _startPauseButton.color = "green";
            _startPauseButton.curText = "Start"
        }

        signal sendTimeValue(string value)
        onTimeViewTargetChanged: sendTimeValue.connect(timeViewTarget.receiveTime)
    }

    Button{
        id: _startPauseButton
        property string curText: "Start"
        width: parent.buttonWidth
        height: parent.buttonHeight
        color: "green"
        buttonText : curText

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
        buttonText: "Tap"
        enabled: _timer.isActive

        MouseArea{
            anchors.fill: parent
            onClicked: sendTimeMoment(_timer.timeLeftText)
        }
    }

    Button{
        id: _resetButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        buttonText : "Reset"
        enabled: !_timer.isActive

        MouseArea{
            anchors.fill: parent
            onClicked: {
                clearTimeMoments();
                _timer.reset()
            }
        }
    }

    Button{
        id: _timeEnterButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        buttonText: "Set initial time"
        enabled: !_timer.isActive

        MouseArea{
            anchors.fill: parent
            //onClicked: _timer.loadTime();
            onClicked: _dialogWindow.open()
        }

        Dialog {
            id: _dialogWindow
            visible: false
            title: "Enter the initial timer time"

            TextEdit{
                id: _timeEdit
                width: 240
                text: "mm:ss:zzz"
                font.family: "Helvetica"
                font.pointSize: 20
                color: "blue"
                focus: true
            }

            standardButtons: StandardButton.Save | StandardButton.Cancel
            onAccepted: {
                _timer.setTime(_timeEdit.text)
                clearTimeMoments();
            }
        }
    }

    Button{
        id: _loadButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        buttonText: "Load initial time from file"
        enabled: !_timer.isActive

        MouseArea{
            anchors.fill: parent
            onClicked: _fileDialog.open();
        }

        FileDialog {
            id: _fileDialog
            title: "Please choose a file with the Timer timeout value"
            nameFilters: [ "Text files (*.txt)"]
            folder: shortcuts.home
            onAccepted: {
                _timer.loadTime(_fileDialog.fileUrl)
                clearTimeMoments();
            }
        }
    }

    Button{
        id: _saveButton
        width: parent.buttonWidth
        height: parent.buttonHeight
        buttonText: "Save current time"
    }
}
