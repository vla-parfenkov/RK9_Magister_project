#include <QMatrix4x4>
#include "scene.h"
#include <cmath>
#include <QMouseEvent>
#include <QtMath>
#include <QWheelEvent>
#include <QDebug>

#define DEGRE_WHEEL_MOUSE_INC 0.001f

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

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LESS);


     m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/vshad.vsh");
     m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/fshad.fsh");

    if ( !m_program.link() ) {
        qWarning( "Error: unable to link a shader program." );
        return;
    }
    m_vertexAttr = m_program.attributeLocation( "qt_Vertex" );
    m_colorAttr = m_program.attributeLocation( "qt_MultiTexCoord0" );
    m_matrixUniform = m_program.uniformLocation( "qt_ModelViewProjectionMatrix" );

    m_frame = new Manipulator( &m_program, m_vertexAttr, m_colorAttr );
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if ( !m_program.bind() ) {
            return;
    }

    QMatrix4x4 matrix;
    matrix.lookAt(QVector3D(scale*(float)sin((float)y_rotate * M_PI / 180.0f),
                            scale*(float)sin((float)x_rotate * M_PI / 180.0f),
                            scale*(float)cos((float)y_rotate * M_PI / 180.0f)*(float)cos((float)x_rotate * M_PI / 180.0f)),
                  QVector3D(0,0,0), QVector3D(0,1.0f,0));
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_frame->draw();

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::mouseMoveEvent(QMouseEvent *event)
{
    if (x_mouse_position == 45) {
        x_mouse_position = event->x();
    }
    if (y_mouse_position == 45) {
        y_mouse_position = event->y();
    }
    y_rotate = event->x() - x_mouse_position;
    x_rotate = event->y() - y_mouse_position;
    this->update();

}

void Scene::wheelEvent(QWheelEvent *event)
{
    float scaleInc = (float)event->delta() * DEGRE_WHEEL_MOUSE_INC;
    scale += scaleInc;
    this->update();
}

