/**
 * Shapes.h
 *
 * Author: Hoang Nguyen
 * Date created: 4/26/2026
 * Last modified: 5/3/2026
 *
 * Contained definition of XYPoint class
 * Shape base class, and Circle, Triangle and Rectangle derived classes
 * ShapeAreaComparator struct that have a functor to sort Shape pointers
 * by area.
 * ShapeSorter function that use std::sort and ShapeAreaComparator functor
 * to sort the std::vector<Shape*> by area in increasing order.
 */

#ifndef CMPE180A_SHAPES_H
#define CMPE180A_SHAPES_H

#include <vector>

//-------------------- XYPoint class --------------------//
class XYPoint
{
public:
    
    int x;
    int y;

    XYPoint(int xc, int yc);
};

double distance(const XYPoint& p1, const XYPoint& p2);
double distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3);
double distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4);
double distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4, const XYPoint& p5);

//-------------------- Shape class --------------------//
class Shape
{
public:
    virtual ~Shape();
    virtual double area() const = 0;
};

struct ShapeAreaComparator
{
    bool operator()(Shape* a, Shape* b) const
    {
        return a->area() < b->area();
    }
};

void ShapeSorter(std::vector<Shape*>& shapes);


//-------------------- Circle class --------------------//

// for circle area
constexpr double PI = 3.14159265359;

class Circle : public Shape
{
public:
    Circle(XYPoint center, double radius);
    ~Circle() override;
    double area() const override;

private:
    XYPoint center_;
    double radius_;
};

//-------------------- Triangle class --------------------//
class Triangle : public Shape
{
public:
    Triangle(XYPoint a, XYPoint b, XYPoint c);
    ~Triangle() override;
    double area() const override;

private:
    XYPoint a_;
    XYPoint b_;
    XYPoint c_;
};

//-------------------- Rectangle class --------------------//
class Rectangle : public Shape
{
public:
    Rectangle(XYPoint a, XYPoint b, XYPoint c, XYPoint d);
    ~Rectangle() override;
    double area() const override;

private:
    XYPoint a_;
    XYPoint b_;
    XYPoint c_;
    XYPoint d_;
};

#endif //CMPE180A_SHAPES_H
