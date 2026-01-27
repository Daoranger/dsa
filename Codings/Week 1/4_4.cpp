/**
 * Section 4.4: Overloading Functions
 */

#include <iostream>

int print(int x);
double print(double x);

double average(double x, double y)
{
    return (x + y) / 2.0;
}

double average(double x, double y, double z)
{
    return (x + y + z) / 3.0;
}

int main()
{
    std::cout << "average(2)=" << average(11, 11) << '\n';
    std::cout << "average(3)=" << average(11, 22, 33) << '\n';
}