#ifndef __Room_H
#define __Room_H

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
#include <vector>

class Room
{
protected:
    std::string _name;
    std::string _description;
    std::vector<Room*> _exits;

public:
    Room(std::string name, std::string description) : _name(name), _description(description) {}

    void AddRoom(Room* room)
    {
        _exits.push_back(room);
    }

    std::vector<std::string> ExitNames()
    {
        std::vector<std::string> result;
        for (auto room : _exits)
        {
            result.push_back(room->_name);
        }
        return result;
    }

    Room* GoThroughExit(std::string name)
    {
        for (auto room : _exits)
        {
            if (room->_name == name) return room;
        }
        return this;
    }

    std::string getName() { return _name; }
    std::string getDescription() { return _description; }

};


#endif //Room_H