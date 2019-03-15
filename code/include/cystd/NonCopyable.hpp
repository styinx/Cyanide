#ifndef CYANIDE_NONCOPYABLE_HPP
#define CYANIDE_NONCOPYABLE_HPP

namespace cyanide
{
namespace cystd
{

    class NonCopyable
    {
    public:
        NonCopyable(const NonCopyable& non_copyable) = delete;
        NonCopyable operator=(const NonCopyable& non_copyable) = delete;
    };

}  // namespace cystd
}  // namespace cyanide

#endif  // CYANIDE_NONCOPYABLE_HPP
