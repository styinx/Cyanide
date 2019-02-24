#ifndef CYANIDE_NONMOVEABLE_HPP
#define CYANIDE_NONMOVEABLE_HPP

namespace Cyanide
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
}  // namespace Cyanide

#endif  // CYANIDE_NONMOVEABLE_HPP
