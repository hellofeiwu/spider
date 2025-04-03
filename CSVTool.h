#ifndef CSVTOOL_H
#define CSVTOOL_H
#include <QFile>
#include <QTextStream>
#include <QDebug>

class CSVTool
{
public:
    CSVTool(const QString fileName):_fileName(fileName){}
    bool writeCSV(const QVector<QString> &headers, const QVector<QString> &contentPairs);
private:
    QString _fileName;
    QVector<QString> _contentPairs;
};

#endif // CSVTOOL_H
