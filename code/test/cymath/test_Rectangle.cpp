#include <gtest/gtest.h>

#include "cymath/Rectangle.hpp"

using namespace cyanide::cymath;

TEST(RectangleTest, Ctor)
{
    Rectangle r;

    ASSERT_EQ(0, r.x);
    ASSERT_EQ(0, r.y);
    ASSERT_EQ(0, r.w);
    ASSERT_EQ(0, r.h);
}

TEST(RectangleTest, Ctor2)
{
    Rectangle r(-1, -2, 3, 4);

    ASSERT_EQ(-1, r.x);
    ASSERT_EQ(-2, r.y);
    ASSERT_EQ(3, r.w);
    ASSERT_EQ(4, r.h);
}

TEST(RectangleTest, Ctor3)
{
    Rectangle r({2, 2}, {3, 3});

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(2, r.y);
    ASSERT_EQ(3, r.w);
    ASSERT_EQ(3, r.h);
}

TEST(RectangleTest, CpyCtor)
{
    Rectangle r(2, 2, 2, 3);
    Rectangle s(r);

    ASSERT_EQ(r.x, s.x);
    ASSERT_EQ(r.y, s.y);
    ASSERT_EQ(r.w, s.w);
    ASSERT_EQ(r.h, s.h);
}

TEST(RectangleTest, CpyAssign)
{
    Rectangle r(2, 2, 2, 3);
    Rectangle s = r;

    ASSERT_EQ(r.x, s.x);
    ASSERT_EQ(r.y, s.y);
    ASSERT_EQ(r.w, s.w);
    ASSERT_EQ(r.h, s.h);
}

TEST(RectangleTest, bool)
{
    Rectangle r;

    ASSERT_FALSE(r);

    r.set(2, 1, 1, 0);

    ASSERT_TRUE(r);
}

TEST(RectangleTest, empty)
{
    Space s;

    ASSERT_TRUE(s.empty());

    s.set(2, 1, 1, 0);

    ASSERT_FALSE(s.empty());
}

TEST(RectangleTest, topLeft)
{
    Rectangle r(-2, -3, 5, 5);
    Point     tl = r.topLeft();

    ASSERT_EQ(-2, tl.x);
    ASSERT_EQ(-3, tl.y);
}

TEST(RectangleTest, topRight)
{
    Rectangle r(-2, -3, 5, 5);
    Point tr = r.topRight();

    ASSERT_EQ(3, tr.x);
    ASSERT_EQ(-3, tr.y);
}

TEST(RectangleTest, bottomRight)
{
    Rectangle r(-2, -3, 5, 5);
    Point br = r.bottomRight();

    ASSERT_EQ(3, br.x);
    ASSERT_EQ(2, br.y);
}

TEST(RectangleTest, bottomLeft)
{
    Rectangle r(-2, -3, 5, 5);
    Point bl = r.bottomLeft();

    ASSERT_EQ(-2, bl.x);
    ASSERT_EQ(2, bl.y);
}

TEST(RectangleTest, center)
{
    Rectangle r(-2, -3, 5, 5);
    Point c = r.center();

    ASSERT_EQ(1, c.x);
    ASSERT_EQ(-1, c.y);
}

TEST(RectangleTest, getPosition)
{
    Rectangle r(-2, -3, 5, 5);
    Point p = r.getPosition();

    ASSERT_EQ(-2, p.x);
    ASSERT_EQ(-3, p.y);
}

TEST(RectangleTest, getSize)
{
    Rectangle r(-2, -3, 5, 5);
    Size s = r.getSize();

    ASSERT_EQ(5, s.width);
    ASSERT_EQ(5, s.height);
}

TEST(RectangleTest, set)
{
    Rectangle r{};

    r.set(2, 2, 4, 4);

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(2, r.y);
    ASSERT_EQ(4, r.w);
    ASSERT_EQ(4, r.h);
}

TEST(RectangleTest, add)
{
    Rectangle r{};

    r.add(2, 2, 4, 4);

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(2, r.y);
    ASSERT_EQ(4, r.w);
    ASSERT_EQ(4, r.h);
}

TEST(RectangleTest, sub)
{
    Rectangle r{};

    r.sub(2, 2, 4, 4);

    ASSERT_EQ(-2, r.x);
    ASSERT_EQ(-2, r.y);
    ASSERT_EQ(-4, r.w);
    ASSERT_EQ(-4, r.h);
}

