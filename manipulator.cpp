#include "manipulator.h"

Manipulator::Manipulator(QOpenGLShaderProgram *program,
int vertexAttr, int colorAttr) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_colorAttr( colorAttr )
{
    initFrame();
    initColor();
}


Manipulator::~Manipulator()
{

}

void Manipulator::initFrame()
{
   float arr[] = {
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

   m_vertices.resize( POINT_COUNT * DIMENSION );

   for (int i = 0; i < POINT_COUNT * DIMENSION; i++) {
       m_vertices[i] = arr[i];
   }

}

void Manipulator::initColor()
{
    int rgbCount = 3;

    m_colors.assign( rgbCount, 0.0f );

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
