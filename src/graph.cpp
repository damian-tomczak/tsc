#include "graph.h"

Graph::Graph(QWidget* pParent) : QGLWidget{pParent}
{

}

void Graph::addDrawable(Drawable* pDrawable)
{

}

void Graph::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Graph::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = GLfloat(w) / GLfloat(h);
    gluPerspective(45.0, aspect, 0.1, 100.0);
}

void Graph::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -6.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
}
