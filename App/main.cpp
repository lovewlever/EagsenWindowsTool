// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "autogen/environment.h"

#include <QQuickItem>
#include <QDebug>
#include "viewclass.h"
#include <QQmlContext>
#include <QIcon>

// E:\Qt\6.7.2\mingw_64\bin\windeployqt6.exe --release EagsenWindowsToolApp.exe --qmldir E:\Documents\QtProject\EagsenWindowsTool-Release\qml
int main(int argc, char *argv[])
{
    set_qt_environment();
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/res/ic_def_cover.png"));

    QQmlApplicationEngine engine;
    const QUrl url(mainQmlFile);
    QObject::connect(
                &engine, &QQmlApplicationEngine::objectCreated, &app,
                [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    const auto obj = engine.rootObjects().value(0);
    ViewClass vc{obj};
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("vc", &vc);

    return app.exec();
}
