#include "outputblock.h"


#define COMPOUND_COUNT 6


OutputBlock::OutputBlock(QVector3D position,
                         QQuaternion anglePosition, QObject *parent) : QObject(parent)
{
    this->position = position;
    this->anglePosition = anglePosition;
    compoundPositionInit();
}

void OutputBlock::compoundPositionInit()
{
    compoundPosition.resize(COMPOUND_COUNT);
    compoundPosition[0] = QVector3D(position.x() - 0.05f, position.y(), position.z() + 0.06f);
    compoundPosition[1] = QVector3D(position.x() + 0.05f, position.y(), position.z() + 0.06f);
    compoundPosition[2] = QVector3D(position.x(), position.y() + 0.05f, position.z() + 0.11f);
    compoundPosition[3] = QVector3D(position.x(), position.y() - 0.05f, position.z() + 0.11f);
    compoundPosition[4] = QVector3D(position.x(), position.y(), position.z() + 0.1f);
    compoundPosition[5] = QVector3D(position.x(), position.y(), position.z() + 0.11f);
    for (int i = 0; i < COMPOUND_COUNT; i++) {
        compoundPosition[i] =  anglePosition.rotatedVector(compoundPosition[i]);
    }
}
