#include <gtest/gtest.h>
#include "XYPoint.h"

// Test Case 1
TEST(DistanceTest, TwoPoints1)
{
    XYPoint point1(0, 0);
    XYPoint point2(3, 4);
    const float actual = distance(point1, point2);
    const float expected = 5.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 2
TEST(DistanceTest, TwoPoints2)
{
    XYPoint point1(-5, 5);
    XYPoint point2(-5, 5);
    const float actual = distance(point1, point2);
    const float expected = 0.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 3
TEST(DistanceTest, ThreePoints1)
{
    XYPoint point1(0, 0);
    XYPoint point2(0, 6);
    XYPoint point3(8, 6);
    const float actual = distance(point1, point2, point3);
    const float expected = 14.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 4
TEST(DistanceTest, ThreePoints2)
{
    XYPoint point1(-3, 0);
    XYPoint point2(3, 0);
    XYPoint point3(0, 0);
    const float actual = distance(point1, point2, point3);
    const float expected = 9.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 5
TEST(DistanceTest, FourPoints1)
{
    XYPoint point1(0, 0);
    XYPoint point2(5, 0);
    XYPoint point3(5, 12);
    XYPoint point4(0, 0);
    const float actual = distance(point1, point2, point3, point4);
    const float expected = 30.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 6
TEST(DistanceTest, FourPoints2)
{
    XYPoint point1(-10, 0);
    XYPoint point2(-8, 0);
    XYPoint point3(-5, 0);
    XYPoint point4(-1, 0);
    const float actual = distance(point1, point2, point3, point4);
    const float expected = 9.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 7
TEST(DistanceTest, FivePoints1)
{
    XYPoint point1(0, 0);
    XYPoint point2(3, 4);
    XYPoint point3(6, 0);
    XYPoint point4(9, 4);
    XYPoint point5(12, 0);
    const float actual = distance(point1, point2, point3, point4, point5);
    const float expected = 20.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}

// Test Case 7
TEST(DistanceTest, FivePoints2)
{
    XYPoint point1(0, 0);
    XYPoint point2(0, 0);
    XYPoint point3(100, 0);
    XYPoint point4(100, 0);
    XYPoint point5(100, -50);
    const float actual = distance(point1, point2, point3, point4, point5);
    const float expected = 150.0;
    std::cout << "Actual: " << actual << "\n";
    EXPECT_NEAR(actual, expected, 1e-6);
}