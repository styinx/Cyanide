#include <gtest/gtest.h>

#include "cymath/Point.hpp"

using namespace Cyanide::cymath;

TEST(PointTest, Ctor)
{
    Point p;
    ASSERT_EQ(0, p.x);
    ASSERT_EQ(0, p.y);
    ASSERT_EQ(0, p.z);

    Point q(-1, -2);
    ASSERT_EQ(-1, q.x);
    ASSERT_EQ(-2, q.y);
    ASSERT_EQ(0, q.z);
}

TEST(PointTest, CpyCtor)
{
    Point p(5, -5, 3);
    Point q(p);
    Point r = p;

    ASSERT_TRUE(p.x == q.x);
    ASSERT_TRUE(p.x == r.x);

    ASSERT_TRUE(p.y == q.y);
    ASSERT_TRUE(p.y == r.y);

    ASSERT_TRUE(p.z == q.z);
    ASSERT_TRUE(p.z == r.z);
}

TEST(PointTest, set)
{
    Point p;
    p.set(-5, 3, 5);

    ASSERT_EQ(-5, p.x);
    ASSERT_EQ(3, p.y);
    ASSERT_EQ(5, p.z);
}

TEST(PointTest, add)
{
    Point p;
    p.add(1, 2, 3).add(2, 3, 4);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);
}

TEST(PointTest, sub)
{
    Point p;
    p.add(1, 2, 3).add(2, 3, 4);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);
}