#include <QCoreApplication>
#include "HttpAccess.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUrl url("www.baidu.com");
    HttpAccess httpAccess;

    httpAccess.get(url);

    QObject::connect(&httpAccess, &HttpAccess::finished, [](const QByteArray &data){
        qDebug()<<data;
    });

    QObject::connect(&httpAccess, &HttpAccess::error, [](const QString &errorString){
        qDebug()<<errorString;
    });

    return a.exec();
}
