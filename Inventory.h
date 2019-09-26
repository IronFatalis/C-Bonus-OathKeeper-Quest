#pragma once
#include <iostream>
#include <string>

using namespace std;

class Inventory
{
private:

public:
	void DrawInventory();			//shows player's current inventory
	bool StrangeKey = true;			//is key in inventory
	bool Antidote = false;			//is antidote in inventory
	bool OathKeeperSword = false;	//is sword in inventory
	bool PlateArmour = false;		//is armour in inventory
	int HealthPotion = 2;			//how many potions are in inventory
};