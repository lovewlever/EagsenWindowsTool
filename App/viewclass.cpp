#include "viewclass.h"

ViewClass::ViewClass(QObject *parent)
    : QObject{parent}
{}

void ViewClass::btnClicked() {

    qDebug("click");
}

void ViewClass::onFileDialogAccepted(const QString& filePath) {
    QFile file{filePath};
    QFileInfo fileInfo {file.fileName()};
    const auto fileName = fileInfo.fileName();
    this->apkFilePath = filePath;
    const auto btnSelectApk = parent()->findChild<QObject*>("tvSelectApk");
    btnSelectApk->setProperty("text", fileName);
    qDebug() << filePath;
}

void ViewClass::onSignatureDialogAccepted(const QString& filePath) {
    QFile file{filePath};
    QFileInfo fileInfo {file.fileName()};
    const auto fileName = fileInfo.fileName();
    this->signatureFilePath = filePath;
    const auto btnSelectSignatureFile = parent()->findChild<QObject*>("tvSelectSignatureFile");
    btnSelectSignatureFile->setProperty("text", fileName);
    qDebug() << filePath;
}

void ViewClass::onKeyAliasTextChanged(const QString& keyAlias) {
    this->signatureKeyAlias = keyAlias;
    qDebug() << "onKeyAliasTextChanged" << keyAlias;
}

void ViewClass::onPasswordTextChanged(const QString& password) {
    this->signaturePwd = password;
    qDebug() << "onPasswordTextChanged" << password;
}

void ViewClass::onChannelInviteTextChanged(const QString& invite) {
    this->channelInvite = invite;
    qDebug() << "onChannelInviteTextChanged" << invite;
}

void ViewClass::onChannelManagerTextChanged(const QString& manager) {
    this->channelManager = manager;
    qDebug() << "onChannelManagerTextChanged" << manager;
}
