/**
 * Shapes.cc
 *
 * Author: Hoang Nguyen
 * Date created: 4/26/2026
 * Last modified: 5/3/2026
 *
 * Contained implementations of XYPoint, Shape, Circle, Triangle, Rectangle
 * and ShapeSorter function.
 */

#include "Shapes.h"
#include <algorithm>
#include <cmath>

Shape::~Shape()
{
}

void ShapeSorter(std::vector<Shape*>& shapes)
{
    std::sort(shapes.begin(), shapes.end(), ShapeAreaComparator());
}

Circle::Circle(XYPoint center, double radius)
    : center_(center)
    , radius_(radius)
{
}

Circle::~Circle()
{
}

double Circle::area() const
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

double Triangle::area() const
{
    // Shoelace formula for triangle area
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

double Rectangle::area() const
{
    double l = distance(a_, b_);
    double w = distance(a_, d_);
    return l * w;
}



