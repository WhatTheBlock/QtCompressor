#ifndef FILEDL_H
#define FILEDL_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDL : public QObject {
    Q_OBJECT
public:
    explicit FileDL(QUrl fileUrl, QObject *parent = 0);
    virtual ~FileDL();
    QByteArray downloadedData() const;
signals:
    void downloaded();
private slots:
    void fileDownloaded(QNetworkReply* pReply);
private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};



#endif // FILEDL_H
