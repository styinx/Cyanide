#ifndef CYANIDE_STDDEFINE_HPP
#define CYANIDE_STDDEFINE_HPP

#define CY_SAVE_DEF(macro, value) \
#ifdef macro \
#undef macro \
#endif \
#define macro value

CY_SAVE_DEF(CY_VERSION_MAJOR, 0);
CY_SAVE_DEF(CY_VERSION_MINOR, 0);
CY_SAVE_DEF(CY_VERSION_PATCH, 1);

namespace cyanide
{
namespace cystd
{



}  // namespace cystd
}  // namespace cyanide

#endif  // CYANIDE_STDDEFINE_HPP
