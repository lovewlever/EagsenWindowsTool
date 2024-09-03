#ifndef VIEWCLASS_H
#define VIEWCLASS_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QVariant>
#include <QProcess>
#include <QFile>
#include <QFile>

class ViewClass : public QObject
{
    Q_OBJECT

private:
    QString apkFilePath = nullptr;
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
};




#endif // VIEWCLASS_H
