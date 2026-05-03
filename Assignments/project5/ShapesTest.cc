#include <gtest/gtest.h>
#include "Shapes.h"

TEST(CircleArea, Test1)
{
    Circle* c = new Circle(XYPoint(0, 0), 1.0);
    EXPECT_NEAR(c->area(), 3.1415927, 1e-4);
    delete c;
}

TEST(CircleArea, Test2)
{
    Circle* c = new Circle(XYPoint(0, 0), 10.0);
    EXPECT_NEAR(c->area(), 314.15927, 1e-4);
    delete c;
}

TEST(CircleArea, Test3)
{
    Circle* c = new Circle(XYPoint(0, 0), 5.0);
    EXPECT_NEAR(c->area(), 78.53982, 1e-4);
    delete c;
}

TEST(CircleArea, TestZero)
{
    Circle* c = new Circle(XYPoint(0, 0), 0.0);
    EXPECT_NEAR(c->area(), 0.0, 1e-4);
    delete c;
}

TEST(TriangleArea, Test1)
{
    Triangle* t = new Triangle(XYPoint(0, 0), XYPoint(4, 0), XYPoint(0, 3));
    EXPECT_EQ(t->area(), 6.0);
    delete t;
}

TEST(TriangleArea, Test2)
{
    Triangle* t = new Triangle(XYPoint(0, 0), XYPoint(6, 0), XYPoint(0, 4));
    EXPECT_EQ(t->area(), 12.0);
    delete t;
}

TEST(TriangleArea, Test3)
{
    Triangle* t = new Triangle(XYPoint(0, 0), XYPoint(1, 0), XYPoint(0, 1));
    EXPECT_EQ(t->area(), 0.5);
    delete t;
}

TEST(TriangleArea, TestZero)
{
    Triangle* t = new Triangle(XYPoint(0, 0), XYPoint(0, 0), XYPoint(0, 0));
    EXPECT_EQ(t->area(), 0.0);
    delete t;
}

TEST(RectangleArea, Test1)
{
    Rectangle* r = new Rectangle(XYPoint(0, 0), XYPoint(4, 0), XYPoint(4, 3), XYPoint(0, 3));
    EXPECT_EQ(r->area(), 12.0);
    delete r;
}

TEST(RectangleArea, Test2)
{
    Rectangle* r = new Rectangle(XYPoint(0, 0), XYPoint(5, 0), XYPoint(5, 5), XYPoint(0, 5));
    EXPECT_EQ(r->area(), 25.0);
    delete r;
}

TEST(RectangleArea, Test3)
{
    Rectangle* r = new Rectangle(XYPoint(0, 0), XYPoint(2, 0), XYPoint(2, 1), XYPoint(0, 1));
    EXPECT_EQ(r->area(), 2.0);
    delete r;
}

TEST(RectangleArea, TestZero)
{
    Rectangle* r = new Rectangle(XYPoint(0, 0), XYPoint(0, 0), XYPoint(0, 0), XYPoint(0, 0));
    EXPECT_EQ(r->area(), 0.0);
    delete r;
}

TEST(ShapeSorter, Test1)
{
    std::vector<Shape*> shapes = {
        new Circle(XYPoint(0, 0), 5.0),          // area = 78.53
        new Triangle(XYPoint(0,0), XYPoint(4,0), XYPoint(0,3)),  // area = 6.0
        new Rectangle(XYPoint(0,0), XYPoint(4,0), XYPoint(4,3), XYPoint(0,3))  // area = 12.0
    };

    ShapeSorter(shapes);

    // after sorting ascending, order should be: Triangle(6), Rectangle(12), Circle(78.53)
    EXPECT_EQ(shapes[0]->area(), 6.0);    // Triangle smallest
    EXPECT_EQ(shapes[1]->area(), 12.0);   // Rectangle middle
    EXPECT_NEAR(shapes[2]->area(), 78.53982, 1e-4);  // Circle largest

    for (Shape* shape : shapes)
    {
        std::cout << shape->area() << "\n";
        delete shape;
    }
}