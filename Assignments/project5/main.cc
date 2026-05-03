#include <iostream>
#include "Shapes.h"

int main() {
    // Circle tests
    Circle c1(XYPoint(0, 0), 1.0);
    std::cout << "Circle r=1: " << c1.area() << std::endl;

    Circle c2(XYPoint(0, 0), 10.0);
    std::cout << "Circle r=10: " << c2.area() << std::endl;

    Circle c3(XYPoint(0, 0), 5.0);
    std::cout << "Circle r=5: " << c3.area() << std::endl;

    // Triangle tests
    Triangle t1(XYPoint(0, 0), XYPoint(4, 0), XYPoint(0, 3));
    std::cout << "Triangle 1: " << t1.area() << std::endl;

    Triangle t2(XYPoint(0, 0), XYPoint(6, 0), XYPoint(0, 4));
    std::cout << "Triangle 2: " << t2.area() << std::endl;

    Triangle t3(XYPoint(0, 0), XYPoint(1, 0), XYPoint(0, 1));
    std::cout << "Triangle 3: " << t3.area() << std::endl;

    // Rectangle tests
    Rectangle r1(XYPoint(0, 0), XYPoint(4, 0), XYPoint(4, 3), XYPoint(0, 3));
    std::cout << "Rectangle 1: " << r1.area() << std::endl;

    Rectangle r2(XYPoint(0, 0), XYPoint(5, 0), XYPoint(5, 5), XYPoint(0, 5));
    std::cout << "Rectangle 2: " << r2.area() << std::endl;

    Rectangle r3(XYPoint(0, 0), XYPoint(2, 0), XYPoint(2, 1), XYPoint(0, 1));
    std::cout << "Rectangle 3: " << r3.area() << std::endl;

    std::vector<Shape*> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&c2);
    shapes.push_back(&c3);
    shapes.push_back(&t1);
    shapes.push_back(&t2);
    shapes.push_back(&t3);
    shapes.push_back(&r1);
    shapes.push_back(&r2);
    shapes.push_back(&r3);

    std::cout << "\nBefore sorting:\n";
    for (auto& shape : shapes)
    {
        std::cout << shape->area() << ", ";
    }

    ShapeSorter(shapes);

    std::cout << "\nAfter sorting:\n";
    for (auto& shape : shapes)
    {
        std::cout << shape->area() << ", ";
    }

    return 0;
}