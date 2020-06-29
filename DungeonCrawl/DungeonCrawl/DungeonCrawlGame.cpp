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
#include "DungeonCrawlGame.h"
#include "string_handlers.h"
#include "Command.h";
#include "GoCommand.h"
#include "QuitCommand.h"
#include "SHowCommand.h"

DungeonCrawlGame::DungeonCrawlGame(Player* player) 
    : Game("Dungeon Crawld v0.1", "A dungeon crawl game", "Command >"),
      _player(player)
{
}

void DungeonCrawlGame::EvalCommand(std::string commandStr)
{
    Command* cmd = nullptr;
    Command* temp = nullptr;

    std::vector<std::string> words = split(commandStr);
    std::vector<std::string> params(words);
    params.erase(params.begin());
    std::string command = words[0];

    temp = GoCommand::parse(*this, *_player, command, params);
    if (temp == nullptr) {
        temp = QuitCommand::parse(*this, *_player, command, params);
    }

    if (temp == nullptr) {
        temp = ShowCommand::parse(*this, *_player, command, params);
    }

    cmd = temp;
    if (cmd != nullptr)
    {
        if (cmd->Execute(*this, *_player, params)) {
            _player->printRoom(std::cout);
        }
        else {
            cmd->error(std::cout);
        }
    }
    else {
        std::cout << "Unknown command: " << command << std::endl;
    }

}

void DungeonCrawlGame::PrintResult()
{

}


