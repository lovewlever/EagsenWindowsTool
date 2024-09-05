#include "viewclass.h"

bool ViewClass::isNeedOp()
{
    return (this->aboutImagePath != nullptr && this->aboutImagePath != "")
    || (this->aboutClickUrl != nullptr && this->aboutClickUrl != "")
        || (this->channelInvite != nullptr && this->channelInvite != "")
        || (this->channelManager != nullptr && this->channelManager != "");
}

bool ViewClass::isInputSignatureFile()
{
    return this->signatureFilePath != nullptr && this->signatureFilePath != ""
           && this->signatureKeyAlias != nullptr && this->signatureKeyAlias != ""
           && this->signaturePwd != nullptr && this->signaturePwd != "";
}

ViewClass::ViewClass(QObject *parent)
    : QObject{parent}
{
    this->apktool = new ApkUnpackAndPackPkg();
    this->thread = new QThread();
    this->aboutUsProcess = std::make_shared<AboutUsProcess>();
    this->channelProcess = std::make_shared<ChannelProcess>();
}

ViewClass::~ViewClass()
{
    qDebug() << "调用析构函数：ViewClass";
    delete this->apktool;
    delete this->thread;
}

void ViewClass::btnClicked() {
    const auto errorText = parent()->findChild<QObject*>("errorText");
    const auto dialogProcess = parent()->findChild<QObject*>("dialogProcess");
    const auto processDoneText = this->parent()->findChild<QObject*>("processDoneText");
    processDoneText->setProperty("text", "");
    errorText->setProperty("text", "");
    this->apkFileInfoPtr = std::make_shared<QFileInfo>(QUrl(this->apkFilePath).toLocalFile());
    qDebug() << "File Exists:" << apkFileInfoPtr->exists();
    qDebug() << "Is File:" << apkFileInfoPtr->isFile();
    if(!apkFileInfoPtr->isFile()) {
        errorText->setProperty("text", "APK file not found");
        return;
    }
    if(!this->isNeedOp()) {
        errorText->setProperty("text", "No operation content");
        return;
    }

    if(!this->isInputSignatureFile()) {
        errorText->setProperty("text", "Signature not set");
        return;
    }
    // 验证签名
    // apksigner.bat sign -verbose --ks .\668.keystore --out eagsen_signed.apk .\eagsen_unsign_aligned.apk
    QString signVerCmd{"Tools/keytool.exe -list -keystore "};
    signVerCmd.append("\"").append(QUrl(this->signatureFilePath).toLocalFile()).append("\"")
        .append(" -alias ")
        .append("\"").append(this->signatureKeyAlias).append("\"")
        .append(" -storepass ")
        .append("\"").append(this->signaturePwd).append("\"");
    qDebug() << "验证签名文件有效性:" << signVerCmd;
    QProcess process;
    process.startCommand(signVerCmd);
    process.waitForFinished(60000);
    const auto output = process.readAllStandardOutput();
    const auto error = process.readAllStandardError();
    // keytool \xB4\xED\xCE\xF3: java.lang.Exception: \xB1\xF0\xC3\xFB <aaa> \xB2\xBB\xB4\xE6\xD4\xDA\r\n
    // keytool \xB4\xED\xCE\xF3: java.io.IOException: keystore password was incorrect
    qDebug() << "验证签名文件有效性: output: " << output << "\nerror: " << error;
    const auto sOut = QString::fromUtf8(output);
    if(sOut.contains("java.lang.Exception") || sOut.contains("java.io.IOException")) {
        errorText->setProperty("text", sOut);
        return;
    }

    const auto tvProcessDesc = parent()->findChild<QObject*>("tvProcessDesc");
    dialogProcess->setProperty("visible", "true");
    tvProcessDesc->setProperty("text", "Unpacking Apk...");

    this->apktool->moveToThread(this->thread);

    connect(this->thread, &QThread::started, this->apktool, [&]() {
        QString outputSignedApkPath{""};
        QString floder{"E:\\Documents\\AndroidProjects\\Eagsen Auto 3.4 Dev\\Eagsen Auto\\app\\apks\\unpackageapksource"};
        //this->apktool->unApkPkg(*apkFileInfoPtr, &floder);
        //this->aboutUsProcess->processAboutUs(floder, this->aboutImagePath, this->aboutClickUrl);
        this->channelProcess->processChannel(floder, this->channelInvite, this->channelManager);
       // this->apktool->packingApkPkg(floder, this->signatureFilePath, this->signatureKeyAlias, this->signaturePwd, outputSignedApkPath);
        qDebug() << "处理完成：" << outputSignedApkPath;
        emit this->apktool->finished(outputSignedApkPath);
    });
    connect(this->apktool, &ApkUnpackAndPackPkg::updateLabel, this, [this](const QString& label) {
        const auto tvProcessDesc = this->parent()->findChild<QObject*>("tvProcessDesc");
        tvProcessDesc->setProperty("text", label);
    });

    connect(this->aboutUsProcess.get(), &AboutUsProcess::updateLabel, this, [this](const QString& label) {
        const auto tvProcessDesc = this->parent()->findChild<QObject*>("tvProcessDesc");
        tvProcessDesc->setProperty("text", label);
    });

    connect(this->apktool, &ApkUnpackAndPackPkg::finished, this, [&](const QString& signedApkPath) {
        const auto p1 = this->parent()->findChild<QObject*>("dialogProcess");
        const auto p2 = this->parent()->findChild<QObject*>("processDoneText");
        p1->setProperty("visible", "false");
        p2->setProperty("text", "Process Success\nBuild APK Path: " + signedApkPath);
    });

    thread->start();
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

void ViewClass::onAboutImageSelectDialogAccepted(const QString& filePath) {
    QFile file{filePath};
    QFileInfo fileInfo {file.fileName()};
    const auto fileName = fileInfo.fileName();
    this->aboutImagePath = filePath;
    const auto btnSelectSignatureFile = parent()->findChild<QObject*>("tvSelectPic");
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

void ViewClass::onAboutTextChanged(const QString& url) {
    this->aboutClickUrl = url;
    qDebug() << "onAboutTextChanged" << url;
}

void ViewClass::onChannelManagerTextChanged(const QString& manager) {
    this->channelManager = manager;
    qDebug() << "onChannelManagerTextChanged" << manager;
}
