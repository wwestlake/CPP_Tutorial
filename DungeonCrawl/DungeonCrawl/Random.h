#ifndef __Random_H
#define __Random_H

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

#include <random>
#include <time.h>

class Random
{
private:
    std::mt19937 _rand;
public:
    Random() : _rand(time(0)) {}

    int Next() { return _rand(); }

    // Inclusive of min and max
    int Next(int min, int max)
    {
        return _rand() % (max - min + 1) + min;
    }

    int Dice(int sides, int number) 
    {
        int result = 0;
        for (int i = 0; i < number; i++)
        {
            result += Next(1, sides);
        }
        return result;
    }

    int Dice6(int num) {
        return Dice(6, num);
    }

    int Dice8(int num) {
        return Dice(8, num);
    }

};


#endif //Random_H