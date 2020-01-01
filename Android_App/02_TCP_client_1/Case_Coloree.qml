import QtQuick 2.12
import QtQuick.Layouts 1.12

Rectangle{
    id : root

    Layout.fillHeight: true
    Layout.fillWidth: true

    property string iconPath : "null"
    signal clicked

    Behavior on opacity{
        NumberAnimation{
            duration: 110
        }
    }

    Image{
        id : logo
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        visible: iconPath !== "null"
        source: iconPath !== "null" ? iconPath : ""
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        width: parent.width/3
        height: parent.height/3

        Behavior on width{
            NumberAnimation{
                duration: 110
            }
        }
        Behavior on height{
            NumberAnimation{
                duration: 110
            }
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: root.clicked()
        onPressed: {
            logo.width = parent.width/2
            logo.height= parent.height/2
            root.opacity = 0.6
        }
        onReleased: {
            logo.width = parent.width/3
            logo.height= parent.height/3
             root.opacity = 1
        }
    }
}
