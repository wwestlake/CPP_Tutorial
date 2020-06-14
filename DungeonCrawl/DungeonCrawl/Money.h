#ifndef __Money_H
#define __Money_H

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
#include "Random.h"

enum class Coinage {
    COPPER = 1,
    BRASS = 5,
    SILVER = 50,
    HALF_CROWN = 500,
    GOLD_CROWN = 2500
};

typedef struct Coins {
    int Copper = 0;
    int Brass = 0;
    int Silver = 0;
    int HalfCrown = 0;
    int GoldCrown = 0;

    friend std::ostream& operator <<(std::ostream& os, const Coins& coins)
    {
        os << "Copper: " << coins.Copper << std::endl;
        os << "Brass : " << coins.Brass << std::endl;
        os << "Silver: " << coins.Silver << std::endl;
        os << "Half C: " << coins.HalfCrown << std::endl;
        os << "Gold C: " << coins.GoldCrown << std::endl;
        return os;
    }


} Coins;



class Purse
{
protected:
    int _value;

    int CountCoins(int currentValue, Coinage coin, int& remainder) const
    {
        int coinValue = static_cast<int>(coin);
        int result = currentValue / coinValue;
        remainder = currentValue % coinValue;
        return result;
    }

public:
    Purse() : _value(0) {}

    void Add(Coinage coin, unsigned int number)
    {
        int multiplier = static_cast<int>(coin);
        _value += multiplier * number;
    }

    void Remove(Coinage coin, unsigned int number)
    {
        int multiplier = static_cast<int>(coin);
        _value -= multiplier * number;
    }


    Coins CountPurse() const
    {
        Coins result;
        int value = _value;
        result.GoldCrown = CountCoins(value, Coinage::GOLD_CROWN, value);
        result.HalfCrown = CountCoins(value, Coinage::HALF_CROWN, value);
        result.Silver = CountCoins(value, Coinage::SILVER, value);
        result.Brass = CountCoins(value, Coinage::BRASS, value);
        result.Copper = value;

        return result;
    }

    friend std::ostream& operator <<(std::ostream& os, const Purse& purse)
    {
        Coins values = purse.CountPurse();

        os << "Purse" << std::endl;
        os << "------------------------------------" << std::endl;
        os << "Value : " << purse.getValue() << std::endl;
        os << values;
        os << "------------------------------------" << std::endl;
        return os;
    }

    int getValue() const { return _value; } 
};


class RandomCoins : public Random {
public:
    RandomCoins() : Random() {}

    Coins GetRandomCoins(int minCopperValue, int maxCopperValue)
    {
        int value = Next(minCopperValue, maxCopperValue);
        Purse tempPurse;
        tempPurse.Add(Coinage::COPPER, value);
        return tempPurse.CountPurse();
    }

};



#endif //Money_H