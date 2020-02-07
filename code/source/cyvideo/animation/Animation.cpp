#include "cyvideo/animation/Animation.hpp"

namespace cyanide::cyvideo
{

    Animation::Animation()
        : m_type(AnimationType::LINEAR)
        , m_direction(AnimationDirection::FORWARD)
    {
    }

    Animation::Animation(const AnimationType type, const AnimationDirection direction)
        : m_type(type)
        , m_direction(direction)
    {
    }

    AnimationType Animation::getAnimationType() const
    {
        return m_type;
    }

    void Animation::setAnimationType(const AnimationType type)
    {
        m_type = type;
    }

    AnimationDirection Animation::getAnimationDirection() const
    {
        return m_direction;
    }

    void Animation::setAnimationDirection(const AnimationDirection direction)
    {
        m_direction = direction;
    }

}  // namespace cyanide::cyvideo
