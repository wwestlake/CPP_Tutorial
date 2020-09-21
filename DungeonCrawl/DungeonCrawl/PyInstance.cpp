/*
Copyright 2020 William W. Westlake

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <iostream>

#include "PyInstance.h"

PyInstance::PyInstance()
{
    Py_Initialize();
}

PyInstance::~PyInstance()
{
    Py_Finalize();
}

CPyObject PyInstance::LoadModule(std::string moduleName)
{
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    CPyObject name = PyUnicode_FromString(moduleName.c_str());
    CPyObject module = PyImport_Import(name);
    PyGILState_Release(gstate);

    return module;
}

CPyObject PyInstance::CallFunction(CPyObject module, std::string function, CPyObject args)
{
    PyGILState_STATE gstate;
    gstate = PyGILState_Ensure();

    if (module)
    {
        CPyObject func = PyObject_GetAttrString(module, function.c_str());
        if (func)
        {
            return PyObject_CallObject(func, args);
        }
        else {
            std::cerr << "ERROR: function '" << function << "()' not found" << std::endl;
        }
    }
    else {
        std::cerr << "ERROR: ERROR: Module not imported" << std::endl;
    }

    PyGILState_Release(gstate);
    CPyObject result;
    return result;
}


