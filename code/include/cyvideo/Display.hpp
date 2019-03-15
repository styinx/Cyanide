#ifndef CYANIDE_DISPLAY_HPP
#define CYANIDE_DISPLAY_HPP

#include "cyvideo/IDisplay.hpp"

namespace cyanide
{
namespace cyvideo
{

    class Display : public IDisplay
    {
    private:
    public:
        Display() = default;

        ~Display() = default;
    };

}  // namespace cyvideo
}  // namespace cyanide

#endif  // CYANIDE_DISPLAY_HPP
