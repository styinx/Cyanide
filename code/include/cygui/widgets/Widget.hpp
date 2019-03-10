#ifndef CYANIDE_WIDGET_HPP
#define CYANIDE_WIDGET_HPP

namespace Cyanide
{
namespace
{

    class Widget
    {
    private:
    public:
        Widget() = default;
        Widget(const Widget& widget) = default;
        Widget(Widget&& widget) noexcept = default;
        Widget& operator=(const Widget& widget) = default;
        Widget& operator=(Widget&& widget) noexcept = default;
        virtual ~Widget() = default;
    };

}  // namespace
}  // namespace Cyanide

#endif  // CYANIDE_WIDGET_HPP
