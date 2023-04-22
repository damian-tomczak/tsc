#pragma once

#include <QObject>
#include <QVector3D>
#include <QGLWidget>
#include "GL/GLU.h"

class Drawable : public QObject
{
    Q_OBJECT

public:
    explicit Drawable(QObject* pParent = nullptr) : QObject(pParent) {};
    virtual void draw() = 0;
};

class Graph final : public QGLWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget* pParent = nullptr);

    void addDrawable(Drawable* pDrawable);
};
