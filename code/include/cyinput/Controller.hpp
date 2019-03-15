#ifndef CYANIDE_CONTROLLER_HPP
#define CYANIDE_CONTROLLER_HPP

namespace cyanide
{
namespace cyinput
{

    class Controller
    {
    private:
    public:
        Controller() = default;
        ~Controller() = default;
        Controller(const Controller& controller) = default;
        Controller(Controller&& controller) noexcept = default;
        Controller& operator=(const Controller& controller) = default;
        Controller& operator=(Controller&& controller) noexcept = default;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_CONTROLLER_HPP
