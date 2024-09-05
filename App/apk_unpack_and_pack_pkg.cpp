#include "apk_unpack_and_pack_pkg.h"

/**
 * @brief ApkUnpackAndPackPkg::unApkPkg
 * @param file
 * @return
 * .\apktool d .\云联_国际版_10000_1.0.0.0_2024_08_30_16_.apk -o yunlianresource
 */
ApkUnpackAndPackPkg::ApkUnpackAndPackPkg(QObject *parent)
{

}

ApkUnpackAndPackPkg::~ApkUnpackAndPackPkg()
{
    qDebug() << "调用析构函数：ApkUnpackAndPackPkg";
}

bool ApkUnpackAndPackPkg::packingApkPkg(const QString& floder, const QString &jks, const QString &ali, const QString pwd, QString& outputSignedApkPath)
{
    qDebug() << "打包：------------------------ START";
    qDebug() << "floder" << floder;
    qDebug() << "jks：" << jks;
    qDebug() << "ali: " << ali;
    qDebug() << "pwd：" << pwd;
    emit this->updateLabel("Packing apk...");
    QString apkFilePath{floder + "/eagsen_unsign.apk"};
    QString cmd{"Tools/jbr/bin/java.exe -jar Tools/apktool_2.9.3.jar b "};
    cmd.append("\"")
        .append(floder)
        .append("\"")
        .append(" -o \"")
        .append(apkFilePath)
        .append("\" --use-aapt2");
    qDebug() << "CMD:" << cmd;
    QProcess process;
    process.startCommand(cmd);
    connect(&process, &QProcess::readyReadStandardOutput, this, [&]() {
        const auto output = process.readAllStandardOutput();
        qDebug() << output;
        emit this->updateLabel(output);
    });
    connect(&process, &QProcess::readyReadStandardError, this, [&]() {
        const auto error = process.readAllStandardError();
        qDebug() << error;
        emit this->updateLabel(error);
    });
    process.waitForFinished(600000);
    auto output = process.readAllStandardOutput();
    auto error = process.readAllStandardError();
    qDebug() << "\npackingApkPkg#readAllStandardOutput" << output << "\npackingApkPkg#ErroR:" << error;

    //对齐///////////////////////////////////////////////////////////////////////////////////////
    qDebug() << "zipalign.exe -v 4";
    QString alignedApkPath{floder + "/eagsen_unsign_aligned.apk"};
    // 已存在对齐的apk 删除
    QFile alignedFile{alignedApkPath};
    if (alignedFile.exists()) {
        const auto rBoo = QFile::remove(alignedApkPath);
        qDebug() << "\neagsen_unsign_aligned.apk已存在-删除： " << rBoo;
    }
    QString zipalignCmd{"Tools/build-tools/zipalign.exe -v 4 \"" + apkFilePath + "\" \"" + alignedApkPath + "\""};
    qDebug() << "zipalign.exe -v 4: " << zipalignCmd;
    process.startCommand(zipalignCmd);
    process.waitForFinished(600000);
    output = process.readAllStandardOutput();
    error = process.readAllStandardError();
    qDebug() << "\nzipalign-output" << output << "\nzipalign:error" << error;

    //签名///////////////////////////////////////////////////////////////////////////////////////
    // Tools/build-tools/apksigner.bat sign -verbose --ks .\668.keystore --out eagsen_signed.apk .\eagsen_unsign_aligned.apk
    QString signedApkPath{floder + "/eagsen_signed.apk"};
    QString signCmd{"Tools/build-tools/apksigner.bat sign -verbose --v1-signing-enabled true --v2-signing-enabled true --ks "};
    signCmd.append("\"").append(QUrl(jks).toLocalFile()).append("\"")
        .append(" --ks-key-alias ").append(ali)
        .append(" --ks-pass pass:").append(pwd)
        .append(" --out ")
        .append("\"").append(signedApkPath).append("\" ")
        .append("\"").append(alignedApkPath).append("\"");
    qDebug() << "签名: " << signCmd;
    process.startCommand(signCmd);
    process.waitForFinished(600000);
    output = process.readAllStandardOutput();
    error = process.readAllStandardError();
    qDebug() << "\n签名-output: " << output << "\n签名-error" << error;

    qDebug() << "打包：------------------------ END";
    outputSignedApkPath = signedApkPath;
    return true;
}

void ApkUnpackAndPackPkg::unApkPkg(const QFileInfo &file, QString * const floder)
{
    //"E:/Documents/AndroidProjects/Eagsen Auto 3.4 Dev/Eagsen Auto/app/apks/掌讯_国际版_10000_1.0.0.0_2024_09_03_14_.apk"
    QString filePath = file.filePath();
    //QString fileName = file.fileName();
    //"E:/Documents/AndroidProjects/Eagsen Auto 3.4 Dev/Eagsen Auto/app/apks"
    QString path = file.path();
    QString unpkgFloder{path + "/unpackageapksource"};
    QDir dir{unpkgFloder};
    if(dir.exists()) {
        emit this->updateLabel("Cleaning up previous data");
        const auto boo = dir.removeRecursively();
        qDebug() << "删除目录：" << boo;
    }

    QString cmd{"Tools/jbr/bin/java.exe -jar Tools/apktool_2.9.3.jar -f d \"" + filePath + "\" -o \"" + unpkgFloder + "\""};
    qDebug() << "CMD:" << cmd;

    QProcess process;
    process.startCommand(cmd);
    QObject::connect(&process, &QProcess::readyReadStandardOutput, this, [&](){
        const auto output = process.readAllStandardOutput();
        qDebug() << "readAllStandardOutput" << output;
        emit this->updateLabel(output);
    });
    process.waitForFinished(600000);
    const auto output = process.readAllStandardOutput();
    const auto err = process.readAllStandardError();
    qDebug() << "\nreadAllStandardOutput" << output << "\nErroR:" << err;
    qDebug() << "\nreadAllStandardOutput" << output << "\nErroR:" << err;

    *floder = unpkgFloder;
}
