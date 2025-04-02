#include "HttpAccess.h"

HttpAccess::HttpAccess(QObject *parent) : QObject(parent){

}

void HttpAccess::get(QUrl &url){
    QNetworkRequest request(url);
    QNetworkReply* reply = _manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, [this, reply](){
        if(reply->error()==QNetworkReply::NoError){
            QByteArray data = reply->readAll();
            emit finished(data); // emit 也是qt自己的一个机制 这里就是调用HttpAccess类里声明的finished方法
        }else{
            emit error(reply->errorString());
        }

        reply->deleteLater();
    });
}

HttpAccess::~HttpAccess(){

}
