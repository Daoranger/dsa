#include <iostream>
#include "XYZPoint.h"

int main()
{
    XYZPoint point1(1, 1, 1);
    XYZPoint point2(2, 2, 2);

    XYZPoint point3(point1 + point2);

    std::cout << "Point 3:" << "x=" << point3.m_x << " y=" << point3.m_y << " z=" << point3.m_z << "\n";
}