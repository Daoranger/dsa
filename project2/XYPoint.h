//
// Created by hoang on 2/16/2026.
//

#ifndef PROJECT2_XYPOINT_H
#define PROJECT2_XYPOINT_H


class XYPoint
{
public:

    int x;
    int y;

    XYPoint(int xc, int yc);
    int getX() const;
    int getY() const;
};

float distance(XYPoint p1, XYPoint p2);


#endif //PROJECT2_XYPOINT_H