#include <gtest/gtest.h>

#include "cymath/Point.hpp"

using namespace cyanide::cymath;

TEST(PointTest, Ctor)
{
    Point p;

    ASSERT_EQ(0, p.x);
    ASSERT_EQ(0, p.y);
    ASSERT_EQ(0, p.z);
}

TEST(PointTest, Ctor2)
{
    Point q(-1, -2);

    ASSERT_EQ(-1, q.x);
    ASSERT_EQ(-2, q.y);
    ASSERT_EQ(0, q.z);
}

TEST(PointTest, CpyCtor)
{
    Point p(5, -5, 3);
    Point q(p);

    ASSERT_TRUE(p.x == q.x);
    ASSERT_TRUE(p.y == q.y);
    ASSERT_TRUE(p.z == q.z);
}

TEST(PointTest, CpyAssign)
{
    Point p(5, -5, 3);
    Point r = p;

    ASSERT_TRUE(p.x == r.x);
    ASSERT_TRUE(p.y == r.y);
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

    p.add(1, 2, 3).sub(2, 3, 4);

    ASSERT_EQ(-1, p.x);
    ASSERT_EQ(-1, p.y);
    ASSERT_EQ(-1, p.z);
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
    ASSERT_EQ(12, q.y);
    ASSERT_EQ(5, q.z);
}

TEST(PointTest, opadd)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    Point r = p + q;

    ASSERT_EQ(3, r.x);
    ASSERT_EQ(5, r.y);
    ASSERT_EQ(7, r.z);
}

TEST(PointTest, opiadd)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    p += q;

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);
}

TEST(PointTest, opsub)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    Point r = p - q;

    ASSERT_EQ(-1, r.x);
    ASSERT_EQ(-1, r.y);
    ASSERT_EQ(-1, r.z);
}

TEST(PointTest, opisub)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    p -= q;

    ASSERT_EQ(-1, p.x);
    ASSERT_EQ(-1, p.y);
    ASSERT_EQ(-1, p.z);
}

TEST(PointTest, opmul)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    Point r = p * q;

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(6, r.y);
    ASSERT_EQ(12, r.z);
}

TEST(PointTest, opimul)
{
    Point p(1, 2, 3);
    Point q(2, 3, 4);

    p *= q;

    ASSERT_EQ(2, p.x);
    ASSERT_EQ(6, p.y);
    ASSERT_EQ(12, p.z);
}

TEST(PointTest, opdiv)
{
    Point p(1, 2, 3);
    Point q(2, 5, 2);

    Point r = p / q;

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(0, r.y);
    ASSERT_EQ(2, r.z);
}

TEST(PointTest, opidiv)
{
    Point p(1, 2, 3);
    Point q(2, 5, 2);

    p /= q;

    ASSERT_EQ(1, p.x);
    ASSERT_EQ(0, p.y);
    ASSERT_EQ(2, p.z);
}

TEST(PointTest, opmulscalar)
{
    Point p(1, 2, 3);

    Point q = p * 3;
    Point r = p * 1.5f;

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(6, q.y);
    ASSERT_EQ(9, q.z);

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(3, r.y);
    ASSERT_EQ(5, r.z);
}

TEST(PointTest, opimulscalar)
{
    Point p(1, 2, 3);
    Point q(1, 2, 3);

    p *= 3;
    q *= 2.5f;

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(6, p.y);
    ASSERT_EQ(9, p.z);

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(5, q.y);
    ASSERT_EQ(8, q.z);
}

TEST(PointTest, opdivscalar)
{
    Point p(1, 2, 3);

    Point q = p / 3;
    Point r = p / 1.5f;

    ASSERT_EQ(0, q.x);
    ASSERT_EQ(1, q.y);
    ASSERT_EQ(1, q.z);

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(1, r.y);
    ASSERT_EQ(2, r.z);
}

TEST(PointTest, opidivscalar)
{
    Point p(1, 2, 3);
    Point q(1, 2, 3);

    p /= 2;
    q /= 2.5f;

    ASSERT_EQ(1, p.x);
    ASSERT_EQ(1, p.y);
    ASSERT_EQ(2, p.z);

    ASSERT_EQ(0, q.x);
    ASSERT_EQ(1, q.y);
    ASSERT_EQ(1, q.z);
}

TEST(PointTest, eq)
{
    Point p(1, 2, 3);
    Point q = p;

    ASSERT_TRUE(p == q);
}

TEST(PointTest, neq)
{
    Point p(1, 2, 3);
    Point q = p * 2;

    ASSERT_TRUE(p != q);
}

TEST(PointTest, lt)
{
    Point p(1, 2, 3);
    Point q = p * 2;

    ASSERT_TRUE(p < q);
}

TEST(PointTest, lteq)
{
    Point p(1, 2, 3);
    Point q = p * 2;
    Point r = p;

    ASSERT_TRUE(p <= q && p <= r);
}

TEST(PointTest, gt)
{
    Point p(1, 2, 3);
    Point q = p * 2;

    ASSERT_TRUE(q > p);
}

TEST(PointTest, gteq)
{
    Point p(1, 2, 3);
    Point q = p * 2;
    Point r = p;

    ASSERT_TRUE(q >= p && r >= p);
}
