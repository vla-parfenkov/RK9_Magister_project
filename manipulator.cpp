#include "manipulator.h"
#include <QQuaternion>

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
    slideBlockX1 = new SlideBlock(AXIS_X, 0.1f);
    slideBlockX2 = new SlideBlock(AXIS_X, 0.3f);
    slideBlockY1 = new SlideBlock(AXIS_Y, 0.1f);
    slideBlockY2 = new SlideBlock(AXIS_Y, 0.3f);
    slideBlockZ1 = new SlideBlock(AXIS_Z, 0.1f);
    slideBlockZ2 = new SlideBlock(AXIS_Z, 0.3f);
    crankAX1 = new CrankTypeA();
    crankAX2 = new CrankTypeA();
    crankAY1 = new CrankTypeA();
    crankAY2 = new CrankTypeA();
    crankAZ1 = new CrankTypeA();
    crankAZ2 = new CrankTypeA();
    crankBX1 = new CrankTypeB();
    crankBX2 = new CrankTypeB();
    crankBY1 = new CrankTypeB();
    crankBY2 = new CrankTypeB();
    crankBZ1 = new CrankTypeB();
    crankBZ2 = new CrankTypeB();
    outputBlock = new OutputBlock(QVector3D(0.5f, 0.5f, 0.5f),
                                  QQuaternion().fromEulerAngles(0.0f, 0.0f, 0.0f));

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
