#ifndef CYANIDE_PROTOTYPES_HPP
#define CYANIDE_PROTOTYPES_HPP

#include <functional>
#include <list>
#include <map>
#include <thread>
#include <vector>

namespace Cyanide
{

// primitive types
using Byte   = std::uint8_t;
using Uint16 = std::uint16_t;
using Sint16 = std::int16_t;
using Uint32 = std::uint32_t;
using Sint32 = std::int32_t;

// complex types
using Thread = std::thread;
using String = std::string;

// collection types
template<typename T>
using Vector = std::vector<T>;
template<typename T>
using List = std::list<T>;
template<typename K, typename V>
using Map = std::map<K, V>;

// pointer types
template<typename T>
using UniquePtr = std::unique_ptr<T>;
template<typename T>
using SharedPtr = std::shared_ptr<T>;
template<typename T>
using WeakPtr = std::weak_ptr<T>;

// function types
template<typename Func>
using Function = std::function<Func>;

}  // namespace Cyanide

#endif  // CYANIDE_PROTOTYPES_HPP
