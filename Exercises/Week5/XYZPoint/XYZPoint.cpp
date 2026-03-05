#include "XYZPoint.h"

XYZPoint::XYZPoint(int x, int y, int z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

XYZPoint XYZPoint::operator+ (const XYZPoint& rhs) const
{
    return XYZPoint {m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z};
}

