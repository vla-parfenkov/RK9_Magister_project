#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include "manipulator.h"

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    Manipulator *m_frame;
    QOpenGLShaderProgram m_program;



    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;

    int x_mouse_position = 0;
    int y_mouse_position = 0;
    int y_rotate = 45;
    int x_rotate = 45;
    float scale = 1.0f;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);

};

#endif // SCENE_H
