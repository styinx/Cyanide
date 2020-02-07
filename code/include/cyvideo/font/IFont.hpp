#ifndef CYANIDE_IFONT_HPP
#define CYANIDE_IFONT_HPP

#include "cystd/Types.hpp"

namespace cyanide::cyvideo
{

    class IFont
    {
    public:
        virtual ~IFont() = default;
    };

    using IFontSPtr = SharedPtr<IFont>;

}

#endif  // CYANIDE_IFONT_HPP
