#ifndef CYANIDE_PRINT_HPP
#define CYANIDE_PRINT_HPP

#include <iostream>

#include "cymath/Line.hpp"
#include "cymath/Point.hpp"
#include "cymath/Rectangle.hpp"
#include "cymath/Space.hpp"
#include "cymath/Vector.hpp"

namespace cyanide::cyutil
{

    std::ostream& operator<<(std::ostream& out, const cymath::Line& l);
    std::ostream& operator<<(std::ostream& out, const cymath::Point& p);
    std::ostream& operator<<(std::ostream& out, const cymath::Rectangle& r);
    std::ostream& operator<<(std::ostream& out, const cymath::Size& s);
    std::ostream& operator<<(std::ostream& out, const cymath::Space& s);
    std::ostream& operator<<(std::ostream& out, const cymath::Vector& v);

}  // namespace cyanide

#endif  // CYANIDE_PRINT_HPP
