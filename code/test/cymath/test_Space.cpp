#include "cymath/Space.hpp"

#include <gtest/gtest.h>

using namespace cyanide::cymath;

TEST(SpaceTest, Ctor)
{
    Space s;

    ASSERT_EQ(0, s.top);
    ASSERT_EQ(0, s.right);
    ASSERT_EQ(0, s.bottom);
    ASSERT_EQ(0, s.left);
}

TEST(SpaceTest, Ctor2)
{
    Space s(-1, -2, 2, 1);

    ASSERT_EQ(-1, s.top);
    ASSERT_EQ(-2, s.right);
    ASSERT_EQ(2, s.bottom);
    ASSERT_EQ(1, s.left);
}

TEST(SpaceTest, CpyCtor)
{
    Space s(5, -5, 3, 2);
    Space t(s);

    ASSERT_TRUE(s.top == t.top);
    ASSERT_TRUE(s.right == t.right);
    ASSERT_TRUE(s.bottom == t.bottom);
    ASSERT_TRUE(s.left == t.left);
}

TEST(SpaceTest, CpyAssign)
{
    Space s(5, -5, 3, 2);
    Space t = s;

    ASSERT_TRUE(s.top == t.top);
    ASSERT_TRUE(s.right == t.right);
    ASSERT_TRUE(s.bottom == t.bottom);
    ASSERT_TRUE(s.left == t.left);
}

TEST(SpaceTest, bool)
{
    Space s;

    ASSERT_FALSE(s);

    s.set(2, 1, 1, 0);

    ASSERT_TRUE(s);
}

TEST(SpaceTest, empty)
{
    Space s;

    ASSERT_TRUE(s.empty());

    s.set(2, 1, 1, 0);

    ASSERT_FALSE(s.empty());
}

TEST(SpaceTest, set)
{
    Space s;

    s.set(-5, 3, 5, 2);

    ASSERT_EQ(-5, s.top);
    ASSERT_EQ(3, s.right);
    ASSERT_EQ(5, s.bottom);
    ASSERT_EQ(2, s.left);
}

TEST(SpaceTest, add)
{
    Space s;

    s.add(-5, 3, 5, 2);

    ASSERT_EQ(-5, s.top);
    ASSERT_EQ(3, s.right);
    ASSERT_EQ(5, s.bottom);
    ASSERT_EQ(2, s.left);
}

TEST(SpaceTest, sub)
{
    Space s;

    s.sub(5, 3, 5, 2);

    ASSERT_EQ(-5, s.top);
    ASSERT_EQ(-3, s.right);
    ASSERT_EQ(-5, s.bottom);
    ASSERT_EQ(-2, s.left);
}

TEST(SpaceTest, mul)
{
    Space s(-5, 3, 5, 2);
    Space t(s);

    s.mul(2, 3, 4, 5);
    t.mul(0.5F, 1.5F, 2.5F, 1.5F);

    ASSERT_EQ(-10, s.top);
    ASSERT_EQ(9, s.right);
    ASSERT_EQ(20, s.bottom);
    ASSERT_EQ(10, s.left);

    ASSERT_EQ(-3, t.top);
    ASSERT_EQ(5, t.right);
    ASSERT_EQ(13, t.bottom);
    ASSERT_EQ(3, t.left);
}

TEST(SpaceTest, div)
{
    Space s(-5, 3, 5, 2);
    Space t(s);

    s.div(2, 3, 4, 5);
    t.div(0.5F, 1.5F, 2.5F, 1.5F);

    ASSERT_EQ(-10, s.top);
    ASSERT_EQ(9, s.right);
    ASSERT_EQ(20, s.bottom);
    ASSERT_EQ(10, s.left);

    ASSERT_EQ(-2, t.top);
    ASSERT_EQ(4, t.right);
    ASSERT_EQ(12, t.bottom);
    ASSERT_EQ(3, t.left);
}

TEST(SpaceTest, opadd)
{
    Space s(-5, 3, 5, 2);
    Space t(s);

    Space u = s + t;

    ASSERT_EQ(-10, u.top);
    ASSERT_EQ(6, u.right);
    ASSERT_EQ(10, u.bottom);
    ASSERT_EQ(4, u.left);
}
