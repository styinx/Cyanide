#include "cyutil/io/Print.hpp"

namespace cyanide::cyutil
{

    std::ostream& operator<<(std::ostream& out, const cymath::Line& l)
    {
        out << "Line: " << l.x1 << ", " << l.y1 << " | " << l.x2 << ", " << l.y2 << "\n";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const cymath::Point& p)
    {
        out << "Point: " << p.x << ", " << p.y << ", " << p.z << "\n";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const cymath::Rectangle& r)
    {
        out << "Rectangle: " << r.x << ", " << r.y << ", " << r.w << ", " << r.h << "\n";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const cymath::Size& s)
    {
        out << "Size: " << s.width << ", " << s.height << "\n";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const cymath::Space& s)
    {
        out << "Space: " << s.top << ", " << s.right << ", " << s.bottom << ", " << s.left << "\n";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const cymath::Vector& v)
    {
        out << "Vector: " << v.x << ", " << v.y << ", " << v.z << "\n";
        return out;
    }

}  // namespace cyanide
