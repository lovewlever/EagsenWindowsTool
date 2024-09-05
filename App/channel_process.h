#ifndef CHANNEL_PROCESS_H
#define CHANNEL_PROCESS_H

#include <QObject>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QFileInfo>

class ChannelProcess : public QObject
{
    Q_OBJECT
public:
    explicit ChannelProcess(QObject *parent = nullptr);
    bool processChannel(const QString& floder, const QString& channelCode, const QString& channelmanager);

signals:
};

#endif // CHANNEL_PROCESS_H
