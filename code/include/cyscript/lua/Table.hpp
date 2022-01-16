#ifndef CYANIDE_TABLE_HPP
#define CYANIDE_TABLE_HPP

#include "Lua.hpp"

#include <map>
#include <vector>

template<const char* Name>
class LuaTable
{
protected:
    lua_State*                         m_L       = nullptr;
    std::map<const char*, LuaFunction> m_methods = {};
    std::map<const char*, LuaValue>    m_fields  = {};

    void _initMethods()
    {
        // Add functions
        for(const auto& method : m_methods)
        {
            lua_pushcclosure(m_L, method.second, 0);  // Function pointer
            lua_setfield(m_L, -2, method.first);      // Function name
        }
    }

    void _initFields()
    {
        // Add fields
        for(const auto& field : m_fields)
        {
            fromLuaValue(m_L, field.second);     // Field value
            lua_setfield(m_L, -2, field.first);  // Field name
        }
    }

public:
    explicit LuaTable(lua_State* L)
        : m_L(L)
    {
    }

    virtual void init()
    {
        lua_getglobal(m_L, Name);
        if(lua_isnil(m_L, -1))
        {
            lua_pop(m_L, 1);
            lua_newtable(m_L);
        }

        _initMethods();
        _initFields();

        lua_setglobal(m_L, Name);
    }

    void addMethod(const char* name, LuaFunction function)
    {
        m_methods[name] = function;
    }

    void addField(const char* name, LuaValue value)
    {
        m_fields[name] = std::move(value);
    }
};

#endif  // CYANIDE_TABLE_HPP
