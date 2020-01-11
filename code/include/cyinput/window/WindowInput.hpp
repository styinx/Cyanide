#ifndef CYANIDE_WINDOWINPUT_HPP
#define CYANIDE_WINDOWINPUT_HPP

#include "cyinput/IInputDevice.hpp"
#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"

namespace cyanide::cyinput
{

    class WindowInput final
        : public IInputDevice
        , public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    public:
        enum class WINDOW_EVENT : Byte
        {
            NONE  = 0x00,
            ENTER = 0x01
        };

    private:
        UMap<WINDOW_EVENT, Callback> m_callbacks;

    protected:
        WindowInput() = default;

    public:
        virtual ~WindowInput() = default;

        virtual void on(const String& event, const Callback& callback) override;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_WINDOWINPUT_HPP
