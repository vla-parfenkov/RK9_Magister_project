#include "frame.h"

Frame::Frame(QOpenGLShaderProgram *program,
int vertexAttr, int colorAttr) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_colorAttr( colorAttr )
{
    initFrame();
    initColor();
}


Frame::~Frame()
{

}

void Frame::initFrame()
{
   float arr[] = { 0.0f, 0.0f, 0.0f,
                 0.1f, 0.0f, 0.0f,
                 0.1f, 0.1f, 0.0f,
                 0.0f, 0.1f, 0.0f,
                 0.0f, 0.0f, 0.1f,
                 0.1f, 0.0f, 0.1f,
                 0.1f, 0.1f, 0.1f,
                 0.0f, 0.1f, 0.1f
               };

   m_vertices.resize( POINT_COUNT * DIMENSION );

   for (int i = 0; i < POINT_COUNT * DIMENSION; i++) {
       m_vertices[i] = arr[i];
   }

}

void Frame::initColor()
{
    int rgbCount = 3;

    m_colors.assign( rgbCount, 0.0f );

}

void Frame::draw()
{
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), DIMENSION );
    m_program->setAttributeArray( m_colorAttr, m_colors.data(), DIMENSION );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_colorAttr );

    glDrawArrays( GL_LINES, 0, m_vertices.size() / DIMENSION );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_colorAttr );
}
