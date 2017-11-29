#include <QMatrix4x4>
#include "scene.h"
#include <cmath>

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget ( parent )
{

}

Scene::~Scene()
{
     delete m_frame;
}

void Scene::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );


     m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/vshad.vsh");
     m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/fshad.fsh");

    if ( !m_program.link() ) {
        qWarning( "Error: unable to link a shader program." );
        return;
    }
    m_vertexAttr = m_program.attributeLocation( "qt_Vertex" );
    m_colorAttr = m_program.attributeLocation( "qt_MultiTexCoord0" );
    m_matrixUniform = m_program.uniformLocation( "qt_ModelViewProjectionMatrix" );

    m_frame = new Frame( &m_program, m_vertexAttr, m_colorAttr );
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if ( !m_program.bind() ) {
            return;
    }

    QMatrix4x4 matrix;
    matrix.perspective( 45.0f * 180 / M_PI , 4.0f / 3.0f, 0.1f, 100.0f );
    matrix.lookAt(QVector3D(4,3,0), QVector3D(0,0,0), QVector3D(0,1,0));
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_frame->draw();

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

