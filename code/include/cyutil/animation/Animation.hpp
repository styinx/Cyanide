#ifndef UTIL_ANIMATION_HPP
#define UTIL_ANIMATION_HPP

#include "cystd/Types.hpp"

namespace cyanide::cyvideo
{
    enum class AnimationType : Byte
    {
        LINEAR    = 0x00,
        ALTERNATE = 0x01
    };

    enum class AnimationDirection : Byte
    {
        FORWARD  = 0x00,
        BACKWARD = 0x01
    };

    class Animation
    {
    protected:
        AnimationType      m_type;
        AnimationDirection m_direction;

        Animation();
        explicit Animation(const AnimationType type, const AnimationDirection direction);

    public:
        virtual ~Animation() = default;

        virtual void next()     = 0;
        virtual void previous() = 0;
        /**
         * @brief Calculates the upcoming step.
         */
        virtual void update() = 0;
        /**
         * @brief Sets the current value to the minimum.
         */
        virtual void min() = 0;
        /**
         * @brief Sets the current value to the maximum.
         */
        virtual void max() = 0;

        virtual AnimationType      getAnimationType() const final;
        virtual void               setAnimationType(const AnimationType type) final;
        virtual AnimationDirection getAnimationDirection() const final;
        virtual void               setAnimationDirection(const AnimationDirection direction) final;
    };

}  // namespace cyanide::cyvideo

#endif  // UTIL_ANIMATION_HPP
