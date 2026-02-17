//
// Created by hoang on 2/16/2026.
//

#include "XYPoint.h"
#include <cmath>

XYPoint::XYPoint(int xc, int yc)
    : x(xc)
    , y(yc)
{
}

int XYPoint::getX() const
{
    return x;
}

int XYPoint::getY() const
{
    return y;
}

float distance(const XYPoint& p1, const XYPoint& p2)
{
    float dx = static_cast<float>(p2.x)  - static_cast<float>(p1.x);
    float dy = static_cast<float>(p2.y)  - static_cast<float>(p1.y);
    return std::sqrt(dx * dx + dy * dy);
}

float distance(const XYPoint &p1, const XYPoint &p2, const XYPoint &p3)
{
    return distance(p1, p2) + distance(p2, p3);
}

float distance(const XYPoint &p1, const XYPoint &p2, const XYPoint &p3, const XYPoint &p4)
{
    return distance(p1, p2, p3) + distance(p3, p4);
}

float distance(const XYPoint &p1, const XYPoint &p2, const XYPoint &p3, const XYPoint &p4, const XYPoint &p5)
{
    return distance(p1, p2, p3, p4) + distance(p4, p5);
}
