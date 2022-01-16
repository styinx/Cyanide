#include "cyscript/python/Python.hpp"

namespace cyanide::cyscript
{

    Python::Python()
    {
        Py_Initialize();
    }

    Python::~Python()
    {
        Py_Finalize();
    }

}  // namespace cyanide::cyscript
