#ifndef APK_UNPACK_AND_PACK_PKG_H
#define APK_UNPACK_AND_PACK_PKG_H
#include <QFileInfo>
#include <QFile>
#include <QProcess>
#include <QDir>
#include <QThread>
#include <QUrl>

class ApkUnpackAndPackPkg : public QObject
{
    Q_OBJECT

public:
     explicit ApkUnpackAndPackPkg(QObject *parent = nullptr);
    ~ApkUnpackAndPackPkg();

    bool packingApkPkg(const QString& floder , const QString& jks, const QString& ali, const QString pwd, QString& outputSignedApkPath);

signals:
    void updateLabel(const QString& label);
    void finished(const QString& signedApkPath);

public slots:
    void unApkPkg(const QFileInfo& file, QString * const floder);
};

#endif // APK_UNPACK_AND_PACK_PKG_H
