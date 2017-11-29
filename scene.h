#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include "frame.h"

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    Frame *m_frame;
    QOpenGLShaderProgram m_program;

    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;

};

#endif // SCENE_H
