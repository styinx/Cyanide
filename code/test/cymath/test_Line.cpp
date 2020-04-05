#include <gtest/gtest.h>

#include "cymath/Line.hpp"

using namespace cyanide::cymath;

TEST(LineTest, Ctor)
{
    Line l;

    ASSERT_EQ(0, l.x1);
    ASSERT_EQ(0, l.y1);
    ASSERT_EQ(0, l.x2);
    ASSERT_EQ(0, l.y2);
}

TEST(LineTest, Ctor2)
{
    Line l(-1, -2, 2, 1);

    ASSERT_EQ(-1, l.x1);
    ASSERT_EQ(-2, l.y1);
    ASSERT_EQ(2, l.x2);
    ASSERT_EQ(1, l.y2);
}

TEST(LineTest, CpyCtor)
{
    Line l(5, -5, 3, 2);
    Line m(l);

    ASSERT_TRUE(l.x1 == m.x1);
    ASSERT_TRUE(l.y1 == m.y1);
    ASSERT_TRUE(l.x2 == m.x2);
    ASSERT_TRUE(l.y2 == m.y2);
}

TEST(LineTest, CpyAssign)
{
    Line l(5, -5, 3, 2);
    Line m = l;

    ASSERT_TRUE(l.x1 == m.x1);
    ASSERT_TRUE(l.y1 == m.y1);
    ASSERT_TRUE(l.x2 == m.x2);
    ASSERT_TRUE(l.y2 == m.y2);
}

TEST(LineTest, bool)
{
    Line l;

    ASSERT_FALSE(l);

    l.set(2, 1, 3, 1);

    ASSERT_TRUE(l);
}

TEST(LineTest, empty)
{
    Line l;

    ASSERT_TRUE(l.empty());

    l.set(2, 1, 3, 1);

    ASSERT_FALSE(l.empty());
}

TEST(LineTest, set)
{
    Line l;

    l.set(-5, 3, 5, 2);

    ASSERT_EQ(-5, l.x1);
    ASSERT_EQ(3, l.y1);
    ASSERT_EQ(5, l.x2);
    ASSERT_EQ(2, l.y2);
}

TEST(LineTest, first)
{
    Line l(-5, 3, 5, 2);
    Point p1 = l.first();

    ASSERT_EQ(-5, p1.x);
    ASSERT_EQ(3, p1.y);
}

TEST(LineTest, second)
{
    Line l(-5, 3, 5, 2);
    Point p1 = l.second();

    ASSERT_EQ(5, p1.x);
    ASSERT_EQ(2, p1.y);
}

TEST(LineTest, add)
{
    Line l(1, 1, 1, 1);

    l.add(1, 2, 3, 4);

    ASSERT_EQ(2, l.x1);
    ASSERT_EQ(3, l.y1);
    ASSERT_EQ(4, l.x2);
    ASSERT_EQ(5, l.y2);
}

TEST(LineTest, sub)
{
    Line l(1, 1, 1, 1);

    l.sub(1, 2, 3, 4);

    ASSERT_EQ(0, l.x1);
    ASSERT_EQ(-1, l.y1);
    ASSERT_EQ(-2, l.x2);
    ASSERT_EQ(-3, l.y2);
}

TEST(LineTest, mul)
{
    Line l(1, 1, 2, 3);
    Line m(1, 1, 2, 3);

    l.mul(1, 2, 3, 4);
    m.mul(0.5F, 1.5F, 2.5F, 0.75F);

    ASSERT_EQ(1, l.x1);
    ASSERT_EQ(2, l.y1);
    ASSERT_EQ(6, l.x2);
    ASSERT_EQ(12, l.y2);

    ASSERT_EQ(1, m.x1);
    ASSERT_EQ(2, m.y1);
    ASSERT_EQ(5, m.x2);
    ASSERT_EQ(2, m.y2);
}

TEST(LineTest, div)
{
    Line l(1, 1, 2, 3);
    Line m(1, 1, 2, 3);

    l.div(1, 2, 3, 8);
    m.div(0.5F, 1.5F, 2.5F, 0.75F);

    ASSERT_EQ(1, l.x1);
    ASSERT_EQ(1, l.y1);
    ASSERT_EQ(1, l.x2);
    ASSERT_EQ(0, l.y2);

    ASSERT_EQ(2, m.x1);
    ASSERT_EQ(1, m.y1);
    ASSERT_EQ(1, m.x2);
    ASSERT_EQ(4, m.y2);
}

TEST(LineTest, opadd)
{
    Line l(1, 1, 2, 3);
    Line m(l);

    Line n = l + m;

    ASSERT_EQ(2, n.x1);
    ASSERT_EQ(2, n.y1);
    ASSERT_EQ(4, n.x2);
    ASSERT_EQ(6, n.y2);
}

TEST(LineTest, opiadd)
{
    Line l(1, 1, 2, 3);
    Line m(l);

    l += m;

    ASSERT_EQ(2, l.x1);
    ASSERT_EQ(2, l.y1);
    ASSERT_EQ(4, l.x2);
    ASSERT_EQ(6, l.y2);
}

