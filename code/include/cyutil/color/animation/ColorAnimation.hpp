#ifndef UTIL_COLORANIMATION_HPP
#define UTIL_COLORANIMATION_HPP

#include "cyutil/color/RGBAColor.hpp"
#include "cyvideo/animation/Animation.hpp"

namespace cyanide::cyutil
{
    using AnimationType      = cyvideo::AnimationType;
    using AnimationDirection = cyvideo::AnimationDirection;

    class ColorAnimation final : public cyvideo::Animation
    {
    private:
        Uint8     m_steps;
        RGBAColor m_min;
        RGBAColor m_max;
        RGBAColor m_step;
        RGBAColor m_current;

        void updateStep();
        void checkBounds();

    public:
        explicit ColorAnimation(
            const RGBAColor&         min,
            const RGBAColor&         max,
            const AnimationType      type,
            const AnimationDirection direction,
            const Uint8              steps = 255);

        virtual ~ColorAnimation() = default;

        virtual void next() override;
        virtual void previous() override;
        virtual void add() override;
        virtual void sub() override;
        virtual void min() override;
        virtual void max() override;

        virtual RGBAColor current();
        virtual void      setMin(const RGBAColor& min);
        virtual void      setMax(const RGBAColor& max);
        virtual void      setMinMax(const RGBAColor& min, const RGBAColor& max);
        virtual void      setStep(const RGBAColor& step);
        virtual void      setSteps(const Uint8 steps);
    };

}  // namespace cyanide::cyutil

#endif  // UTIL_COLORANIMATION_HPP