TEST(RectangleTest, mul)
{
    Rectangle r(2, 2, 4, 4);
    Rectangle s = r;

    r.mul(2, 3, 1, 4);
    s.mul(2.0F, 1.5F, -1.0F, 2.5F);

    ASSERT_EQ(4, r.x);
    ASSERT_EQ(6, r.y);
    ASSERT_EQ(4, r.w);
    ASSERT_EQ(16, r.h);

    ASSERT_EQ(4, s.x);
    ASSERT_EQ(3, s.y);
    ASSERT_EQ(-4, s.w);
    ASSERT_EQ(10, s.h);
}

TEST(RectangleTest, div)
{
    Rectangle r(2, 4, 8, 16);
    Rectangle s = r;

    r.div(1, 2, 4, 5);
    s.div(-2.0F, 1.5F, 0.5F, 1.5F);

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(2, r.y);
    ASSERT_EQ(2, r.w);
    ASSERT_EQ(3, r.h);

    ASSERT_EQ(-1, s.x);
    ASSERT_EQ(3, s.y);
    ASSERT_EQ(16, s.w);
    ASSERT_EQ(11, s.h);
}

TEST(RectangleTest, opadd)
{
    Rectangle r(0, 0, 2, 2);
    Rectangle s(1, 1, 1, 1);

    Rectangle t = r + s;

    ASSERT_EQ(1, t.x);
    ASSERT_EQ(1, t.y);
    ASSERT_EQ(3, t.w);
    ASSERT_EQ(3, t.h);
}

TEST(RectangleTest, opiadd)
{
    Rectangle r(0, 0, 2, 2);
    Rectangle s(1, 1, 1, 1);

    r += s;

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(1, r.y);
    ASSERT_EQ(3, r.w);
    ASSERT_EQ(3, r.h);
}

TEST(RectangleTest, opsub)
{
    Rectangle r(0, 0, 2, 2);
    Rectangle s(1, 1, 1, 1);

    Rectangle t = r - s;

    ASSERT_EQ(-1, t.x);
    ASSERT_EQ(-1, t.y);
    ASSERT_EQ(1, t.w);
    ASSERT_EQ(1, t.h);
}

TEST(RectangleTest, opisub)
{
    Rectangle r(0, 0, 2, 2);
    Rectangle s(1, 1, 1, 1);

    r -= s;

    ASSERT_EQ(-1, r.x);
    ASSERT_EQ(-1, r.y);
    ASSERT_EQ(1, r.w);
    ASSERT_EQ(1, r.h);
}

TEST(RectangleTest, opmul)
{
    Rectangle r(2, 3, 6, 7);
    Rectangle s(1, 2, 3, 4);

    Rectangle t = r * s;

    ASSERT_EQ(2, t.x);
    ASSERT_EQ(6, t.y);
    ASSERT_EQ(18, t.w);
    ASSERT_EQ(28, t.h);
}

TEST(RectangleTest, opimul)
{
    Rectangle r(2, 3, 6, 7);
    Rectangle s(1, 2, 3, 4);

    r *= s;

    ASSERT_EQ(2, r.x);
    ASSERT_EQ(6, r.y);
    ASSERT_EQ(18, r.w);
    ASSERT_EQ(28, r.h);
}

TEST(RectangleTest, opdiv)
{
    Rectangle r(2, 3, 6, 7);
    Rectangle s(1, 2, 3, 4);

    Rectangle t = r / s;

    ASSERT_EQ(2, t.x);
    ASSERT_EQ(2, t.y);
    ASSERT_EQ(2, t.w);
    ASSERT_EQ(2, t.h);
}

TEST(RectangleTest, opidiv)
{
    Rectangle r(1, 2, 3, 4);
    Rectangle s(2, 3, 6, 7);

    r /= s;

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(1, r.y);
    ASSERT_EQ(1, r.w);
    ASSERT_EQ(1, r.h);
}

TEST(RectangleTest, opmulscalar)
{
    Rectangle r(2, 3, 6, 7);

    Rectangle q = r * 3.0F;
    Rectangle s = r * 1.5F;

    ASSERT_EQ(6, q.x);
    ASSERT_EQ(9, q.y);
    ASSERT_EQ(18, q.w);
    ASSERT_EQ(21, q.h);

    ASSERT_EQ(3, s.x);
    ASSERT_EQ(5, s.y);
    ASSERT_EQ(9, s.w);
    ASSERT_EQ(11, s.h);
}

