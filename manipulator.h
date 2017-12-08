#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#define POINT_COUNT 24
#define DIMENSION 3

#include <vector>
#include<QOpenGLShaderProgram>

class Manipulator
{
public:
    Manipulator( QOpenGLShaderProgram *program,
          int vertexAttr, int colorAttr );
    ~Manipulator();

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

#endif // MANIPULATOR_H
