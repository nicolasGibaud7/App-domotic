import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5
import QtQuick.Extras 1.4

import StateEnum 1.0

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
                onClicked: console.log("red button")//AppManager.launchApp(AppState.HOME);
            }
            Case_Coloree{
                color: "green"
                iconPath: "Images/console.png"
                onClicked: console.log("jeux button")//AppManager.launchApp(AppState.HOME);
            }
            Case_Coloree{
                color: "yellow"
                iconPath: "Images/youtube.png"
                onClicked: AppManager.launchApp(AppState.VIDEO);
            }
            Case_Coloree{
                color: "blue"
                iconPath: "Images/music-player.png"
                onClicked: AppManager.launchApp(AppState.MUSIC);
            }
        }
        Row{
            Button{
                text: "Reconnect"
                onClicked: AppManager.connectTCP()
            }
            StatusIndicator{

            }
        }


    } // end mainLayout
}
