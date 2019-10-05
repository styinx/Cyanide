#include <gtest/gtest.h>

#include "cymath/Size.hpp"

using namespace cyanide::cymath;

TEST(SizeTest, Ctor)
{
    Size s;

    ASSERT_EQ(0, s.width);
    ASSERT_EQ(0, s.height);
}

TEST(SizeTest, Ctor2)
{
    Size t(4, 5);

    ASSERT_EQ(4, t.width);
    ASSERT_EQ(5, t.height);
}

TEST(SizeTest, CpyCtor)
{
    Size s(5, 6);
    Size t(s);

    ASSERT_TRUE(s.width == t.width);
    ASSERT_TRUE(s.height == t.height);
}

TEST(SizeTest, CpyAssign)
{
    Size s(5, 6);
    Size t = s;

    ASSERT_TRUE(s.width == t.width);
    ASSERT_TRUE(s.height == t.height);
}

TEST(SizeTest, set)
{
    Size s;

    s.set(5, 3);

    ASSERT_EQ(5, s.width);
    ASSERT_EQ(3, s.height);
}

TEST(SizeTest, add)
{
    Size s;

    s.add(1, 2);

    ASSERT_EQ(1, s.width);
    ASSERT_EQ(2, s.height);
}

TEST(SizeTest, sub)
{
    Size s(2, 5);

    s.sub(1, 2);

    ASSERT_EQ(1, s.width);
    ASSERT_EQ(3, s.height);
}

TEST(SizeTest, mul)
{
    Size s(1, 2);
    Size t = s;

    s.mul(3, 2);
    t.mul(1.5f, 1.5f);

    ASSERT_EQ(3, s.width);
    ASSERT_EQ(4, s.height);

    ASSERT_EQ(2, t.width);
    ASSERT_EQ(3, t.height);
}

TEST(SizeTest, div)
{
    Size s(5, 6);
    Size t = s;

    s.div(2, 3);
    t.div(0.1f, 0.5f);

    ASSERT_EQ(3, s.width);
    ASSERT_EQ(2, s.height);

    ASSERT_EQ(50, t.width);
    ASSERT_EQ(12, t.height);
}

TEST(SizeTest, opadd)
{
    Size s(1, 2);
    Size t(2, 3);

    Size u = s + t;

    ASSERT_EQ(3, u.width);
    ASSERT_EQ(5, u.height);
}

TEST(SizeTest, opiadd)
{
    Size s(1, 2);
    Size t(2, 3);

    s += t;

    ASSERT_EQ(3, s.width);
    ASSERT_EQ(5, s.height);
}

TEST(SizeTest, opsub)
{
    Size s(2, 3);
    Size t(1, 2);

    Size u = s - t;

    ASSERT_EQ(1, u.width);
    ASSERT_EQ(1, u.height);
}

TEST(SizeTest, opisub)
{
    Size s(1, 2);
    Size t(2, 3);

    s -= t;

    ASSERT_EQ(-1, s.width);
    ASSERT_EQ(-1, s.height);
}

TEST(SizeTest, opmul)
{
    Size s(1, 2);
    Size t(2, 3);

    Size u = s * t;

    ASSERT_EQ(2, u.width);
    ASSERT_EQ(6, u.height);
}

TEST(SizeTest, opimul)
{
    Size s(1, 2);
    Size t(2, 3);

    s *= t;

    ASSERT_EQ(2, s.width);
    ASSERT_EQ(6, s.height);
}

TEST(SizeTest, opdiv)
{
    Size s(1, 2);
    Size t(2, 5);

    Size u = s / t;

    ASSERT_EQ(1, u.width);
    ASSERT_EQ(0, u.height);
}

TEST(SizeTest, opidiv)
{
    Size s(1, 2);
    Size t(2, 5);

    s /= t;

    ASSERT_EQ(1, s.width);
    ASSERT_EQ(0, s.height);
}

TEST(SizeTest, opmulscalar)
{
    Size s(1, 2);

    Size t = s * 3;
    Size u = s * 1.5f;

    ASSERT_EQ(3, t.width);
    ASSERT_EQ(6, t.height);

    ASSERT_EQ(2, u.width);
    ASSERT_EQ(3, u.height);
}

TEST(SizeTest, opimulscalar)
{
    Size s(1, 2);
    Size t(1, 2);

    s *= 3;
    t *= 2.5f;

    ASSERT_EQ(3, s.width);
    ASSERT_EQ(6, s.height);

    ASSERT_EQ(3, t.width);
    ASSERT_EQ(5, t.height);
}

TEST(SizeTest, opdivscalar)
{
    Size s(1, 2);

    Size t = s / 3;
    Size u = s / 1.5f;

    ASSERT_EQ(0, t.width);
    ASSERT_EQ(1, t.height);

    ASSERT_EQ(1, u.width);
    ASSERT_EQ(1, u.height);
}

TEST(SizeTest, opidivscalar)
{
    Size s(1, 2);
    Size t(1, 2);

    s /= 2;
    t /= 2.5f;

    ASSERT_EQ(1, s.width);
    ASSERT_EQ(1, s.height);

    ASSERT_EQ(0, t.width);
    ASSERT_EQ(1, t.height);
}

TEST(SizeTest, eq)
{
    Size s(1, 2);
    Size t = s;

    ASSERT_TRUE(s == t);
}

TEST(SizeTest, neq)
{
    Size s(1, 2);
    Size t = s * 2;

    ASSERT_TRUE(s != t);
}

TEST(SizeTest, lt)
{
    Size s(1, 2);
    Size t = s * 2;

    ASSERT_TRUE(s < t);
}

TEST(SizeTest, lteq)
{
    Size s(1, 2);
    Size t = s * 2;
    Size u = s;

    ASSERT_TRUE(s <= t && s <= u);
}

TEST(SizeTest, gt)
{
    Size s(1, 2);
    Size t = s * 2;

    ASSERT_TRUE(t > s);
}

TEST(SizeTest, gteq)
{
    Size s(1, 2);
    Size t = s * 2;
    Size u = s;

    ASSERT_TRUE(t >= s && u >= s);
}
