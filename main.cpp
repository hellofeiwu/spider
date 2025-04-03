#include <QCoreApplication>
#include "HttpAccess.h"
#include "ReTool.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QUrl url("http://www.google.com");
    HttpAccess httpAccess;

    httpAccess.get(url);

    QObject::connect(&httpAccess, &HttpAccess::finished, [](const QString &data){
        ReTool reTool("<input class=[\\s\\S]*?value=\"([\\s\\S]*?)\"[\\s\\S]*?name");
        QVector<QString> res = reTool.match(data);
        for(auto s : res){
           qDebug()<<s;
        }
    });

    QObject::connect(&httpAccess, &HttpAccess::error, [](const QString &errorString){
        qDebug()<<errorString;
    });

    return a.exec();
}
