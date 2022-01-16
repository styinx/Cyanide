#ifndef CYANIDE_LUA_HPP
#define CYANIDE_LUA_HPP

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <string>
#include <variant>

namespace cyanide::cyscript
{

    using LuaFunction = int (*)(lua_State* L);
    using LuaValue = std::variant<bool, lua_Integer, lua_Number, std::string, LuaFunction, void*>;

    class Lua
    {
    private:
        lua_State* m_L;

    public:
        Lua();
        virtual ~Lua();

        int      fromLuaValue(const LuaValue& value);
        LuaValue toLuaValue();
        void     printStack();
    };

}  // namespace cyanide::cyscript

#endif  // CYANIDE_LUA_HPP
