#include "Circle.h"
#include <iostream>

int main()
{

    Circle c1(2.5);     // won't accept literal/temporary object

    c1.print();

    // const double r = 1.5;
    // Circle c2(r);       // won't accept const int
    //
    //
    // std::cout << "Circle area is: " << c1.area() << "\n";
    // std::cout << "Circle perimeter is: " << c1.perimeter() << "\n";

}