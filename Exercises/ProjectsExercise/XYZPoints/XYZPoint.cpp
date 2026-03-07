#include "XYZPoint.h"

XYZPoint::XYZPoint(double x, double y, double z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

void XYZPoint::printXYZ() const
{
    std::cout << "x=" << m_x
        << ", y=" << m_y
        << ", z=" << m_z 
        << "\n";
}

XYZPoint XYZPoint::operator+(const XYZPoint& other) const
{
    return XYZPoint(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

XYZPoint XYZPoint::operator-() const
{
    return {-m_x, -m_y, -m_z};
}

bool XYZPoint::operator!() const
{
    return m_x == 0 && m_y == 0 && m_z == 0;
}

XYZPoint XYZPoint::operator+() const
{
    return *this;
}

bool XYZPoint::operator==(const XYZPoint& rhs) const
{
    return (m_x == rhs.m_x) && (m_y == rhs.m_y) && (m_z == rhs.m_z);
}

bool XYZPoint::operator!=(const XYZPoint& rhs) const
{
    return (m_x != rhs.m_x) || (m_y != rhs.m_y) || (m_z != rhs.m_z);
}

// Prefix
XYZPoint& XYZPoint::operator++()
{
    ++m_x;
    ++m_y;
    ++m_z;

    return *this;
}

// Postfix
XYZPoint XYZPoint::operator++(int)
{
    XYZPoint temp {*this};  // create a temporary object
    ++(*this);              // reuse the prefix I made above!
    return temp;            // return by value (copy of the temporary object)
                            // If we returned a reference to temp, it would become a dangling reference
                            // because temp is destroyed when the function exits.   
}

// XYZPoint operator+(const XYZPoint& p1, const XYZPoint& p2)
// {
//     return XYZPoint(p1.m_x + p2.m_x, p1.m_y + p2.m_y, p1.m_z + p2.m_z);
// }

// XYZPoint operator-(const XYZPoint& p1, const XYZPoint& p2)
// {
//     return XYZPoint(p1.m_x - p2.m_x, p1.m_y - p2.m_y, p1.m_z - p2.m_z);
// }

// XYZPoint operator+(const XYZPoint& p, int v1)
// {
//     return XYZPoint(p.m_x + v1, p.m_y + v1, p.m_z + v1);
// }

// XYZPoint operator+(int v1, const XYZPoint& p)
// {
//     return XYZPoint(v1 + p.m_x, v1 + p.m_y, v1 + p.m_z);
// }

std::ostream& operator<<(std::ostream& out, const XYZPoint& p)
{
    out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")\n";
    return out;
}

// std::istream& operator>>(std::istream& in, XYZPoint& p)
// {
//     double x {};
//     double y {};
//     double z {};

//     if (in >> x >> y >> z)
//     {
//         p = XYZPoint{x, y, z};
//     }

//     return in;
// }