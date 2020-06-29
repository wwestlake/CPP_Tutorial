// DungeonCrawl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


#include "DungeonCrawlGame.h"
#include "Random.h"
#include "Player.h"
#include "Room.h"
#include "Money.h"

int main()
{
    Player player("Bill");

    DungeonCrawlGame game(&player);
    game.CreateRoom("Start", "start room");
    game.CreateRoom("Store", "Buy stuff");

    player.setRoom(game.find("Start"));


    game.GameLoop();



}

