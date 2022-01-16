#ifndef CYANIDE_METATABLE_HPP
#define CYANIDE_METATABLE_HPP

#include "Table.hpp"

template<typename Type, const char* Name>
class LuaMetaTable : public LuaTable<Name>
{
private:
    bool m_overwrite = false;

    static int _new(lua_State* L)
    {
        auto user_data = reinterpret_cast<Type**>(lua_newuserdatauv(L, sizeof(Type*), 1));
        *user_data     = new Type();

        // Associate the user data with the metatable.
        luaL_setmetatable(L, Name);

        // Return the userdata
        return 1;
    }

    static int _delete(lua_State* L)
    {
        delete *reinterpret_cast<Type**>(lua_touserdata(L, -1));
        return 0;
    }

    static int _get(lua_State* L)
    {
        auto        user_data = reinterpret_cast<Type**>(lua_touserdata(L, -2));
        const char* field     = lua_tostring(L, -1);

        // Replace the user data with the associated metatable.
        luaL_getmetatable(L, Name);
        lua_replace(L, -3);

        // Get the field of the table.
        lua_rawget(L, -2);

        // Return field's value.
        return 1;
    }

    static int _set(lua_State* L)
    {
        auto        user_data = reinterpret_cast<Type**>(lua_touserdata(L, -3));
        const char* field     = lua_tostring(L, -2);
        LuaValue    value     = toLuaValue(L);

        // Replace the user data with the associated metatable.
        luaL_getmetatable(L, Name);
        lua_replace(L, -4);

        // Set the field to the value.
        lua_rawset(L, -3);

        return 0;
    }

public:
    explicit LuaMetaTable(lua_State* L, bool overwrite = false)
        : LuaTable<Name>(L)
        , m_overwrite(overwrite)
    {
    }

    void init() override
    {
        // If new metatable was created or the existing one should be overwritten (extended).
        if(luaL_newmetatable(LuaTable<Name>::m_L, Name) == 1 || m_overwrite)
        {
            // Constructor and Destructor
            LuaTable<Name>::addMethod("__call", LuaMetaTable<Type, Name>::_new);
            LuaTable<Name>::addMethod("__gc", LuaMetaTable<Type, Name>::_delete);

            // Metatable name
            LuaTable<Name>::addField("__metatable", Name);

            // Getter and Setter
            LuaTable<Name>::addMethod("__index", LuaMetaTable<Type, Name>::_get);
            LuaTable<Name>::addMethod("__newindex", LuaMetaTable<Type, Name>::_set);

            // Initialize members
            LuaTable<Name>::_initFields();
            LuaTable<Name>::_initMethods();
        }
        else
        {
            // metatable already known, the existing table is returned
        }

        // Set metatable as global name
        lua_setglobal(LuaTable<Name>::m_L, Name);
    }
};

#endif  // CYANIDE_METATABLE_HPP
