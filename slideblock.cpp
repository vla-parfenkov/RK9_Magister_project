#include "slideblock.h"

SlideBlock::SlideBlock(Axis axis, float position, QObject *parent) : QObject(parent)
{
    this->axis = axis;
    this->position = position;
    position = 0;
}

void SlideBlock::moveCompound(float newPosition)
{
    position = newPosition;
    emit moveSlide(position);
}
