#include "frame.h"

#define DIMENSION 3
#define POINT_COUNT 24

Frame::Frame()
{
    pointsCount = POINT_COUNT * DIMENSION;
}

Frame::~Frame()
{
}

std::initializer_list<float>Frame::getPoints()
{
    return {
        //1
                  0.0f, 0.0f, 0.0f,
                  1.0f, 0.0f, 0.0f,
        //2
                  1.0f, 0.0f, 0.0f,
                  1.0f, 1.0f, 0.0f,
        //3
                  1.0f, 1.0f, 0.0f,
                  0.0f, 1.0f, 0.0f,
        //4
                  0.0f, 1.0f, 0.0f,
                  0.0f, 0.0f, 0.0f,
        //5
                  0.0f, 0.0f, 1.0f,
                  1.0f, 0.0f, 1.0f,
        //6
                  1.0f, 0.0f, 1.0f,
                  1.0f, 1.0f, 1.0f,
        //7
                  1.0f, 1.0f, 1.0f,
                  0.0f, 1.0f, 1.0f,
        //8
                  0.0f, 1.0f, 1.0f,
                  0.0f, 0.0f, 1.0f,
        //9
                  0.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 1.0f,
        //10
                  1.0f, 0.0f, 0.0f,
                  1.0f, 0.0f, 1.0f,
        //11
                  1.0f, 1.0f, 0.0f,
                  1.0f, 1.0f, 1.0f,
        //12
                  0.0f, 1.0f, 0.0f,
                  0.0f, 1.0f, 1.0f
                };
}

int Frame::getPointsCount()
{
    return pointsCount;
}

