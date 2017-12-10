#include "manipulator.h"
#include <QQuaternion>

#define SLIDEBLOCK_COUNT 6
#define CRANK_COUNT 6


Manipulator::Manipulator(QOpenGLShaderProgram *program,
int vertexAttr, int colorAttr) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_colorAttr( colorAttr )
{
    initElement();
    initFrame();
    initColor();
}


Manipulator::~Manipulator()
{
    delete(frame);
    delete(outputBlock);
}

void Manipulator::initFrame()
{
   m_vertices.insert(m_vertices.end(), frame->getPoints().begin(), frame->getPoints().end());
}

void Manipulator::initColor()
{
    int rgbCount = 3;

    m_colors.assign( rgbCount, 0.0f );

}

void Manipulator::initElement()
{
    frame = new Frame();
    slideBlocks.resize(SLIDEBLOCK_COUNT);
    cranksA.resize(CRANK_COUNT);
    cranksB.resize(CRANK_COUNT);
    slideBlocks.at(0) = new SlideBlock(AXIS_X, 0.1f);
    slideBlocks.at(1) = new SlideBlock(AXIS_X, 0.3f);
    slideBlocks.at(2) = new SlideBlock(AXIS_Y, 0.1f);
    slideBlocks.at(3) = new SlideBlock(AXIS_Y, 0.3f);
    slideBlocks.at(4) = new SlideBlock(AXIS_Z, 0.1f);
    slideBlocks.at(5) = new SlideBlock(AXIS_Z, 0.3f);
    outputBlock = new OutputBlock(QVector3D(0.5f, 0.5f, 0.5f),
                                  QQuaternion().fromEulerAngles(0.0f, 0.0f, 0.0f));
    for (int i = 0; i < CRANK_COUNT; i++) {
            cranksA.at(i) = new CrankTypeA();
            cranksB.at(i) = new CrankTypeB();
            outputBlock->consolidateCrank(i + 1, cranksB.at(i));
    }

}

void Manipulator::draw()
{
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), DIMENSION );
    m_program->setAttributeArray( m_colorAttr, m_colors.data(), DIMENSION );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_colorAttr );

    glDrawArrays( GL_LINES, 0, m_vertices.size() / DIMENSION );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_colorAttr );
}
