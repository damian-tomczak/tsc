#include "gcode_view_parser.h"

void GcodeViewParser::reset()
{
    for (const auto ls : lines)
    {
        delete ls;
    }

    lines.clear();
}

void GcodeViewParser::getLinesFromParser(GcodeParser* pGp)
{
    reset();

    auto psl = pGp->getPointSegmentList();

    QVector3D* pStart{}, * pEnd{};

    for (const auto ps : psl)
    {
        pEnd = ps->getPoint();

        if (pStart != nullptr)
        {
            auto ls = new LineSegment(*pStart, *pEnd);
            ls->setIsFastTraverse(ps->isFastTraverse());
            lines.append(ls);
        }
        pStart = pEnd;
    }
}