TEST(LineTest, opsub)
{
    Line l(1, 1, 2, 3);
    Line m(l);

    Line n = l - m;

    ASSERT_EQ(0, n.x1);
    ASSERT_EQ(0, n.y1);
    ASSERT_EQ(0, n.x2);
    ASSERT_EQ(0, n.y2);
}

TEST(LineTest, opisub)
{
    Line l(1, 1, 2, 3);
    Line m(l);

    l -= m;

    ASSERT_EQ(0, l.x1);
    ASSERT_EQ(0, l.y1);
    ASSERT_EQ(0, l.x2);
    ASSERT_EQ(0, l.y2);
}

TEST(LineTest, opmul)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    Line n = l * m;

    ASSERT_EQ(1, n.x1);
    ASSERT_EQ(4, n.y1);
    ASSERT_EQ(9, n.x2);
    ASSERT_EQ(16, n.y2);
}

TEST(LineTest, opimul)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    l *= m;

    ASSERT_EQ(1, l.x1);
    ASSERT_EQ(4, l.y1);
    ASSERT_EQ(9, l.x2);
    ASSERT_EQ(16, l.y2);
}

TEST(LineTest, opdiv)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    Line n = l / m;

    ASSERT_EQ(1, n.x1);
    ASSERT_EQ(1, n.y1);
    ASSERT_EQ(1, n.x2);
    ASSERT_EQ(1, n.y2);
}

TEST(LineTest, opidiv)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    l /= m;

    ASSERT_EQ(1, l.x1);
    ASSERT_EQ(1, l.y1);
    ASSERT_EQ(1, l.x2);
    ASSERT_EQ(1, l.y2);
}

TEST(LineTest, opmulscalar)
{
    Line l(1, 2, 3, 4);

    Line m = l * 3.0F;
    Line n = l * 1.5F;

    ASSERT_EQ(3, m.x1);
    ASSERT_EQ(6, m.y1);
    ASSERT_EQ(9, m.x2);
    ASSERT_EQ(12, m.y2);

    ASSERT_EQ(2, n.x1);
    ASSERT_EQ(3, n.y1);
    ASSERT_EQ(5, n.x2);
    ASSERT_EQ(6, n.y2);
}

TEST(LineTest, opimulscalar)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    l *= 3U;
    m *= 1.5F;

    ASSERT_EQ(3, l.x1);
    ASSERT_EQ(6, l.y1);
    ASSERT_EQ(9, l.x2);
    ASSERT_EQ(12, l.y2);

    ASSERT_EQ(2, m.x1);
    ASSERT_EQ(3, m.y1);
    ASSERT_EQ(5, m.x2);
    ASSERT_EQ(6, m.y2);
}

TEST(LineTest, opdivscalar)
{
    Line l(1, 2, 3, 4);

    Line m = l / 3.0F;
    Line n = l / 1.5F;

    ASSERT_EQ(0, m.x1);
    ASSERT_EQ(1, m.y1);
    ASSERT_EQ(1, m.x2);
    ASSERT_EQ(1, m.y2);

    ASSERT_EQ(1, n.x1);
    ASSERT_EQ(1, n.y1);
    ASSERT_EQ(2, n.x2);
    ASSERT_EQ(3, n.y2);
}

TEST(LineTest, opidivscalar)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    l /= 3U;
    m /= 1.5F;

    ASSERT_EQ(0, l.x1);
    ASSERT_EQ(1, l.y1);
    ASSERT_EQ(1, l.x2);
    ASSERT_EQ(1, l.y2);

    ASSERT_EQ(1, m.x1);
    ASSERT_EQ(1, m.y1);
    ASSERT_EQ(2, m.x2);
    ASSERT_EQ(3, m.y2);
}

TEST(LineTest, eq)
{
    Line l(1, 2, 3, 4);
    Line m(l);

    ASSERT_TRUE(l == m);
}

TEST(LineTest, neq)
{
    Line l(1, 2, 3, 4);
    Line m(2, 1, 3, 4);

    ASSERT_TRUE(l != m);
}

TEST(LineTest, lt)
{
    Line l(1, 1, 3, 3);
    Line m(2, 2, 4, 5);

    ASSERT_TRUE(l < m);
}

TEST(LineTest, lteq)
{
    Line l(1, 2, 3, 4);
    Line m(l);
    Line n(2, 3, 4, 5);

    ASSERT_TRUE(l <= m && l <= n);
}

TEST(LineTest, gt)
{
    Line l(2, 3, 4, 5);
    Line m(1, 2, 3, 4);

    ASSERT_TRUE(l > m);
}

TEST(LineTest, gteq)
{
    Line l(1, 2, 3, 4);
    Line m(l);
    Line n(2, 3, 4, 5);

    ASSERT_TRUE(m >= l && n >= l);
}
