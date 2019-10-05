#ifndef CYANIDE_KEYMOD_HPP
#define CYANIDE_KEYMOD_HPP

#include "IKey.hpp"

namespace cyanide::cyinput
{

    class Keymod final : public IKey
    {
    private:
        KeyMod m_key_mod = 0;

    public:
        Keymod()  = default;
        ~Keymod() = default;
        explicit Keymod(const IKey& key);
        Keymod(const Keymod& other)     = default;
        Keymod(Keymod&& other) noexcept = default;
        Keymod& operator=(const Keymod& other) = default;
        Keymod& operator=(Keymod&& other) noexcept = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEYMOD_HPP
