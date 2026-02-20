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
};

float distance(const XYPoint& p1, const XYPoint& p2);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4);
float distance(const XYPoint& p1, const XYPoint& p2, const XYPoint& p3, const XYPoint& p4, const XYPoint& p5);



#endif //PROJECT2_XYPOINT_H