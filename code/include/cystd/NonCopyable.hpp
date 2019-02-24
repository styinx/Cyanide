#ifndef CYANIDE_NONCOPYABLE_HPP
#define CYANIDE_NONCOPYABLE_HPP

namespace Cyanide
{
namespace cystd
{

    class NonCopyable
    {
    public:
        NonCopyable(NonCopyable& non_copyable) = delete;
        NonCopyable operator=(NonCopyable& non_copyable) = delete;
    };

}  // namespace cystd
}  // namespace Cyanide

#endif  // CYANIDE_NONCOPYABLE_HPP
