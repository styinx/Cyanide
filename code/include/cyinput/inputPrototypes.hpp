#ifndef CYANIDE_INPUTPROTOTYPES_HPP
#define CYANIDE_INPUTPROTOTYPES_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyinput
{

    class Keyboard;
    using KeyboardSPtr = SharedPtr<Keyboard>;

    class Mouse;
    using MouseSPtr = SharedPtr<Mouse>;

} // namespace cyanide::cyinput

#endif  // CYANIDE_INPUTPROTOTYPES_HPP
