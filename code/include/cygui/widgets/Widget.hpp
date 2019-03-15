#ifndef CYANIDE_WIDGET_HPP
#define CYANIDE_WIDGET_HPP

namespace cyanide
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
}  // namespace cyanide

#endif  // CYANIDE_WIDGET_HPP
