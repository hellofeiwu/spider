#ifndef HTTPACCESS_H
#define HTTPACCESS_H

#include <QObject>
#include <QtNetwork>

class HttpAccess : public QObject
{
    Q_OBJECT
public:
    explicit HttpAccess(QObject *parent = nullptr);
    HttpAccess(const HttpAccess &other) = delete;
    HttpAccess(HttpAccess &&other) = delete;

    HttpAccess& operator= (const HttpAccess &other)=delete;
    HttpAccess& operator= (HttpAccess &&other)=delete;

    virtual ~HttpAccess();

    void get(QUrl &url);


signals:
    void finished(const QByteArray &data); // 这个是qt内部的一个已经存在的方法不用写实现，只要在这里声明一下，别的地方就可以用了
    void error(const QString &errorString); // 和上面的方法是一样的机制
private:
    QNetworkAccessManager _manager;

};

#endif // HTTPACCESS_H
