#pragma once

#include "graph.h"

class ToolDrawer final : public Drawable
{
    Q_OBJECT

public:
    explicit ToolDrawer(QObject* pParent = nullptr) : Drawable{ pParent }
    {}

    void draw() override;
    void setToolPosition(const QVector3D& toolPosition) { mToolPosition = toolPosition; }

private:
    QVector3D mToolPosition;
    double mToolDiameter{ 3 };
};
