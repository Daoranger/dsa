#include "XYZPoint.h"
#include <iostream>

int main()
{
    XYZPoint point1(2, 3, 4);

    std::cout << "Postfix:" << point1++;
    std::cout << "Prefix:" << ++point1;
}