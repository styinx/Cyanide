#include "cymath/Vector.hpp"

#include <gtest/gtest.h>

using namespace cyanide::cymath;

TEST(VectorTest, Ctor)
{
    Vector p;

    ASSERT_EQ(0, p.x);
    ASSERT_EQ(0, p.y);
    ASSERT_EQ(0, p.z);
}

TEST(VectorTest, Ctor2)
{
    Vector q(-1, -2);

    ASSERT_EQ(-1, q.x);
    ASSERT_EQ(-2, q.y);
    ASSERT_EQ(0, q.z);
}

TEST(VectorTest, CpyCtor)
{
    Vector p(5, -5, 3);
    Vector q(p);

    ASSERT_TRUE(p.x == q.x);
    ASSERT_TRUE(p.y == q.y);
    ASSERT_TRUE(p.z == q.z);
}

TEST(VectorTest, CpyAssign)
{
    Vector p(5, -5, 3);
    Vector r = p;

    ASSERT_TRUE(p.x == r.x);
    ASSERT_TRUE(p.y == r.y);
    ASSERT_TRUE(p.z == r.z);
}

TEST(VectorTest, bool)
{
    Vector p;

    ASSERT_FALSE(p);

    p.set(2, 1, 2);

    ASSERT_TRUE(p);
}

TEST(VectorTest, empty)
{
    Vector p;

    ASSERT_TRUE(p.empty());

    p.set(2, 1, 2);

    ASSERT_FALSE(p.empty());
}

TEST(VectorTest, set)
{
    Vector p;

    p.set(-5, 3, 5);

    ASSERT_EQ(-5, p.x);
    ASSERT_EQ(3, p.y);
    ASSERT_EQ(5, p.z);
}

TEST(VectorTest, add)
{
    Vector p;

    p.add(1, 2, 3).add(2, 3, 4);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);
}

TEST(VectorTest, sub)
{
    Vector p;

    p.add(1, 2, 3).sub(2, 3, 4);

    ASSERT_EQ(-1, p.x);
    ASSERT_EQ(-1, p.y);
    ASSERT_EQ(-1, p.z);
}

TEST(VectorTest, mul)
{
    Vector p(1, 2, 3);
    Vector q = p;

    p.mul(3, 2, 1);
    q.mul(1.5F, 1.5F, 1.5F);

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(4, p.y);
    ASSERT_EQ(3, p.z);

    ASSERT_EQ(1.5F, q.x);
    ASSERT_EQ(3, q.y);
    ASSERT_EQ(4.5F, q.z);
}

TEST(VectorTest, div)
{
    Vector p(5, 6, 7);
    Vector q = p;

    p.div(2, 3, 4);
    q.div(0.1F, 0.5F, 1.5F);

    ASSERT_EQ(2.5F, p.x);
    ASSERT_EQ(2, p.y);
    ASSERT_EQ(1.75F, p.z);

    ASSERT_EQ(50, q.x);
    ASSERT_EQ(12, q.y);
    ASSERT_NEAR(4.66, q.z, 0.01);
}

TEST(VectorTest, opadd)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    Vector r = p + q;

    ASSERT_EQ(3, r.x);
    ASSERT_EQ(5, r.y);
    ASSERT_EQ(7, r.z);
}

TEST(VectorTest, opiadd)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    p += q;

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(5, p.y);
    ASSERT_EQ(7, p.z);
}

TEST(VectorTest, opsub)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    Vector r = p - q;

    ASSERT_EQ(-1, r.x);
    ASSERT_EQ(-1, r.y);
    ASSERT_EQ(-1, r.z);
}

TEST(VectorTest, opisub)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    p -= q;

    ASSERT_EQ(-1, p.x);
    ASSERT_EQ(-1, p.y);
    ASSERT_EQ(-1, p.z);
}

TEST(VectorTest, opmul)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    Vector r = p * q;

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(6, r.y);
    ASSERT_EQ(12, r.z);
}

