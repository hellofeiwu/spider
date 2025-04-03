#include "ReTool.h"
#include <QRegularExpression>

QVector<QString> ReTool::match(const QString &data)
{
    QVector<QString> res;
    QRegularExpression regex(_pattern);
    QRegularExpressionMatchIterator i = regex.globalMatch(data);
    while(i.hasNext()){
        QRegularExpressionMatch match = i.next();
        res.append(match.captured(1));
    }
    return res;
}
