#ifndef __Player_H
#define __Player_H

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
#include <vector>
#include "Random.h"
#include "Item.h"
#include "Inventory.h"
#include "Money.h"
#include "Room.h"

class Player
{
protected:
    Random _rand;
    std::string _name;

    int _strength;
    int _health;
    int _damage;

    bool _alive = true;

    int _hitPoints;
    int _damageTaken = 0;

    Inventory _inventory;
    Purse _purse;

    Room* _currentRoom;

public:
    Player(std::string name) : _name(name), _currentRoom(nullptr)
    {
        _strength = _rand.Dice6(3);
        _health = _rand.Dice6(3);
        _damage = _rand.Dice6(3);

        _hitPoints = _rand.Dice6(3) + (_health / 3);
    }

    void printRoom(std::ostream& os) const
    {
        os << *_currentRoom << std::endl;
    }


    friend std::ostream& operator << (std::ostream& os, const Player& player)
    {
        os << "Player: " << player._name << std::endl;
        player.printRoom(os);
        os << player._purse;
        os << "------------------------------------" << std::endl;
        os << "Strength: " << player._strength << std::endl;
        os << "Health  : " << player._health << std::endl;
        os << "Damage  : " << player._damage << std::endl;
        os << "------------------------------------" << std::endl;
        os << player._inventory;
        return os;
    }


    void setRoom(Room* room)
    {
        _currentRoom = room;
    }

    bool isAlive() { return _alive; }

    void TakeDamage(int amount) {
        _damageTaken += amount;
        _alive = (_damageTaken < _hitPoints);
    }

    void Heal(int amount) {
        _damageTaken -= amount;
    }

    void AddItem(Item* item)
    {
        _inventory.Add(item);
    }

    void RemoveItem(std::string name)
    {
        _inventory.Remove(name);
    }

    void AddMoney(Coinage coin, int number)
    {
        _purse.Add(coin, number);
    }

    void RemoveMoney(Coinage coin, int number)
    {
        _purse.Remove(coin, number);
    }



};


#endif //Player_H