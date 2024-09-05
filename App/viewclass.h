#ifndef VIEWCLASS_H
#define VIEWCLASS_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QProcess>
#include <QFile>
#include <QFile>
#include <QFileInfo>
#include <QUrl>
#include <QThread>
#include "apk_unpack_and_pack_pkg.h"
#include "about_us_process.h"
#include "channel_process.h"

class ViewClass : public QObject
{
    Q_OBJECT

private:
    QString apkFilePath = nullptr;
    QString signatureFilePath = nullptr;
    QString signatureKeyAlias = nullptr;
    QString signaturePwd = nullptr;
    QString aboutImagePath = nullptr;
    QString aboutClickUrl = nullptr;
    QString channelInvite = nullptr;
    QString channelManager = nullptr;


    ApkUnpackAndPackPkg* apktool = nullptr;
    QThread* thread = nullptr;
    std::shared_ptr<QFileInfo> apkFileInfoPtr = nullptr;
    std::shared_ptr<AboutUsProcess> aboutUsProcess = nullptr;
    std::shared_ptr<ChannelProcess> channelProcess = nullptr;

private:
    bool isNeedOp();
    bool isInputSignatureFile();

public:
    explicit ViewClass(QObject *parent = nullptr);
    ~ViewClass();

signals:

public slots:
    void btnClicked();
    void onAboutImageSelectDialogAccepted(const QString& filePath);
    void onFileDialogAccepted(const QString& filePath);
    void onSignatureDialogAccepted(const QString& filePath);
    void onKeyAliasTextChanged(const QString& keyAlias);
    void onPasswordTextChanged(const QString& filePath);
    void onAboutTextChanged(const QString& url);

    void onChannelInviteTextChanged(const QString& invite);
    void onChannelManagerTextChanged(const QString& manager);
};

#endif // VIEWCLASS_H
