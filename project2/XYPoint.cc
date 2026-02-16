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

float distance(XYPoint p1, XYPoint p2)
{
    return sqrtf(powf(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
