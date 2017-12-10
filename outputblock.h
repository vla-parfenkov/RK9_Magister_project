#ifndef OUTPUTBLOCK_H
#define OUTPUTBLOCK_H

#include <QObject>
#include <crank.h>
#include <QVector3D>
#include <vector>
#include <QQuaternion>

class OutputBlock : public QObject
{
    Q_OBJECT
public:
    explicit OutputBlock(QVector3D position, QQuaternion anglePosition,
                         QObject *parent = 0);
private:
    QVector3D position;
    QQuaternion anglePosition;
    Crank *compoundX1;
    Crank *compoundX2;
    Crank *compoundY1;
    Crank *compoundY2;
    Crank *compoundZ1;
    Crank *compoundZ2;
    std::vector<QVector3D> compoundPosition;
    void compoundPositionInit();
signals:

public slots:
};

#endif // OUTPUTBLOCK_H
