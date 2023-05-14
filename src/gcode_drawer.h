#pragma once

#include "line_segment.hpp"
#include "gcode_view_parser.h"
#include "graph.h"

#include <QObject>
#include <QVector3D>

#include <numbers>

class GcodeDrawer : public Drawable
{
    Q_OBJECT

public:
    explicit GcodeDrawer(QObject* pParent, GcodeViewParser& gcodeViewParser_) :
        Drawable{ pParent },
        mGcodeViewParser{ gcodeViewParser_ }
    {}

    void draw();

private:
    static constexpr auto lineWidth{ 1 };

    GcodeViewParser& mGcodeViewParser;
};
