#include "about_us_process.h"

AboutUsProcess::AboutUsProcess(QObject *parent)
    : QObject{parent}
{}

void AboutUsProcess::processAboutUs(const QString& floder, const QString &imagePath, const QString &url)
{
    qDebug() << "开始处理关于我们：------------------------ START";
    qDebug() << "解包后的目录：" << floder;
    qDebug() << "图片地址: " << imagePath;
    qDebug() << "点击的连接地址：" << url;
    QFileInfo fInfo{ QUrl(imagePath).toLocalFile() };
    if(fInfo.isFile()) {
        emit this->updateLabel("Process About Us Image...");
        QString dstFilePath = {floder + "/assets/" + ABOUT_US_IMAGE_FILE_NAME};
        QFile dstFile{dstFilePath};
        if(dstFile.exists()) {
            const auto removeBoo = QFile::remove(dstFilePath);
            qDebug() << "About image found, remove :" << removeBoo;;
            emit this->updateLabel(QString{"About image found, remove :"} + (removeBoo ? "1" : "0"));
        }
        QFile::copy(fInfo.absoluteFilePath(), dstFilePath);
    } else {
        emit this->updateLabel("About us image is empty, jump");
        qDebug() << "关于我们的图片为空，跳过";
    }

    if(url != nullptr && url != "") {
        emit this->updateLabel("Process About Us Url...");
        QFile configJsonFile{floder + "/assets/" + ABOUT_US_URL_FILE_NAME};

        const auto open = configJsonFile.open(QIODevice::ReadWrite);
        emit this->updateLabel("Open file " + configJsonFile.fileName() + ": " + (open ? "1" : "0"));
        if(open) {
            const auto len = configJsonFile.write(url.toUtf8());
            emit this->updateLabel("Write file " + configJsonFile.fileName() + ": " + QString::number(len));
            qDebug() << "Write file " + configJsonFile.fileName() + ": " + QString::number(len);
            configJsonFile.close();
        } else {
            emit this->updateLabel("File open fail");
            qDebug() << "文件打开失败---";
        }
    } else {
        emit this->updateLabel("About us url is empty, jump");
        qDebug() << "关于我们的链接为空，跳过";
    }

    qDebug() << "开始处理关于我们：------------------------ END";
}
