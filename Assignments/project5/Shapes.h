#ifndef CMPE180A_SHAPES_H
#define CMPE180A_SHAPES_H

#include <vector>

class XYPoint
{
public:
    
    int x;
    int y;

    XYPoint(int xc, int yc);
};

float distance(const XYPoint& p1, const XYPoint& p2);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4, const XYPoint& p5);

class Shape
{
public:
    virtual ~Shape();
    virtual double area() = 0;
};

void ShapeSorter(std::vector<Shape*>& shapes);

constexpr double PI = 3.14159265359;

class Circle : public Shape
{
public:
    Circle(XYPoint center, double radius);
    ~Circle() override;
    double area() override;

private:
    XYPoint center_;
    double radius_;
};

class Triangle : public Shape
{
public:
    Triangle(XYPoint a, XYPoint b, XYPoint c);
    ~Triangle() override;
    double area() override;

private:
    XYPoint a_;
    XYPoint b_;
    XYPoint c_;
};

class Rectangle : public Shape
{
public:
    Rectangle(XYPoint a, XYPoint b, XYPoint c, XYPoint d);
    ~Rectangle() override;
    double area() override;

private:
    XYPoint a_;
    XYPoint b_;
    XYPoint c_;
    XYPoint d_;
};



#endif //CMPE180A_SHAPES_H
