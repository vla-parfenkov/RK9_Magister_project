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
    std::vector<SlideBlock*> slideBlocks;
    std::vector<CrankTypeA*> cranksA;
    std::vector<CrankTypeB*> cranksB;
    OutputBlock *outputBlock;
};

#endif // MANIPULATOR_H
