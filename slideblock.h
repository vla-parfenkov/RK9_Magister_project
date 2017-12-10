#ifndef SLIDEBLOCK_H
#define SLIDEBLOCK_H

#include <QObject>

enum Axis {AXIS_X, AXIS_Y, AXIS_Z};

class SlideBlock : public QObject
{
    Q_OBJECT
public:
    explicit SlideBlock(Axis axis, float position, QObject *parent = Q_NULLPTR);

private:
    Axis axis;
    float position;

signals:
    void moveSlide(float newPosition);
public slots:
    void moveCompound(float newPosition);
};

#endif // SLIDEBLOCK_H
