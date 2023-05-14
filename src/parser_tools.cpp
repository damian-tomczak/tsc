#include "parser_tools.h"

namespace pt
{
QList<QString> parseCodes(QList<QString> args, char code)
{
    QList<QString> l;
    char address{ static_cast<QChar>(code).toUpper().toLatin1() };

    for (auto s : args)
    {
        if (s.length() > 0 && s.at(0).toUpper().toLatin1() == address)
        {
            l.append(s.mid(1));
        }
    }

    return l;
}

QVector3D updatePointWithCommand(QList<QString> commandArgs, QVector3D initial, bool absoluteMode)
{
    return updatePointWithCommand(initial,
        parseCoord(commandArgs, 'X'),
        parseCoord(commandArgs, 'Y'),
        parseCoord(commandArgs, 'Z'),
        absoluteMode);
}

QVector3D updatePointWithCommand(QVector3D initial, double x, double y, double z, bool absoluteMode)
{
    QVector3D newPoint{ initial.x(), initial.y(), initial.z() };

    if (absoluteMode)
    {
        if (!isnan(x))
        {
            newPoint.setX(x);
        }
        if (!isnan(y))
        {
            newPoint.setY(y);
        }
        if (!isnan(z))
        {
            newPoint.setZ(z);
        }
    }
    else
    {
        if (!isnan(x))
        {
            newPoint.setX(newPoint.x() + x);
        }
        if (!isnan(y))
        {
            newPoint.setY(newPoint.y() + y);
        }
        if (!isnan(z))
        {
            newPoint.setZ(newPoint.z() + z);
        }
    }

    return newPoint;
}

double parseCoord(QList<QString> args, char c)
{
    char address = QChar(c).toUpper().toLatin1();
    for (auto t : args)
    {
        if (t.length() > 0 && t.at(0).toUpper().toLatin1() == address)
        {
            return t.mid(1).toDouble();
        }
    }
    return std::numeric_limits<double>::quiet_NaN();
}
}