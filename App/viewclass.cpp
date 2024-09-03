#include "viewclass.h"

ViewClass::ViewClass(QObject *parent)
    : QObject{parent}
{}

void ViewClass::btnClicked() {

    qDebug("click");
}

void ViewClass::onFileDialogAccepted(const QString& filePath) {

    QFile file{filePath};
    const auto fileName = file.fileName();

    // const auto par = parent();
    // const auto btn = par->findChild<QObject*>("button");
    // const auto item = btn->property("contentItem");
    qDebug() << filePath;
    QProcess process;
    process.startCommand("adb devices");
    process.waitForReadyRead();
    QByteArray arr = process.readAllStandardOutput();
    qDebug() << "CMD: " << arr;
}
