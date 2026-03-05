#ifndef XYZPoint_H
#define XYZPoint_H

#include <iostream>

class XYZPoint
{
    
public:
    XYZPoint();
    XYZPoint(double x, double y, double z);
    void printXYZ() const;
    friend XYZPoint operator+(const XYZPoint& p1, const XYZPoint& p2);
    friend XYZPoint operator-(const XYZPoint& p1, const XYZPoint& p2);
    friend XYZPoint operator+(const XYZPoint& p, int v1);
    friend XYZPoint operator+(int v1, const XYZPoint& p);
    friend std::ostream& operator<<(std::ostream& out, const XYZPoint& p);
    friend std::istream& operator>>(std::istream& in, XYZPoint& p);


private:

    double m_x;
    double m_y;
    double m_z; 

};


#endif