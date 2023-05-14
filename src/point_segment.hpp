#pragma once

#include <QObject>
#include <QVector3D>

struct PointSegment final
{
    PointSegment(PointSegment* ps) : PointSegment(ps->getPoint()) { setIsFastTraverse(ps->isFastTraverse()); }
    PointSegment(const QVector3D* b) { mpPoint = new QVector3D(b->x(), b->y(), b->z()); }
    ~PointSegment()
    {
        if (mpPoint != nullptr)
        {
            delete mpPoint;
        }
    }

    void setIsFastTraverse(bool isF) { mIsFastTraverse = isF; }
    bool isFastTraverse() { return mIsFastTraverse; }
    QVector3D* getPoint() { return mpPoint; }

private:
    QVector3D* mpPoint{};
    bool mIsFastTraverse{};
};
