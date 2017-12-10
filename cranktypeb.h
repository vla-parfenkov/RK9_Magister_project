#ifndef CRANKTYPEB_H
#define CRANKTYPEB_H

#include <QObject>
#include <crank.h>
#include <outputblock.h>

class OutputBlock;

class CrankTypeB : public QObject, public Crank
{
Q_OBJECT
public:
    CrankTypeB(QObject *parent = 0) : QObject(parent){}
    ~CrankTypeB(){}

    bool consolidateOutputBlock(OutputBlock *compound);
    bool consolidateCrank(Crank *compound);

private:
    Crank *compound1;
    OutputBlock *compound2;
signals:

public slots:
    void somethingBlockConsolidate(OutputBlock *compound);
};

#endif // CRANKTYPEB_H
