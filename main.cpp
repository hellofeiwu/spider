#include <QCoreApplication>
#include "HttpAccess.h"
#include "ReTool.h"
#include "CSVTool.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QUrl url("http://www.baidu.com");
    QString pattern = "<li class=\"hotsearch-item[\\s\\S]*?href=\"([\\s\\S]*?)\"[\\s\\S]*?class=\"title-content-title\">([\\s\\S]*?)</span>";
    HttpAccess httpAccess;

    httpAccess.get(url);

    QObject::connect(&httpAccess, &HttpAccess::finished, [&](const QString &data){
        ReTool reTool(pattern);
        QVector<QString> res = reTool.match(data);
        CSVTool csvTool("test.csv");
        QVector<QString> headers = {"Title", "URL"};
        bool writeCsvOk = csvTool.writeCSV(headers, res);
        if(writeCsvOk){
            qDebug()<<"write csv file ok";
        }else{
            qDebug()<<"write csv file failed";
        }
    });

    QObject::connect(&httpAccess, &HttpAccess::error, [](const QString &errorString){
        qDebug()<<errorString;
    });

    return a.exec();
}