TEST(VectorTest, opimul)
{
    Vector p(1, 2, 3);
    Vector q(2, 3, 4);

    p *= q;

    ASSERT_EQ(2, p.x);
    ASSERT_EQ(6, p.y);
    ASSERT_EQ(12, p.z);
}

TEST(VectorTest, opdiv)
{
    Vector p(1, 2, 3);
    Vector q(2, 5, 2);

    Vector r = p / q;

    ASSERT_EQ(0.5F, r.x);
    ASSERT_EQ(0.4F, r.y);
    ASSERT_EQ(1.5F, r.z);
}

TEST(VectorTest, opidiv)
{
    Vector p(1, 2, 3);
    Vector q(2, 5, 2);

    p /= q;

    ASSERT_EQ(0.5F, p.x);
    ASSERT_EQ(0.4F, p.y);
    ASSERT_EQ(1.5F, p.z);
}

TEST(VectorTest, opmulscalar)
{
    Vector p(1, 2, 3);

    Vector q = p * 3.0F;
    Vector r = p * 1.5F;

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(6, q.y);
    ASSERT_EQ(9, q.z);

    ASSERT_EQ(1.5F, r.x);
    ASSERT_EQ(3, r.y);
    ASSERT_EQ(4.5F, r.z);
}

TEST(VectorTest, opimulscalar)
{
    Vector p(1, 2, 3);
    Vector q(1, 2, 3);

    p *= 3;
    q *= 2.5F;

    ASSERT_EQ(3, p.x);
    ASSERT_EQ(6, p.y);
    ASSERT_EQ(9, p.z);

    ASSERT_EQ(2.5F, q.x);
    ASSERT_EQ(5, q.y);
    ASSERT_EQ(7.5F, q.z);
}

TEST(VectorTest, opdivscalar)
{
    Vector p(1, 2, 3);

    Vector q = p / 3.0F;
    Vector r = p / 1.5F;

    ASSERT_NEAR(0.33F, q.x, 0.01);
    ASSERT_NEAR(0.66F, q.y, 0.01);
    ASSERT_NEAR(0.99F, q.z, 0.01);

    ASSERT_NEAR(0.66F, r.x, 0.01);
    ASSERT_NEAR(1.33F, r.y, 0.01);
    ASSERT_EQ(2, r.z);
}

TEST(VectorTest, opidivscalar)
{
    Vector p(1, 2, 3);
    Vector q(1, 2, 3);

    p /= 2;
    q /= 2.5F;

    ASSERT_EQ(0.5F, p.x);
    ASSERT_EQ(1, p.y);
    ASSERT_EQ(1.5F, p.z);

    ASSERT_EQ(0.4F, q.x);
    ASSERT_EQ(0.8F, q.y);
    ASSERT_EQ(1.2F, q.z);
}

TEST(VectorTest, eq)
{
    Vector p(1, 2, 3);
    Vector q = p;

    ASSERT_TRUE(p == q);
}

TEST(VectorTest, neq)
{
    Vector p(1, 2, 3);
    Vector q = p * 2.0F;

    ASSERT_TRUE(p != q);
}

TEST(VectorTest, lt)
{
    Vector p(1, 2, 3);
    Vector q = p * 2.0F;

    ASSERT_TRUE(p < q);
}

TEST(VectorTest, lteq)
{
    Vector p(1, 2, 3);
    Vector q = p * 2.0F;
    Vector r = p;

    ASSERT_TRUE(p <= q && p <= r);
}

TEST(VectorTest, gt)
{
    Vector p(1, 2, 3);
    Vector q = p * 2.0F;

    ASSERT_TRUE(q > p);
}

TEST(VectorTest, gteq)
{
    Vector p(1, 2, 3);
    Vector q = p * 2.0F;
    Vector r = p;

    ASSERT_TRUE(q >= p && r >= p);
}
