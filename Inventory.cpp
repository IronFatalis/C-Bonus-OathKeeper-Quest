#include "Inventory.h"
#include <iostream>
#include <string>

void Inventory::DrawInventory()
{
	cout << endl << "Inventory" << endl;
	cout << "--------------" << endl << endl;
	if (StrangeKey == true)
	{
		cout << "Strange Key" << endl;
	}
	if (Antidote == true)
	{
		cout << "Antidote" << endl;
	}
	if (OathKeeperSword == true)
	{
		cout << "OathKeeper Sword" << endl;
	}
	if (PlateArmour == true)
	{
		cout << "Plate Mail Armour" << endl;
	}
	if (HealthPotion >= 1)
	{
		cout << "Health Potion X " << HealthPotion << endl;
	}
}