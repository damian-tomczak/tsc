#pragma once

#include <QGLWidget>
#include <GL/glu.h>
#include <QVector3D>

#include <numbers>

class Drawable : public QObject
{
    Q_OBJECT

public:
    explicit Drawable(QObject* pParent = nullptr) : QObject{ pParent }
    {};

    virtual void draw() = 0;
};

class Graph final : public QGLWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget* pParent = nullptr) :
        QGLWidget{ pParent }
    {}
    void addDrawable(Drawable* pDrawable) { mDrawables.append(pDrawable); }

private:
    static constexpr double mLineWidth{1};
    double mDistance{ 150 };
    QList<Drawable*> mDrawables;

protected:
    void initializeGL() override {};
    void paintGL() override;
    void resizeGL(int w, int h) override { glViewport(0, 0, w, h);};
    void updateProjection();
};
