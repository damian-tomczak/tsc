#pragma once

#include "point_segment.hpp"
#include "parser_tools.h"

#include <QObject>
#include <QVector3D>
#include <QListIterator>

class GcodeParser final : public QObject
{
    Q_OBJECT

public:
    explicit GcodeParser(QObject* pParent = nullptr) : QObject{ pParent } { mPoints.append(new PointSegment(&mCurrentPoint)); }
    ~GcodeParser();

    void reset();
    QList<PointSegment*> getPointSegmentList() { return mPoints; }
    PointSegment* addCommand(QString command);

private:
    bool mIsAbsoluteMode{true};
    QVector3D mCurrentPoint;

    double mLastSpeed{};
    double mTraverseSpeed{300};

    QList<PointSegment*> mPoints;

    PointSegment* processCommand(QList<QString> args);
    PointSegment* handleGCode(QString code, QList<QString> args);
    PointSegment* addLinearPointSegment(QVector3D nextPoint, bool fastTraverse);
};

