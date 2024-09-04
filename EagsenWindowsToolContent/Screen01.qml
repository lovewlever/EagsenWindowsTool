// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
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
import QtQuick.Layouts

Rectangle {
    id: rectangle
    width: 800
    height: 600
    color: "#ed000000"

    FileDialog {
        id: apkSelectDialog
        title: "Select APK"
        nameFilters: "Apk File (*.apk)"
        onAccepted: {
            vc.onFileDialogAccepted(apkSelectDialog.selectedFile)
        }
    }

    FileDialog {
        id: jksSelectDialog
        title: "Select APK"
        nameFilters: ["Jks File (*.jks)", "KeyStore File (*.keystore)"]
        onAccepted: {
            vc.onFileDialogAccepted(apkSelectDialog.selectedFile)
        }
    }

    ColumnLayout {
        id: column
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 12
        anchors.rightMargin: 12
        anchors.topMargin: 12
        spacing: 20

        Row {
            id: row1
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

        Row {
            id: row
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

        Row {
            id: row2
            spacing: 12

            Label {
                width: 100
                text: "请选择签名文件:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
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
                    onClicked: jksSelectDialog.open()
                }
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
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "please input password"
                placeholderTextColor: "#999999"
            }
        }

        Row {
            spacing: 12
            Label {
                width: 100
                text: "渠道码:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
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

            Label {
                text: "留空不处理"
                anchors.verticalCenter: parent.verticalCenter
                color: "red"
            }
        }

        Row {
            id: row11
            spacing: 12

            Label {
                width: 100
                text: "渠道经理:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
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

            Label {
                text: "留空不处理"
                anchors.verticalCenter: parent.verticalCenter
                color: "red"
            }
        }


        Button {
            id: button2
            rightPadding: 24
            leftPadding: 24
            contentItem: Text {
                text: qsTr("Commit")
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: "white"
                font.pointSize: 18

            }
            background: Rectangle {
                color: "green"
                radius: 6
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {}
            }
        }

    }


}
