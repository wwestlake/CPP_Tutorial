#ifndef __Inventory_H
#define __Inventory_H

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
#include <string>
#include <ostream>
#include <vector>
#include "Item.h"

class Inventory
{
protected:
    std::vector<Item*> _inventory;


public:
    Inventory();
    void Add(Item* item);
    Item* Remove(std::string name);

    friend std::ostream& operator <<(std::ostream& os, const Inventory& inv)
    {
        os << "Inventory" << std::endl;
        os << "-----------------------------------" << std::endl;

        for (auto item : inv._inventory) 
        {
            os << *item << std::endl;
        }
        return os;
    }

};


#endif //Inventory_H