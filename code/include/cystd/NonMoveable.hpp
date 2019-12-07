#ifndef CYANIDE_NONMOVEABLE_HPP
#define CYANIDE_NONMOVEABLE_HPP

namespace cyanide
{
namespace cystd
{

    class NonMoveable
    {
    public:
        NonMoveable(NonMoveable&& non_moveable) = delete;
        NonMoveable& operator=(NonMoveable&& non_moveable) = delete;
    };

}  // namespace cystd
}  // namespace cyanide

#endif  // CYANIDE_NONMOVEABLE_HPP
