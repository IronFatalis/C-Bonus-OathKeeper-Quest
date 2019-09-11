#pragma once
#include <iostream>
#include <string>

using namespace std;

class Inventory
{
private:

public:
	void DrawInventory();
	bool StrangeKey = true;
	bool Antidote = false;
	bool OathKeeperSword = false;
	bool PlateArmour = false;
	int HealthPotion = 2;
};