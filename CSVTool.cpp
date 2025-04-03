#include "CSVTool.h"

bool CSVTool::writeCSV(const QVector<QString> &headers, const QVector<QString> &contentPairs)
{
    QFile file(_fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"open file failed";
        return false;
    }

    QTextStream outFile(&file);
    outFile.setCodec("utf-8");

    // write headers and content pairs
    try {
        for(auto header : headers){
            if(header.contains(":")){
                throw std::runtime_error("header cannot contain \":\"");
            }
        }
        outFile<<headers[0]<<" : "<<headers[1]<<"\n";

        for(auto pair : contentPairs){
            QStringList parts = pair.split(" : ");
            if(parts.size() != 2){
                throw std::runtime_error("incomplete data");
            }
            outFile<<parts[0]<<" : "<<parts[1]<<"\n";
        }

    } catch (std::exception &e) {
        qDebug()<<"Error: "<<e.what();
        file.close();
        return false;
    }
    file.close();
    return true;
}
