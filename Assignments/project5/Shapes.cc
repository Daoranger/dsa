#include "Shapes.h"

#include <cmath>

XYPoint::XYPoint(int xc, int yc)
    : x(xc)
    , y(yc)
{
}

float distance(const XYPoint& p1, const XYPoint& p2)
{
    float dx = static_cast<float>(p2.x) - static_cast<float>(p1.x);
    float dy = static_cast<float>(p2.y) - static_cast<float>(p1.y);
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

Shape::~Shape()
{
}

Circle::Circle(XYPoint center, double radius)
    : center_(center)
    , radius_(radius)
{
}

Circle::~Circle()
{
}

double Circle::area()
{
    return PI * radius_ * radius_;
}

Triangle::Triangle(XYPoint a, XYPoint b, XYPoint c)
    : a_(a)
    , b_(b)
    , c_(c)
{
}

Triangle::~Triangle()
{
}

double Triangle::area()
{
    // Shoelace formula for triangle
    return std::abs(((a_.x * b_.y) + (b_.x * c_.y) + (c_.x * a_.y)) - ((a_.y * b_.x) + (b_.y * c_.x) + (c_.y * a_.x))) / 2.0;
}

Rectangle::Rectangle(XYPoint a, XYPoint b, XYPoint c, XYPoint d)
    : a_(a)
    , b_(b)
    , c_(c)
    , d_(d)
{
}

Rectangle::~Rectangle()
{
}

double Rectangle::area()
{
    double l = distance(a_, b_);
    double w = distance(a_, d_);
    return l * w;
}



