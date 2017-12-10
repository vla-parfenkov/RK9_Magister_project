#ifndef OUTPUTBLOCK_H
#define OUTPUTBLOCK_H

#include <QObject>
#include <cranktypeb.h>
#include <QVector3D>
#include <vector>
#include <QQuaternion>

class CrankTypeB;

class OutputBlock : public QObject
{
    Q_OBJECT
public:
    explicit OutputBlock(QVector3D position, QQuaternion anglePosition,
                         QObject *parent = 0);
    void consolidateCrank(int compoundNumber, CrankTypeB *compound);
    QVector3D getcompoundPosition(CrankTypeB *compound);
private:
    QVector3D position;
    QQuaternion anglePosition;
    std::vector<CrankTypeB*> compounds;
    std::vector<QVector3D> compoundPosition;
    void compoundPositionInit();
signals:
    void consolidateComplited(OutputBlock*);
public slots:
};

#endif // OUTPUTBLOCK_H
