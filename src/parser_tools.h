#pragma once

#include <QString>
#include <QVector3D>
#include <QRegExp>
#include <QDebug>
#include <QVector3D>

#include <numbers>

namespace pt
{
QList<QString> parseCodes(QList<QString> args, char code);
double parseCoord(QList<QString> argList, char c);
QVector3D updatePointWithCommand(QVector3D initial, double x, double y, double z, bool absoluteMode);
QVector3D updatePointWithCommand(QList<QString> commandArgs, QVector3D initial, bool absoluteMode);
}