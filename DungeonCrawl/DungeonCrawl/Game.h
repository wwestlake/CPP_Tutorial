#ifndef __Game_H
#define __Game_H

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


// X 1. Display a description of the game initialy when the game starts
// 2. Startup a loop
// X 3. Display a prompt for this game (supplied by the user of this class)
// 4. Read some user input
// 5. Pass that user input to a function specific to the game and get a result
// 6. Print the result
// 7. Go back to 3

#include <iostream>
#include <string>

/**
    Base class for games using text input and output with REPL
*/

class Game
{
private:
    bool _running = true;
protected:
    std::string _name;
    std::string _description;
    std::string _prompt;

public:
    Game(std::string name, std::string description, std::string prompt);

    void GameLoop();

    void PrintBanner();
    void PrintPrompt();
    std::string ReadInput();

    virtual void EvalCommand(std::string command) = 0;

    virtual void PrintResult() = 0;

    void GameOver()
    {
        _running = false;
    }


};


#endif //Game_H