#ifndef _XYZPoint_H_
#define _XYZPoint_H_

class XYZPoint
{

public:

    XYZPoint(int x, int y, int z);
    XYZPoint operator+(const XYZPoint& rhs) const;

    int m_x;
    int m_y;
    int m_z;
};

#endif 