#ifndef ABOUT_US_PROCESS_H
#define ABOUT_US_PROCESS_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QUrl>
#include <QJsonObject>
#include <QDir>
#include "constants.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>


class AboutUsProcess : public QObject
{
    Q_OBJECT
public:
    explicit AboutUsProcess(QObject *parent = nullptr);

    void processAboutUs(const QString& floder, const QString& imagePath, const QString& url);

signals:
    void updateLabel(const QString& label);
};

#endif // ABOUT_US_PROCESS_H
