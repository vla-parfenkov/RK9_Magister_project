#include "scene.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget ( parent )
{

}

Scene::~Scene()
{
     delete m_frame;
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vshader.vsh" );


    m_program.addShader( &vShader );
    if ( !m_program.link() ) {
        qWarning( "Error: unable to link a shader program." );
        return;
    }

    m_vertexAttr = m_program.attributeLocation( "qt_Vertex" );
    m_colorAttr = m_program.attributeLocation( "qt_MultiTexCoord0" );
    m_matrixUniform = m_program.uniformLocation( "qt_ModelViewProjectionMatrix" );

    m_frame = new Frame( &m_program, m_vertexAttr, m_colorAttr );
}

void Scene::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    if ( !m_program.bind() ) {
            return;
    }

    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f );
    matrix.translate( 0.0f, 0.0f, -1.0f );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_frame->draw();

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