TEST(RectangleTest, opimulscalar)
{
    Rectangle r(2, 3, 6, 7);
    Rectangle q(2, 3, 6, 7);

    r *= 3;
    q *= 1.5F;

    ASSERT_EQ(6, r.x);
    ASSERT_EQ(9, r.y);
    ASSERT_EQ(18, r.w);
    ASSERT_EQ(21, r.h);

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(5, q.y);
    ASSERT_EQ(9, q.w);
    ASSERT_EQ(11, q.h);
}

TEST(RectangleTest, opdivscalar)
{
    Rectangle r(2, 3, 6, 7);

    Rectangle q = r / 3.0F;
    Rectangle s = r / 1.5F;

    ASSERT_EQ(1, q.x);
    ASSERT_EQ(1, q.y);
    ASSERT_EQ(2, q.w);
    ASSERT_EQ(2, q.h);

    ASSERT_EQ(1, s.x);
    ASSERT_EQ(2, s.y);
    ASSERT_EQ(4, s.w);
    ASSERT_EQ(5, s.h);
}

TEST(RectangleTest, opidivscalar)
{
    Rectangle r(2, 3, 6, 7);
    Rectangle q(2, 3, 6, 7);

    r /= 3;
    q /= 1.5F;

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(1, r.y);
    ASSERT_EQ(2, r.w);
    ASSERT_EQ(2, r.h);

    ASSERT_EQ(1, q.x);
    ASSERT_EQ(2, q.y);
    ASSERT_EQ(4, q.w);
    ASSERT_EQ(5, q.h);
}

TEST(RectangleTest, opaddspace)
{
    Rectangle r(2, 2, 3, 3);
    Space s(1, 1, 1, 1);

    Rectangle q = r + s;

    ASSERT_EQ(1, q.x);
    ASSERT_EQ(1, q.y);
    ASSERT_EQ(5, q.w);
    ASSERT_EQ(5, q.h);
}

TEST(RectangleTest, opiaddspace)
{
    Rectangle r(2, 2, 3, 3);
    Space s(1, 1, 1, 1);

    r += s;

    ASSERT_EQ(1, r.x);
    ASSERT_EQ(1, r.y);
    ASSERT_EQ(5, r.w);
    ASSERT_EQ(5, r.h);
}

TEST(RectangleTest, opsubspace)
{
    Rectangle r(2, 2, 3, 3);
    Space s(1, 1, 1, 1);

    Rectangle q = r - s;

    ASSERT_EQ(3, q.x);
    ASSERT_EQ(3, q.y);
    ASSERT_EQ(1, q.w);
    ASSERT_EQ(1, q.h);
}

TEST(RectangleTest, opisubspace)
{
    Rectangle r(2, 2, 3, 3);
    Space s(1, 1, 1, 1);

    r -= s;

    ASSERT_EQ(3, r.x);
    ASSERT_EQ(3, r.y);
    ASSERT_EQ(1, r.w);
    ASSERT_EQ(1, r.h);
}

TEST(RectangleTest, max)
{
    Rectangle r(2, 2, 3, 3);
    Rectangle s(2, 2, 2, 2);

    ASSERT_TRUE(r == Rectangle::max(r, s));
}

TEST(RectangleTest, min)
{
    Rectangle r(2, 2, 3, 3);
    Rectangle s(2, 2, 2, 2);

    ASSERT_TRUE(s == Rectangle::min(r, s));
}

TEST(RectangleTest, eq)
{
    Rectangle r(2, 2, 3, 3);
    Rectangle s(2, 2, 3, 3);

    ASSERT_TRUE(r == s);
}

TEST(RectangleTest, neq)
{
    Rectangle r(2, 2, 3, 3);
    Rectangle s(1, 2, 1, 3);

    ASSERT_TRUE(r != s);
}

TEST(RectangleTest, lt)
{
    Rectangle r(2, 2, 2, 2);
    Rectangle s(2, 2, 3, 3);

    ASSERT_TRUE(r < s);
}

TEST(RectangleTest, lteq)
{
    Rectangle r(2, 2, 3, 3);
    Rectangle s = r;
    Rectangle t = r * 2.0F;

    ASSERT_TRUE(r <= s && r <= t);
}

TEST(RectangleTest, gt)
{
    Rectangle r(2, 2, 4, 4);
    Rectangle s(2, 2, 3, 3);

    ASSERT_TRUE(r > s);
}

TEST(RectangleTest, gteq)
{
    Rectangle r(2, 2, 4, 4);
    Rectangle s = r;
    Rectangle t = r * 2.0F;

    ASSERT_TRUE(s >= r && t >= r);
}
