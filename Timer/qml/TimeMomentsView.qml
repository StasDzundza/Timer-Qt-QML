import QtQuick 2.0
import Timer 1.0

ListView {
    model: TimeMomentModel{
    }

    delegate: Rectangle{
        anchors.fill: parent
        border.color: "black"
        border.width: 2

        Text {
            width: parent.width
            height: 20
            color: "black"
            text: display
            anchors.centerIn: parent
        }
    }
}
