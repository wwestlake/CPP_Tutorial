#ifndef __GoCommand_H
#define __GoCommand_H

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
#include "Command.h"


class GoCommand : public Command
{

public:

    virtual bool Execute(DungeonCrawlGame & game, Player & player, std::vector<std::string> params)
    {
        std::string roomName = params[0];

        Room* room = game.find(roomName);
        if (room != nullptr)
        {
            player.setRoom(room);
            return true;
        }
        _error.append("Unknow room: ");
        _error.append(roomName);
        return false;
    }

    virtual void error(std::ostream& os)
    {
        os << _error << std::endl;
    }

    static Command * parse(DungeonCrawlGame & game, Player & player, std::string command, std::vector<std::string> params)
    {
        Command* cmd = nullptr;
        std::string cmdstr;
        if (command == "go")
        {
            cmd = new GoCommand();
        }
        return cmd;
    }


};


#endif //GoCommand_H