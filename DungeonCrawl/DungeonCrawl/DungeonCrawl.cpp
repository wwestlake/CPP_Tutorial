// DungeonCrawl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "DungeonCrawlGame.h"

int main()
{
    DungeonCrawlGame game;

    game.CreateRoom("Start Room", "You are in a room with a high vaulted ceiling");
    game.CreateRoom("Store", "This is a store where you can buy armor");

    game.ConnectRooms("Start Room", "Store");

    game.GameLoop();

}

