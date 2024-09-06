import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Rectangle {
    id: dialog0001

    MouseArea {
        anchors.fill: parent
        onPressed: {}
        onClicked: {}
    }

    Rectangle {
        width: 300
        height: 300
        color: "#224D45"
        border.width: 2
        border.color: "green"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        radius: 12
        Column {
            id: column
            anchors.fill: parent
            padding: 12
            spacing: 8
            BusyIndicator {
                id: busyIndicator
                width: 100
                height: 100
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: qsTr("Processing... 5-10 minutes")
                anchors.horizontalCenter: parent.horizontalCenter
                color: "white"
                font.pointSize: 13
            }
            Rectangle {
                height: 16
                width: 1
                color: "#00000000"
            }

            Text {
                id: tvProcessDesc
                width: 260
                objectName: "tvProcessDesc"
                text: qsTr("Unpacking...")
                elide: Text.ElideMiddle
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAnywhere
                maximumLineCount: 2
                anchors.horizontalCenter: parent.horizontalCenter
                color: "white"
                font.pointSize: 13
            }
            Rectangle {
                height: 16
                width: 1
                color: "#00000000"
            }
            Button {
                display: AbstractButton.TextUnderIcon
                rightPadding: 20
                leftPadding: 20
                enabled: true
                anchors.horizontalCenter: parent.horizontalCenter
                contentItem: Text {
                    text: qsTr("Cancel")
                    color: "white"
                    font.pointSize: 14
                }
                background: Rectangle {
                    color: "blue"
                    radius: 12
                    border.width: 2
                    border.color: "green"
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        vc.onDialogCancelBtnClick()
                        dialog0001.visible = false
                    }
                }
            }
        }

    }

}
