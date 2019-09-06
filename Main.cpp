#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"
#include "Inventory.h"

using namespace std;

int main()
{
	Game PlayGame = Game();
	PlayGame.Play();

	return 0;
}

/*
			if (Contains(&items[item number], inventory, INVENTORY_CAPACITY))
			{
				cout << "YES" << endl;
			}

			Add(&items[itemNumber], inventory, INVENTORY_CAPACITY);

			Remove(&items[itemNumber], inventory, INVENTORY_CAPACITY);

			Player.AddHealth(-30);
*/
