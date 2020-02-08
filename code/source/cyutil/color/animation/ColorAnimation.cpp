#include "cyutil/color/animation/ColorAnimation.hpp"

namespace cyanide::cyutil
{

    ColorAnimation::ColorAnimation(
        const RGBAColor&         min,
        const RGBAColor&         max,
        const AnimationType      type,
        const AnimationDirection direction,
        const Uint8              steps)
        : Animation(type, direction)
        , m_steps(steps)
        , m_min(min)
        , m_max(max)
        , m_step((m_max - m_min) / m_steps)
        , m_current(m_min)
    {
        if(m_direction == AnimationDirection::FORWARD)
        {
            m_current = m_min;
        }
        else if(m_direction == AnimationDirection::BACKWARD)
        {
            m_current = m_max;
        }
    }

    void ColorAnimation::updateStep()
    {
        m_step = (m_max - m_min) / m_steps;
    }

    void ColorAnimation::checkBounds()
    {
        if(m_current >= m_max)
        {
            if(m_type == AnimationType::LINEAR)
            {
                m_current = m_min;
            }
            else if(m_type == AnimationType::ALTERNATE)
            {
                m_step *= -1;
            }
        }
        else if(m_current <= m_min)
        {
            if(m_type == AnimationType::LINEAR)
            {
                m_current = m_max;
            }
            else if(m_type == AnimationType::ALTERNATE)
            {
                m_step *= -1;
            }
        }
    }

    void ColorAnimation::next()
    {
        if(m_direction == AnimationDirection::FORWARD)
        {
            add();
        }
        else if(m_direction == AnimationDirection::BACKWARD)
        {
            sub();
        }

        checkBounds();
    }

    void ColorAnimation::previous()
    {
        if(m_direction == AnimationDirection::FORWARD)
        {
            sub();
        }
        else if(m_direction == AnimationDirection::BACKWARD)
        {
            add();
        }

        checkBounds();
    }

    void ColorAnimation::add()
    {
        m_current += m_step;
    }

    void ColorAnimation::sub()
    {
        m_current -= m_step;
    }

    void ColorAnimation::min()
    {
        m_current = m_min;
    }

    void ColorAnimation::max()
    {
        m_current = m_max;
    }

    RGBAColor ColorAnimation::current()
    {
        return m_current;
    }

    void ColorAnimation::setMin(const RGBAColor& min)
    {
        m_min = min;

        updateStep();
    }

    void ColorAnimation::setMax(const RGBAColor& max)
    {
        m_max = max;

        updateStep();
    }

    void ColorAnimation::setStep(const RGBAColor& step)
    {
        m_step = step;
    }

    void ColorAnimation::setSteps(const Uint8 steps)
    {
        if(steps > 0)
        {
            m_steps = steps;

            updateStep();
        }
    }

    void ColorAnimation::setMinMax(const RGBAColor& min, const RGBAColor& max)
    {
        setMin(min);
        setMax(max);
    }

}  // namespace cyanide::cyutil
