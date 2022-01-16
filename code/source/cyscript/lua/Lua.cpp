#include "cyscript/lua/Lua.hpp"

namespace cyanide::cyscript
{

    Lua::Lua()
        : m_L(luaL_newstate())
    {
    }

    Lua::~Lua()
    {
        lua_close(m_L);
    }

    int Lua::fromLuaValue(const LuaValue& value)
    {
        switch(value.index())
        {
        case 0:
            lua_pushboolean(m_L, std::get<0>(value));
            break;
        case 1:
            lua_pushinteger(m_L, std::get<1>(value));
            break;
        case 2:
            lua_pushnumber(m_L, std::get<2>(value));
            break;
        case 3:
            lua_pushstring(m_L, std::get<3>(value).c_str());
            break;
        case 4:
            lua_pushcclosure(m_L, std::get<4>(value), 0);
            break;
        case 5:
            void* pointer = std::get<5>(value);
            if(pointer == nullptr)
                lua_pushnil(m_L);
            else
                lua_pushlightuserdata(m_L, pointer);
            break;
        }
        return 1;
    }

    LuaValue Lua::toLuaValue()
    {
        LuaValue value;

        if(lua_isboolean(m_L, -1) == 1)
        {
            value = lua_toboolean(m_L, -1) > 0;
        }
        else if(lua_isinteger(m_L, -1) == 1)
        {
            value = lua_tointeger(m_L, -1);
        }
        else if(lua_isnumber(m_L, -1) == 1)
        {
            value = lua_tonumber(m_L, -1);
        }
        else if(lua_isstring(m_L, -1) == 1)
        {
            value = lua_tostring(m_L, -1);
        }
        else if(lua_isfunction(m_L, -1) == 1)
        {
            value = lua_tocfunction(m_L, -1);
        }
        else if(lua_islightuserdata(m_L, -1) == 1)
        {
            value = lua_topointer(m_L, -1);
        }
        else
        {
            value = static_cast<void*>(nullptr);
        }

        return value;
    }

    void Lua::printStack()
    {
        printf("Stack:\n");
        int top = lua_gettop(m_L);
        int neg = -top;
        for(int i = 1; i <= top; i++)
        {
            printf("%d\t%d\t%s\t", i, neg++, luaL_typename(m_L, i));
            switch(lua_type(m_L, i))
            {
            case LUA_TNUMBER:
                printf("%g\n", lua_tonumber(m_L, i));
                break;
            case LUA_TSTRING:
                printf("%s\n", lua_tostring(m_L, i));
                break;
            case LUA_TBOOLEAN:
                printf("%s\n", (lua_toboolean(m_L, i) ? "true" : "false"));
                break;
            case LUA_TNIL:
                printf("%s\n", "nil");
                break;
            default:
                printf("%p\n", lua_topointer(m_L, i));
                break;
            }
        }
        printf("==========\n");
        fflush(stdout);
    }

}  // namespace cyanide::cyscript