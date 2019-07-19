#include <gtest/gtest.h>

#include "cymath/Point.hpp"

using namespace cyanide::cymath;

TEST(PointTest, Ctor)
{
    Point p;
    Point q(-1, -2);

    ASSERT_EQ(0, p.x);
    ASSERT_EQ(0, p.y);
    ASSERT_EQ(0, p.z);

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
    Point q(1, 1, 1);
    Point r(2, 2, 2);

    p.add(1, 2, 3).add(2, 3, 4);
    q.add(r);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(3, q.y);
    ASSERT_EQ(3, q.z);
}

TEST(PointTest, sub)
{
    Point p;
    Point q(2, 2, 2);
    Point r(1, 1, 1);

    p.add(1, 2, 3).sub(2, 3, 4);
    q.sub(r);

    ASSERT_EQ(-1, p.x);
    ASSERT_EQ(-1, p.y);
    ASSERT_EQ(-1, p.z);

    ASSERT_EQ(1, q.x);
    ASSERT_EQ(1, q.y);
    ASSERT_EQ(1, q.z);
}

TEST(PointTest, mul)
{
    Point p(1, 2, 3);
    Point q = p;

    p.mul(3, 2, 1);
    q.mul(1.5f, 1.5f, 1.5f);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(4, p.y);
    ASSERT_EQ(3, p.z);

    ASSERT_EQ(2, q.x);
    ASSERT_EQ(3, q.y);
    ASSERT_EQ(5, q.z);
}

TEST(PointTest, div)
{
    Point p(5, 6, 7);
    Point q = p;

    p.div(2, 3, 4);
    q.div(0.1f, 0.5f, 1.5f);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(2, p.y);
    ASSERT_EQ(2, p.z);

    ASSERT_EQ(50, q.x);
    ASSERT_EQ(3, q.y);
    ASSERT_EQ(3, q.z);
}

TEST(PointTest, opadd)
{
    Point p(1, 2, 3);
    Point q = p;

    Point r = p + q;

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(3, r.y);
    ASSERT_EQ(6, r.z);
}

TEST(PointTest, opiadd)
{
    Point p(1, 2, 3);
    Point q = p;

    p += q;

    ASSERT_EQ(2, p.x);
    ASSERT_EQ(3, p.y);
    ASSERT_EQ(6, p.z);
}