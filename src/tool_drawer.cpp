#include "tool_drawer.h"

void ToolDrawer::draw()
{
    glColor3f(1.f, .6f, 0.f);

    glBegin(GL_LINE_LOOP);
    for (int i{}; i <= 50; ++i)
    {
        double angle = 2 * std::numbers::pi * i / 50;
        double x = mToolPosition.x() + mToolDiameter / 2 * cos(angle);
        double y = mToolPosition.y() + mToolDiameter / 2 * sin(angle);
        glVertex3f(x, y, mToolPosition.z());
    }
    glEnd();
}
