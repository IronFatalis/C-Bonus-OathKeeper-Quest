#include "Inventory.h"
#include <iostream>
#include <string>

void Inventory::DrawInventory()		//very basic inventory
{
	cout << endl << "Inventory" << endl;
	cout << "--------------" << endl << endl;
	if (StrangeKey == true)		//checks if player has Strange Key
	{
		cout << "Strange Key" << endl;	//if so output Strange Key
	}
	if (Antidote == true)		//checks if player has antidote
	{
		cout << "Antidote" << endl;		//if so output antidote
	}
	if (OathKeeperSword == true)	//checks if player has sword
	{
		cout << "OathKeeper Sword" << endl;		//if so output sword
	}
	if (PlateArmour == true)		//checks if player has armour
	{
		cout << "Plate Mail Armour" << endl;	//if so output armour
	}
	if (HealthPotion >= 1)			//checks if player has 1 or more health potions
	{
		cout << "Health Potion X " << HealthPotion << endl;	//if so output amount of health potions
	}
}