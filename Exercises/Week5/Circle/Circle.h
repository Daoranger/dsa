#ifndef CIRCLE_H
#define CIRCLE_H

const double PI = 3.14;

class Circle
{
public:
    Circle(const double& radius);
    double getRadius() const;
    void setRadius(double radius);
    double area();      // pir^2
    double perimeter(); // 2pir

    void print(int x = 5);

private:
    double m_radius;

};

#endif
