#include "cygui/layout/HBox.hpp"
#include "cygui/layout/VBox.hpp"
#include "cygui/widgets/Widget.hpp"

#include <gtest/gtest.h>

using namespace cyanide::cygui;

TEST(BoxTest, empty)
{
    VBox b{};

    ASSERT_TRUE(b.empty());

    WidgetSPtr w1 = std::make_shared<Widget>();

    b.add(w1);

    ASSERT_TRUE(!b.empty());
}

TEST(BoxTest, size)
{
    VBox b{};

    ASSERT_TRUE(b.size() == 0);

    WidgetSPtr w1 = std::make_shared<Widget>();

    b.add(w1);

    ASSERT_TRUE(b.size() == 1);
}

TEST(BoxTest, add)
{
    VBox b{};

    WidgetSPtr w1 = std::make_shared<Widget>();
    WidgetSPtr w2 = std::make_shared<Widget>();
    WidgetSPtr w3 = std::make_shared<Widget>();

    b.add(w1);
    b.add(w2);
    b.add(w3);

    ASSERT_TRUE(b.size() == 3);
}

TEST(BoxTest, insert)
{
    VBox b{};

    WidgetSPtr w1 = std::make_shared<Widget>();
    WidgetSPtr w2 = std::make_shared<Widget>();
    WidgetSPtr w3 = std::make_shared<Widget>();
    WidgetSPtr w4 = std::make_shared<Widget>();

    b.insert(w1, 0);
    b.insert(w2, 0);
    b.insert(w3, -1);
    b.insert(w4, 2);

    ASSERT_TRUE(b.size() == 4);
}

TEST(BoxTest, remove)
{
    VBox b{};

    WidgetSPtr w1 = std::make_shared<Widget>();
    WidgetSPtr w2 = std::make_shared<Widget>();
    WidgetSPtr w3 = std::make_shared<Widget>();

    b.add(w1);
    b.add(w2);
    b.add(w3);

    ASSERT_TRUE(b.size() == 3);
    b.remove(2);
    ASSERT_TRUE(b.size() == 2);
    b.remove(0);
    ASSERT_TRUE(b.size() == 1);
    b.remove(0);
    ASSERT_TRUE(b.size() == 0);
}

TEST(BoxTest, erase)
{
    VBox b{};

    WidgetSPtr w1 = std::make_shared<Widget>();
    WidgetSPtr w2 = std::make_shared<Widget>();
    WidgetSPtr w3 = std::make_shared<Widget>();

    b.add(w1);
    b.add(w2);
    b.add(w3);

    ASSERT_TRUE(b.size() == 3);
    b.erase(w1);
    ASSERT_TRUE(b.size() == 2);
    b.erase(w2);
    ASSERT_TRUE(b.size() == 1);
    b.erase(w3);
    ASSERT_TRUE(b.size() == 0);
}
