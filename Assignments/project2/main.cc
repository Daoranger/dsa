#include <iomanip>
#include <iostream>
#include "XYPoint.h"

int main()
{
    XYPoint point1(11, 1);
    XYPoint point2(4, 5);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Distance between point 1 and point 2 is " << distance(point1, point2) << "\n";
}