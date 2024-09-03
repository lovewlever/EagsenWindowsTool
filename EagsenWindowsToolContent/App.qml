// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.7
import EagsenWindowsTool

Window {
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "EagsenWindowsTool"
    maximumHeight: 600
    maximumWidth: 800


    Screen01 {
        id: mainScreen
    }

}

