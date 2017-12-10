#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include <initializer_list>


class Frame : public QObject
{
Q_OBJECT
public:
    Frame();
    ~Frame();

    std::initializer_list<float> getPoints();
    int getPointsCount();
private:
    int pointsCount;
};

#endif // FRAME_H
