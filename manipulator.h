#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#define DIMENSION 3

#include <vector>
#include<QOpenGLShaderProgram>
#include <frame.h>
#include <slideblock.h>
#include <outputblock.h>
#include <cranktypea.h>
#include <cranktypeb.h>
#include <QObject>

class Manipulator
{
public:
    Manipulator( QOpenGLShaderProgram *program,
          int vertexAttr, int colorAttr );
    ~Manipulator();

    void draw();

private:
    void initFrame();
    void initColor();
    void initElement();


    std::vector<float> m_vertices;
    std::vector<float> m_colors;

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;

    Frame *frame;
    SlideBlock *slideBlockX1;
    SlideBlock *slideBlockX2;
    SlideBlock *slideBlockY1;
    SlideBlock *slideBlockY2;
    SlideBlock *slideBlockZ1;
    SlideBlock *slideBlockZ2;
    CrankTypeA *crankAX1;
    CrankTypeB *crankBX1;
    CrankTypeA *crankAX2;
    CrankTypeB *crankBX2;
    CrankTypeA *crankAY1;
    CrankTypeB *crankBY1;
    CrankTypeA *crankAY2;
    CrankTypeB *crankBY2;
    CrankTypeA *crankAZ1;
    CrankTypeB *crankBZ1;
    CrankTypeA *crankAZ2;
    CrankTypeB *crankBZ2;
    OutputBlock *outputBlock;
};

#endif // MANIPULATOR_H
