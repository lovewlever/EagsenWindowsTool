#include "channel_process.h"

ChannelProcess::ChannelProcess(QObject *parent)
    : QObject{parent}
{}

bool ChannelProcess::processChannel(const QString &floder, const QString &channelCode, const QString &channelmanager)
{
    qDebug() << "开始处理渠道：------------------------ START";
    qDebug() << "解包后的目录：" << floder;
    qDebug() << "渠道码: " << channelCode;
    qDebug() << "渠道经理" << channelmanager;
    const auto isChannelCodeNotSet = channelCode == nullptr || channelCode == "";
    const auto isCnannelManagerNotSet = channelmanager == nullptr || channelmanager == "";

    if(isChannelCodeNotSet && isCnannelManagerNotSet) {
        qDebug() << "都是空的，跳过";
        return false;
    }

    QFile file{floder + "/AndroidManifest.xml"};
    if(!file.exists()) {
        qDebug() << "未找到AndroidManifest.xml，跳过";
        return false;
    }

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文档，跳过";
        return false;
    }
    QDomDocument* xmlDom = new QDomDocument();
    xmlDom->setContent(&file);
    file.close();
    QDomElement element = xmlDom->documentElement();
    QDomNodeList nodeList = element.elementsByTagName("meta-data");
    for(int i = 0; i<nodeList.count();i++) {
        QDomElement nodeElement = nodeList.at(i).toElement();
        const QDomNamedNodeMap attributes = nodeElement.attributes();
        for(int i=0; i < attributes.count();i++) {
            const QDomNode node = attributes.item(i);
            if(node.nodeValue() == "eagsen_channel_invite" && !isChannelCodeNotSet) {
                nodeElement.setAttribute("android:value", channelCode);
            }
            if(node.nodeValue() == "eagsen_channel_manager" && !isCnannelManagerNotSet) {
                nodeElement.setAttribute("android:value", channelmanager);
            }
        }

    }

    QFile outFile{floder + "/AndroidManifest.xml"};

    if(!outFile.open(QIODevice::WriteOnly)) {
        qDebug() << "无法打开文档，跳过";
        return false;
    }
    QTextStream textStream{&outFile};
    xmlDom->save(textStream, 4);
    outFile.close();
    delete xmlDom;
    qDebug() << "开始处理渠道：------------------------ END";
    return true;
}
