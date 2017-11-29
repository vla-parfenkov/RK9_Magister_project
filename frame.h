#ifndef FRAME_H
#define FRAME_H

#define POINT_COUNT 8
#define DIMENSION 3

#include <vector>
#include<QOpenGLShaderProgram>

class Frame
{
public:
    Frame( QOpenGLShaderProgram *program,
          int vertexAttr, int colorAttr );
    ~Frame();

    void draw();

private:
    void initFrame();
    void initColor();

    std::vector<float> m_vertices;
    std::vector<float> m_colors;

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;
};

#endif // FRAME_H
