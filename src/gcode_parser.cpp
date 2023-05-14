#include "gcode_parser.h"

GcodeParser::~GcodeParser()
{
    for (const auto ps : mPoints)
    {
        delete ps;
    }
}

void GcodeParser::reset()
{
    for (const auto ps : mPoints)
    {
        delete ps;
    }
    mPoints.clear();
    mPoints.append(new PointSegment(&mCurrentPoint));
}

PointSegment* GcodeParser::addCommand(QString command)
{
    auto args{ command.split(" ") };
    if (args.isEmpty())
    {
        return nullptr;
    }
    return processCommand(args);
}

PointSegment* GcodeParser::processCommand(QList<QString> args)
{
    PointSegment* ps{};

    auto gCodes = pt::parseCodes(args, 'G');

    for (const auto i : gCodes)
    {
        ps = handleGCode(i, args);
    }

    return ps;
}

PointSegment* GcodeParser::addLinearPointSegment(QVector3D nextPoint, bool fastTraverse)
{
    PointSegment* ps = new PointSegment(&nextPoint);

    ps->setIsFastTraverse(fastTraverse);
    mPoints.append(ps);

    mCurrentPoint = nextPoint;
    return ps;
}

PointSegment* GcodeParser::handleGCode(QString code, QList<QString> args)
{
    PointSegment* ps{};

    QVector3D nextPoint{ pt::updatePointWithCommand(args, mCurrentPoint, mIsAbsoluteMode) };

    double speed = pt::parseCoord(args, 'F');
    if (!isnan(speed))
    {
        mLastSpeed = speed;
    }

    if (code == "0")
    {
        ps = addLinearPointSegment(nextPoint, true);
    }
    else if (code == "1")
    {
        ps = addLinearPointSegment(nextPoint, false);
    }
    else if (code == "90")
    {
        mIsAbsoluteMode = true;
    }
    else if (code == "91")
    {
        mIsAbsoluteMode = false;
    }

    return ps;
}
