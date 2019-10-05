#ifndef CYANIDE_CONTROLLER_HPP
#define CYANIDE_CONTROLLER_HPP

#include "cyinput/controller/IController.hpp"

namespace cyanide::cyinput
{

    class Controller : public IController
    {
    private:
    public:
        Controller()                                 = default;
        ~Controller()                                = default;
        Controller(const Controller& controller)     = default;
        Controller(Controller&& controller) noexcept = default;
        Controller& operator=(const Controller& controller) = default;
        Controller& operator=(Controller&& controller) noexcept = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_CONTROLLER_HPP
