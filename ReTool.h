#ifndef RETOOL_H
#define RETOOL_H
#include <QVector>

class ReTool
{
public:
    ReTool(QString pattern = ""):_pattern(pattern){};
    QVector<QString> match(const QString &data);
private:
    QString _pattern;
};

#endif // RETOOL_H
