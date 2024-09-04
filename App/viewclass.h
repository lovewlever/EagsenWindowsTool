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

public:
    explicit ViewClass(QObject *parent = nullptr);

signals:

public slots:
    void btnClicked();
    void onFileDialogAccepted(const QString& filePath);
    void onSignatureDialogAccepted(const QString& filePath);
    void onKeyAliasTextChanged(const QString& keyAlias);
    void onPasswordTextChanged(const QString& filePath);

    void onChannelInviteTextChanged(const QString& invite);
    void onChannelManagerTextChanged(const QString& manager);
};

#endif // VIEWCLASS_H
