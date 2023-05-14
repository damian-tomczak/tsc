#pragma once

#include "line_segment.hpp"
#include "gcode_parser.h"

#include <QObject>
#include <QVector3D>

class GcodeViewParser final : public QObject
{
    Q_OBJECT

public:
    explicit GcodeViewParser(QObject* pParent = nullptr) : QObject { pParent }
    {}
    ~GcodeViewParser() { reset(); }

    QList<LineSegment*> getLineSegmentList() { return lines; };
    void getLinesFromParser(GcodeParser* pGp);

private:
    void reset();

    QList<LineSegment*> lines;
    QVector3D lastPoint;
};

