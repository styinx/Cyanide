#ifndef CYANIDE_PYCLASSTYPE_HPP
#define CYANIDE_PYCLASSTYPE_HPP

#include "PyCustom.hpp"

#include <cstdint>
#include <Python.h>
#include <structmember.h>
#include <vector>

namespace ACLIB
{

    class PyClassType
    {
    protected:
        const char*              m_class_name;
        PyTypeObject             m_type;
        std::vector<PyMemberDef> m_members;
        std::vector<PyMethodDef> m_methods;
        std::vector<PyGetSetDef> m_getset;

        explicit PyClassType(const char* name)
            : m_class_name(name)
            , m_type()
        {
        }

    public:
        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            auto self = reinterpret_cast<PyClassType*>(type->tp_alloc(type, 0));
            if(self == nullptr)
            {
                INFO("Could not allocate PyClassType.\n");
                return nullptr;
            }
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* type)
        {
            Py_TYPE(type)->tp_free(reinterpret_cast<PyObject*>(type));
        }

        virtual bool init(PyObject* module)
        {
            // MSVC c99 :/
            PyMethodDef method_sentinel = {nullptr};
            PyMemberDef member_sentinel = {nullptr};
            PyGetSetDef getset_sentinel = {nullptr};
            m_methods.emplace_back(method_sentinel);
            m_members.emplace_back(member_sentinel);
            m_getset.emplace_back(getset_sentinel);

            PyVarObject ob_base = ACLIBPyObject_HEAD_INIT(&PyType_Type);
            m_type.ob_base      = ob_base;
            m_type.tp_name      = m_class_name;
            m_type.tp_methods   = m_methods.data();
            m_type.tp_members   = m_members.data();
            m_type.tp_getset    = m_getset.data();

            // Set defaults if nothing was set yet
            if(!m_type.tp_flags)
                m_type.tp_flags = Py_TPFLAGS_DEFAULT;
            if(!m_type.tp_new)
                m_type.tp_new = (newfunc)PyClassType::_new;
            if(!m_type.tp_dealloc)
                m_type.tp_dealloc = (destructor)PyClassType::_del;

            if(!m_type.tp_basicsize)
                INFO("Set basic size of your class type.");

            if(module == nullptr)
            {
                INFO("Call init() before adding class types.");
                return false;
            }

            bool success = true;

            // Init class
            success &= PyType_Ready(&m_type) >= 0;

            // Add class object
            success &=
                PyModule_AddObject(module, m_type.tp_name, reinterpret_cast<PyObject*>(&m_type)) >= 0;

            if(!success)
                INFO("Could not initialize class.");

            return success;
        }

        void addMethod(
            const char*  name,
            PyCFunction  method,
            std::int16_t args      = METH_VARARGS,
            const char*  docstring = nullptr)
        {
            PyMethodDef method_def = {name, method, args, docstring};
            m_methods.emplace_back(method_def);
        }

        void addMember(
            const char* name,
            std::int8_t type,
            Py_ssize_t  offset,
            std::int8_t flags     = 0,
            const char* docstring = nullptr)
        {
            ACLIBPyMemberDef member_def = {name, type, offset, flags, docstring};
            m_members.emplace_back(*reinterpret_cast<PyMemberDef*>(&member_def));
        }

        void addGetSet(
            const char* name,
            getter      get_method,
            setter      set_method,
            void*       closure   = nullptr,
            const char* docstring = nullptr)
        {
            ACLIBPyGetSetDef getset_def = {name, get_method, set_method, docstring, closure};
            m_getset.emplace_back(*reinterpret_cast<PyGetSetDef*>(&getset_def));
        }
    };  // namespace ACLIB

}  // namespace ACLIB

#endif  // CYANIDE_PYCLASSTYPE_HPP
