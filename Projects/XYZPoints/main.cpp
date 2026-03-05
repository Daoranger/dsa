#include "XYZPoint.h"
#include <iostream>

int main()
{
    XYZPoint point1(1, 1, 1);
    XYZPoint point2(2, 3, 4);
    XYZPoint point3(11 + point1);

    point3.printXYZ();

    std::cout << point3;

    std::cin >> point3;

    std::cout << point3;
}