#ifndef CYANIDE_KEYMOD_HPP
#define CYANIDE_KEYMOD_HPP

#include "cyinput/IKey.hpp"

namespace cyanide
{
namespace cyinput
{

    class Keymod final : public IKey
    {
    private:
        Uint32 code = 0;

    public:
        Keymod() = default;
        ~Keymod() = default;
        explicit Keymod(const KEYMOD& keymod);
        explicit Keymod(const IKey& key);
        explicit Keymod(const KEY& key);
        Keymod(const Keymod& keymod) = default;
        Keymod(Keymod&& keymod) noexcept = default;
        Keymod& operator=(const Keymod& keymod) = default;
        Keymod& operator=(Keymod&& keymod) noexcept = default;
        virtual Uint32 getCode() const override;
        virtual IKey& setCode(const Uint32 key) override;
        virtual IKey& setCode(const KEY key) override;
        virtual IKey& setCode(const IKey& key) override;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_KEYMOD_HPP
