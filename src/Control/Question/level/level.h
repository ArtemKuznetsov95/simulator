#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QMap>

class level
{
public:    
    virtual QMap<int, QString> getMapAnswer() = 0;
    virtual int getResult() = 0;
    virtual QString getQuestion() = 0;
};

#endif // LEVEL_H
