
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

class Shape
{
public:
    virtual ~Shape() = 0;
    virtual double area() = 0;

    void ShapeSorter(std::vector<Shape*>& shapes);

};



#endif //CMPE180A_SHAPES_H
