#ifndef CRANKTYPEA_H
#define CRANKTYPEA_H

#include <QObject>
#include <crank.h>
#include <slideblock.h>

class CrankTypeA : public QObject, public Crank
{
Q_OBJECT
public:
    CrankTypeA(QObject *parent = 0) : QObject(parent){}
    ~CrankTypeA(){}

    bool consolidateSlide(SlideBlock *compound);
    bool consolidateCrank(Crank *compound);

private:
    SlideBlock *compound1;
    Crank *compound2;
};

#endif // CRANKTYPEA_H
