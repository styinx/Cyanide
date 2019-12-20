#ifndef CYANIDE_NONCOPYABLE_HPP
#define CYANIDE_NONCOPYABLE_HPP

namespace cyanide::cystd
{

    class NonCopyable
    {
    public:
        NonCopyable(const NonCopyable& non_copyable) = delete;
        NonCopyable operator=(const NonCopyable& non_copyable) = delete;
    };

}  // namespace cyanide

#endif  // CYANIDE_NONCOPYABLE_HPP
