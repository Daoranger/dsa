#include "Circle.h"
#include <iostream>

Circle::Circle(const double& radius)
    : m_radius(radius)
{

}

double Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}

double Circle::area()
{
    return PI * m_radius * m_radius;
}

double Circle::perimeter()
{
    return 2 * PI * m_radius;
}

void Circle::print(int x = 7)
{
    std::cout << x << "\n";
}
