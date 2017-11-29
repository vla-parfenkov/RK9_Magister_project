#include "scene.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget ( parent )
{

}

Scene::~Scene()
{

}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
}

void Scene::initializeGL()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
}

void Scene::resizeGL( int w, int h )
{

}

