#ifndef __DungeonCrawlGame_H
#define __DungeonCrawlGame_H

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

#include <vector>
#include "Game.h"
#include "Room.h"

class DungeonCrawlGame : public Game
{
private:
    std::vector<Room*> rooms;

    Room* currentRoom = nullptr;
    

public:
    DungeonCrawlGame();

    virtual ~DungeonCrawlGame()
    {
        for (auto room : rooms)
        {
            delete room;
        }
    }

    virtual void EvalCommand(std::string command);

    virtual void PrintResult();

    void CreateRoom(std::string name, std::string description)
    {
        rooms.push_back(new Room(name, description));
        if (currentRoom == nullptr)
        {
            currentRoom = find(name);
        }
    }

    Room* find(std::string name)
    {
        for (auto room : rooms)
        {
            if (room->getName() == name)
            {
                return room;
            }
        }
        return nullptr;
    }

    void ConnectRooms(std::string room1name, std::string room2name)
    {
        Room* room1;
        Room* room2;

        room1 = find(room1name);
        room2 = find(room2name);

        if (room1 == nullptr)
        {
            std::cout << "Error invalid room: " << room1name << std::endl;
            return;
        }
        if (room2 == nullptr)
        {
            std::cout << "Error invalid room: " << room2name << std::endl;
            return;
        }

        room1->AddRoom(room2);
        room2->AddRoom(room1);


    }


};


#endif //DungeonCrawlGame_H