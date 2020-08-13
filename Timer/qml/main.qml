import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    minimumWidth: 300
    minimumHeight: 500
    title: qsTr("Timer")

    Rectangle{
        id: _background
        anchors.fill: parent
        color: "#ededf2"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ededf2"
            }

            GradientStop {
                position: 1
                color: "#00d4ff"
            }
        }

        Column{
            anchors.fill: parent
            spacing: 20

            TimeView{
                id: _timeView
                width: parent.width
                height: parent.height / 7
                color: "white"
            }

            TimeMomentsView{
                id: _timeMomentsView
                width: parent.width - 20
                anchors.horizontalCenter: parent.horizontalCenter
                height: parent.height / 7

            }

            ButtonPannel{
                textView: _timeView
                timeMomentsViewTarget: _timeMomentsView
                width: parent.width - 20
                height: parent.height / 3
                buttonWidth: width
                buttonHeight: height / 4
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10
            }
        }

    }
}
