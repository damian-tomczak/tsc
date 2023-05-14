#include "gcode_drawer.h"

void GcodeDrawer::draw()
{
    for (auto ls : mGcodeViewParser.getLineSegmentList())
    {
        glLineWidth(lineWidth);

        if (ls->isFastTraverse())
        {
            glLineStipple(1, 0x00ff);
            glEnable(GL_LINE_STIPPLE);
        }

        glColor3f(0.0, 0.0, 0.0);

        glBegin(GL_LINES);
        auto start{ ls->getStart() };
        auto end{ ls->getEnd() };
        glVertex3f(start.x(), start.y(), start.z());
        glVertex3f(end.x(), end.y(), end.z());
        glEnd();

        glDisable(GL_LINE_STIPPLE);
    }
}