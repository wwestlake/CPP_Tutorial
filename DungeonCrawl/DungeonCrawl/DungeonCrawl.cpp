// DungeonCrawl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>


#include "DungeonCrawlGame.h"
#include "Random.h"
#include "Player.h"
#include "Room.h"
#include "Money.h"
#include "Python3.h"
#include "PyInstance.h"
#include "CPyObject.h"

int main_1(void)
{

    PyRun_SimpleString("print('Hello, World! from  Python')");

    return 0;
}

int main_2(void)
{

    CPyObject p;
    p = PyLong_FromLong(50L);

    std::cout << "Value = " << PyLong_AsLong(p) << std::endl;


    return 0;
}


void loadModule()
{
    CPyObject name = PyUnicode_FromString("integer");
    CPyObject module = PyImport_Import(name);

    if (module)
    {
        CPyObject func = PyObject_GetAttrString(module, "getNumber");
        if (func && PyCallable_Check(func)) 
        {
            CPyObject value = PyObject_CallObject(func, nullptr);

            std::cout << "getNumber() = " << PyLong_AsLong(value) << std::endl;
        }
        else {
            std::cerr << "ERROR: function getNumber not found" << std::endl;
        }
    }
    else {
        std::cerr << "ERROR: Module not found" << std::endl;
    }

}

void loadModule_2(PyInstance& inst)
{
    CPyObject nullobject;
    CPyObject module = inst.LoadModule("integer");
    CPyObject value = inst.CallFunction(module, "getNumber", nullobject);

    std::cout << "getNumber() = " << PyLong_AsLong(value) << std::endl;


}

int main(void)
{
    PyInstance instance;

    loadModule_2(instance);

    return 0;
}

int _main(void)
{
    Player player("Bill");

    DungeonCrawlGame game(&player);
    game.CreateRoom("Start", "start room");
    game.CreateRoom("Store", "Buy stuff");

    player.setRoom(game.find("Start"));


    game.GameLoop();


    return 0;
}



