import QtQuick 2.0
import Timer 1.0

ListView {
    model: ListModel{
        id: _timeMomentModel
    }

    spacing: 1

    delegate: Rectangle{
        width: parent.width
        height: 30
        border.color: "black"
        border.width: 1

        Text {
            width: parent.width
            color: "black"
            anchors.centerIn: parent
            text: display.toString()
        }

        MouseArea{
            anchors.fill: parent
            onClicked: _timeMomentModel.append({display:"3"})
        }
    }

    function addTimeMoment(value){
        _timeMomentModel.append({display:value})
    }

    function clearModel(){
        _timeMomentModel.clear()
    }

    function getTimeMomentModel(){
        return _timeMomentModel
    }

}
