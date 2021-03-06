import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("TCP Client")

    ColumnLayout{
        id : mainLayout
        anchors.fill: parent

        GridLayout{
            columns: 2
            Case_Coloree{
                color : "red"
                iconPath: "Images/alarm.png"
                onClicked: AppManager.launchApp("Alarme");
            }
            Case_Coloree{
                color: "green"
                iconPath: "Images/console.png"
                onClicked: AppManager.launchApp("Jeux");
            }
            Case_Coloree{
                color: "yellow"
                iconPath: "Images/youtube.png"
                onClicked: AppManager.launchApp("Youtube");
            }
            Case_Coloree{
                color: "blue"
                iconPath: "Images/music-player.png"
                onClicked: AppManager.launchApp("Musique");
            }
        }
        Button{
            text: "Reconnect"
            onClicked: AppManager.connectTCP()
        }
    } // end mainLayout
}
