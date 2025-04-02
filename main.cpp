#include <QCoreApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUrl url("http://www.baidu.com");
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, [&](){
        if(reply->error()==QNetworkReply::NoError){
            QByteArray data = reply->readAll();
            QString htmlContent = QString::fromUtf8(data);
            //qDebug()<<htmlContent;
        }else{
            qDebug()<<reply->error();
        }

        reply->deleteLater();
    });

    return a.exec();
}
