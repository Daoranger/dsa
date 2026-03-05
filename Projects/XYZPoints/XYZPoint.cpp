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

XYZPoint operator+(const XYZPoint& p1, const XYZPoint& p2)
{
    return XYZPoint(p1.m_x + p2.m_x, p1.m_y + p2.m_y, p1.m_z + p2.m_z);
}

XYZPoint operator-(const XYZPoint& p1, const XYZPoint& p2)
{
    return XYZPoint(p1.m_x - p2.m_x, p1.m_y - p2.m_y, p1.m_z - p2.m_z);
}

XYZPoint operator+(const XYZPoint& p, int v1)
{
    return XYZPoint(p.m_x + v1, p.m_y + v1, p.m_z + v1);
}

XYZPoint operator+(int v1, const XYZPoint& p)
{
    return XYZPoint(v1 + p.m_x, v1 + p.m_y, v1 + p.m_z);
}

std::ostream& operator<<(std::ostream& out, const XYZPoint& p)
{
    out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")\n";
    return out;
}

std::istream& operator>>(std::istream& in, XYZPoint& p)
{
    double x {};
    double y {};
    double z {};

    if (in >> x >> y >> z)
    {
        p = XYZPoint{x, y, z};
    }

    return in;
}