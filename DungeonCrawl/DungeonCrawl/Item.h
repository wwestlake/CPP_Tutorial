#ifndef __Item_H
#define __Item_H

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

#include <ostream>
#include <string>


class Item
{
protected:
    std::string _name;
    std::string _description;
    int _value;
    bool _takable;


public:
    Item(std::string name, std::string description, int value) 
        : _name(name), _description(description), _value(value), _takable(true) {}

    Item(std::string name, std::string description, int value, bool isTakale)
        : _name(name), _description(description), _value(value), _takable(isTakale) {}


    friend std::ostream& operator << (std::ostream& os, const Item& item)
    {
        os << "\tItem    : " << item._name << std::endl;
        os << "\tDesc    : " << item._description << std::endl;
        os << "\tValue   : " << item._value  << std::endl;
        return os;
    }

    std::string getName() { return _name; }
    int getValue() { return _value; }
    bool isTakable() { return _takable; }
};


#endif //Item_H