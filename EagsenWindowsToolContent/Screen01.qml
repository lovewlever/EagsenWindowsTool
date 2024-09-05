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
        nameFilters: ["JKS File (*.jks)", "KeyStore File (*.keystore)"]
        onAccepted: {
            vc.onSignatureDialogAccepted(jksSelectDialog.selectedFile)
        }
    }

    FileDialog {
        id: aboutImageSelectDialog
        title: "Select About Image"
        nameFilters: "Image File (*.png)"
        onAccepted: {
            vc.onAboutImageSelectDialogAccepted(aboutImageSelectDialog.selectedFile)
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
                id: textABC
                objectName: "textABC"
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
                width: 120
                text: "APK File:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                width: 12
                height: 10
                color: "#00000000"
            }

            Button {
                width: 200
                height: 32
                id: btnSelectApk
                objectName: "btnSelectApk"
                background: Rectangle {
                    color: "blue"
                    radius: 6
                }

                contentItem: Text {
                    objectName: "tvSelectApk"
                    text: "Click here select apk"
                    elide: Text.ElideMiddle
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    maximumLineCount: 1
                    anchors.horizontalCenter: parent.horizontalCenter
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
            id: row3
            spacing: 12
            Label {
                width: 120
                text: "About Us"
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
            }

            Button {
                id: button
                width: 200
                height: 32
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: "blue"
                    radius: 6
                }
                contentItem: Text {
                    objectName: "tvSelectPic"
                    text: qsTr("Click here select picture")
                    elide: Text.ElideMiddle
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    anchors.horizontalCenter: parent.horizontalCenter
                    maximumLineCount: 1
                    color: "white"

                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        aboutImageSelectDialog.open()
                    }
                }
            }

            TextField {
                id: textField1
                width: 412
                height: 35
                verticalAlignment: Text.AlignVCenter
                background: Rectangle {
                    border.color: "blue"
                    border.width: 2
                    radius: 8
                    color: "#232323"
                }
                placeholderTextColor: "#999999"
                placeholderText: "Url"
                color: "white"
                onTextChanged: {
                    vc.onAboutTextChanged(textField1.text)
                }
            }
        }

        Row {
            id: row2
            spacing: 12

            Label {
                width: 120
                text: "Signature File:"
                color: "white"
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                width: 200
                height: 32
                id: btnSelectSignatureFile
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    color: "blue"
                    radius: 6
                }

                contentItem: Text {
                    objectName: "tvSelectSignatureFile"
                    text: "Click here select signature file"
                    elide: Text.ElideMiddle
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    anchors.horizontalCenter: parent.horizontalCenter
                    maximumLineCount: 1
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
                id: textField4
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
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "KeyAlias"
                placeholderTextColor: "#999999"
                onTextChanged: vc.onKeyAliasTextChanged(textField4.text)
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
                placeholderText: "Password"
                placeholderTextColor: "#999999"
                onTextChanged: vc.onPasswordTextChanged(textField3.text)
            }
        }

        Row {
            spacing: 12
            Label {
                width: 120
                text: "Channel Code:"
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
                placeholderText: "Channel Invite"
                placeholderTextColor: "#999999"
                onTextChanged: vc.onChannelInviteTextChanged(textField.text)
            }

            Label {
                text: "Empty not processed"
                anchors.verticalCenter: parent.verticalCenter
                color: "green"
                visible: textField.text.trim() === ""
            }
        }

        Row {
            id: row11
            spacing: 12

            Label {
                width: 120
                text: "Channel Manager:"
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
                placeholderText: "Channel Manager"
                placeholderTextColor: "#999999"
                onTextChanged: vc.onChannelManagerTextChanged(textField2.text)
            }

            Label {
                text: "Empty not processed"
                anchors.verticalCenter: parent.verticalCenter
                color: "green"
                visible: textField2.text.trim() === ""
            }
        }

        Row {
            id: row4
            spacing: 12
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
                    onClicked: {
                        vc.btnClicked()
                    }
                }
            }
            Text {
                id: errorText
                objectName: "errorText"
                text: ""
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 14
                color: "red"
            }
        }

        Text {
            objectName: "processDoneText"
            text: ""
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
            verticalAlignment: Text.AlignTop
            color: "green"
            font.pointSize: 16
        }
    }


    Dialog0001 {
        id: dialogProcess
        objectName: "dialogProcess"
        anchors.fill: parent
        color: "#7f000000"
        z: 2
        visible: false
    }
}
