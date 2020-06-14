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
    //DungeonCrawlGame game;
    //
    //game.CreateRoom("Start", "You are in a room with a high vaulted ceiling");
    //game.CreateRoom("Store", "This is a store where you can buy armor");
    //
    //game.ConnectRooms("Start", "Store");
    //
    //game.GameLoop();

    //Player me("Bill");
    //
    //me.AddMoney(Coinage::COPPER, 1543);
    //
    //me.AddItem(new Item("Ball", "Red Ball", 12));
    //me.AddItem(new Item("Cube", "Blue Cube", 14));
    //me.AddItem(new Item("Cone", "Green Cone", 16));
    //
    //std::cout << me;
    //
    //me.RemoveItem("Ball");
    //me.RemoveItem("Cone");
    //std::cout << me;
    //
    //Room room("SPecial","A Room");
    //room.AddRoom(new Room("Someplace", "Another room"));
    //room.AddItem(new Item("Ball", "Red Ball", 12));
    //room.AddItem(new Item("Cube", "Blue Cube", 14));
    //room.AddItem(new Item("Cone", "Green Cone", 16));
    

    //std::cout << room;

    RandomCoins rcoins;
    Coins c = rcoins.GetRandomCoins(100, 1500);
    std::cout << c;



}

