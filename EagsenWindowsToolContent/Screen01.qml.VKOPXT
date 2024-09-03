

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.7
import QtQuick.Controls 6.7
import EagsenWindowsTool
import QtQuick.Dialogs

Rectangle {
    id: rectangle
    width: maximumWidth
    height: maximumHeight

    color: "#ed000000"

    Column {
        id: column
        padding: 12
        anchors.fill: parent

        Row {
            id: row1
            width: implicitWidth
            height: implicitHeight
            Image {
                id: name
                source: "images/ic_def_cover.png"
                width: 80
                height: 80
            }
            Rectangle {
                height: 1
                width: 12
                color: "#00000000"
            }
            Text {
                width: implicitWidth
                height: implicitHeight
                color: "#B7B7B7"
                text: qsTr("Eagsen APK process tool")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 24
                font.family: Constants.font.family
            }

        }

        Rectangle {
            height: 20
            width: 1
            color: "#00000000"
        }

        FileDialog {
            id: apkSelectDialog
            title: "Select APK"
            nameFilters: "Text Files (*.apk)"
            onAccepted: {
                vc.onFileDialogAccepted(apkSelectDialog.selectedFile)
            }
        }

        Row {
            id: row
            width: implicitWidth
            height: implicitHeight

            Label {
                width: 100
                text: "请选择APK:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            Button {
                id: button
                background: Rectangle {
                    color: "blue"
                    radius: 6
                }

                contentItem: Text {
                    text: "click here selecte apk"
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: apkSelectDialog.open()
                }
            }
        }

        Rectangle {
            height: 20
            width: 1
            color: "#00000000"
        }
        Row {
            id: row2
            width: implicitWidth
            height: implicitHeight

            Label {
                width: 100
                text: "请选择签名文件:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            Button {
                id: button1
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: "blue"
                    radius: 6
                }

                contentItem: Text {
                    text: "click here selecte signature file"
                    color: "white"
                }

                MouseArea {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {}
                }
            }

            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            TextField {
                id: textField3
                height: 35
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                width: 200
                background: Rectangle {
                    border.color: "blue"
                    border.width: 2
                    radius: 8
                    color: "#232323"
                }
                echoMode: TextInput.Password
                color: "white"
                placeholderText: "please input password"
                placeholderTextColor: "#999999"
            }
        }

        Rectangle {
            height: 20
            width: 1
            color: "#00000000"
        }
        Row {
            width: implicitWidth
            height: implicitHeight

            Label {
                width: 100
                text: "渠道码:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            TextField {
                id: textField
                height: 35
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                width: 200
                background: Rectangle {
                    border.color: "blue"
                    border.width: 2
                    radius: 8
                    color: "#232323"
                }
                color: "white"
                placeholderText: "please input channel invite"
                placeholderTextColor: "#999999"
            }
        }

        Rectangle {
            height: 20
            width: 1
            color: "#00000000"
        }
        Row {
            width: implicitWidth
            height: implicitHeight

            Label {
                width: 100
                text: "渠道经理:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            TextField {
                id: textField2
                height: 35
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                width: 200
                background: Rectangle {
                    border.color: "blue"
                    border.width: 2
                    radius: 8
                    color: "#232323"
                }
                color: "white"
                placeholderText: "please input channel manager"
                placeholderTextColor: "#999999"
            }
        }

    }


}
