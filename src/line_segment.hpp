#pragma once

#include <QVector3D>

struct LineSegment final
{
    LineSegment(QVector3D a, QVector3D b) : mFirst{ a }, mSecond{ b }
    {}

    QVector3D getStart() { return mFirst; }
    QVector3D getEnd() { return mSecond; }

    void setIsFastTraverse(bool isF) { mIsFastTraverse = isF; }
    bool isFastTraverse() { return mIsFastTraverse; }

private:
    QVector3D mFirst, mSecond;
    bool mIsFastTraverse{};
};
