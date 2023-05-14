#include "graph.h"

void Graph::paintGL()
{
    makeCurrent();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    qglClearColor(QColor(Qt::white));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    updateProjection();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    double angXRad{ 90 * (std::numbers::pi / 180) };
    double angYRad{ std::numbers::pi / 180 };

    double viewerX{ mDistance * cos(angXRad) * sin(angYRad) };
    double viewerY{ mDistance * sin(angXRad) };
    double viewerZ{ mDistance * cos(angXRad) * cos(angYRad) };

    double objectX{}, objectY{}, objectZ{};

    double upX{ -sin(angYRad) };
    double upY{ cos(angXRad) };
    double upZ{ -cos(angYRad) };

    gluLookAt(
        viewerX, viewerY, viewerZ,
        objectX, objectY, objectZ,
        upX,     upY,     upZ
    );

    glRotatef(-90, 1.0, 0.0, 0.0);

    glLineWidth(mLineWidth);

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(9, 0, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(10, 0, 0);
    glVertex3f(8, 0.5, 0);
    glVertex3f(8, -0.5, 0);
    glVertex3f(10, 0, 0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 9, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 10, 0);
    glVertex3f(-0.5, 8, 0);
    glVertex3f(0.5, 8, 0);
    glVertex3f(0, 10, 0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 10);
    glVertex3f(-0.5, 0, 8);
    glVertex3f(0.5, 0, 8);
    glVertex3f(0, 0, 10);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glEnd();

    for (auto const pDr : mDrawables)
    {
        pDr->draw();
    }

    update();
}

void Graph::updateProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    auto ratio{ static_cast<double>(width()) / height() };
    glFrustum(-0.5 * ratio, 0.5 * ratio, -0.5, 0.5, 2, mDistance * 2);

    glMatrixMode(GL_MODELVIEW);
}
