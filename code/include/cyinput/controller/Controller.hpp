#ifndef CYANIDE_CONTROLLER_HPP
#define CYANIDE_CONTROLLER_HPP

#include "ControllerInput.hpp"
#include "cyinput/controller/IController.hpp"

namespace cyanide::cyinput
{

    class Controller
        : public IController
        , public ControllerInput
    {
    private:
    public:
        explicit Controller(const Uint8 id);
        virtual ~Controller() = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_CONTROLLER_HPP
