#include <gtest/gtest.h>
#include "XYPoint.h"

TEST(XYPointMethodTest, GetX)
{
    XYPoint point(3, 5);
    EXPECT_EQ(point.getX(), 3);
}

TEST(XYPointMethodTest, GetY)
{
    XYPoint point(3, 5);
    EXPECT_EQ(point.getY(), 5);
}

TEST(DistanceTest, TwoPoints)
{
    XYPoint point1(2, 2);
    XYPoint point2(4, 4);
    const float d = distance(point1, point2);
    // difference between actual and expected and then check it with tolerance
    // difference <= tolerance (pass), difference > tolerance (fail)
    EXPECT_NEAR(d, 2.8284271247462, 1e-6);
}

TEST(DistanceTest, ThreePoints)
{
    XYPoint point1(2, 2);
    XYPoint point2(4, 4);
    XYPoint point3(6, 6);
    const float d = distance(point1, point2, point3);
    const float expected = distance(point1, point2) + distance(point2, point3);
    EXPECT_NEAR(d, expected, 1e-6);
}

