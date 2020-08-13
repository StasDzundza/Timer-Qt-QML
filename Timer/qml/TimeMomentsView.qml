import QtQuick 2.0
import Timer 1.0

ListView {
    model: ListModel{
        id: _timeMomentModel
    }

    delegate: Rectangle{
        width: parent.width
        height: 30
        border.color: "black"
        border.width: 1

        Text {
            width: parent.width
            anchors.centerIn: parent
            text: display.toString()
            anchors.rightMargin: 10
        }

        MouseArea{
            anchors.fill: parent
        }
    }

    function addTimeMoment(value){
        _timeMomentModel.append({display:value})
    }

    function clearModel(){
        _timeMomentModel.clear()
    }

    function getTimeMomentModel(){
        return model
    }

}
