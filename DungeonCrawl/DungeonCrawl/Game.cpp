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
#include <sstream>
#include "Game.h"


Game::Game(std::string name, std::string description, std::string prompt)  
    : _name(name), _description(description), _prompt(prompt) {}

void Game::GameLoop()
{
    PrintBanner();

    while (_running)
    {
        PrintPrompt();
        EvalCommand(ReadInput());
    }

}

void Game::PrintBanner()
{
    std::cout << _name << std::endl << _description << std::endl << std::endl;
}

void Game::PrintPrompt()
{
    std::cout << _prompt;
    std::cout.flush();
}

std::string Game::ReadInput()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}


