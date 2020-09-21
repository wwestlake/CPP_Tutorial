#ifndef __CPyObject_H
#define __CPyObject_H

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

#include <utility>

#include "Python3.h"

class CPyObject
{
private:
    PyObject* _object;

public:
    CPyObject() : _object(nullptr) {}

    CPyObject(PyObject* object) : _object(object) {}


    CPyObject(CPyObject const& other)
    {
        this->_object = other._object;
        addRef();
    }
    CPyObject(CPyObject&& other) noexcept
    {
        std::swap(_object, other._object);
    }

    CPyObject& operator =(CPyObject&& other) noexcept
    {
        std::swap(_object, other._object);
        return *this;
    }

    ~CPyObject()
    {
        release();
    }

    PyObject* addRef()
    {
        if (_object)
        {
            Py_XINCREF(_object);
        }
        return _object;
    }

    void release()
    {
        if (_object)
        {
            Py_XDECREF(_object);
        }
        _object = nullptr;
    }


    PyObject* getObject() { return _object; }

    PyObject* setObject(PyObject* obj) 
    { 
        _object = obj;
        return _object;
    }

    PyObject* operator ->()
    {
        return _object;
    }

    bool is()
    {
        return _object ? true : false;
    }

    operator PyObject* ()
    {
        return _object;
    }

    PyObject* operator =(PyObject* obj)
    {
        _object = obj;
        return _object;
    }

    operator bool()
    {
        return _object ? true : false;
    }


};


#endif //CPyObject_H