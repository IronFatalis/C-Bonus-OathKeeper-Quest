#include "Game.h"
#include "Player.h"
#include "Inventory.h"
#include "Area.h"
#include <iostream>
#include <string>

using namespace std;
Player Player1 = Player();
Inventory Inventory1= Inventory();
Area Area1 = Area();


void Game::Intro()
{
	cout << "\tOathkeeper Quest" << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room" << endl << endl;

	cout << "<-----INTRO TEXT HERE---->" << endl;
	cout << "King: What was your name again knight?" << endl;
	cin >> playerName;
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "King: Awe yes, now I remember. ";
	Player1.Name(playerName);
	cout << " is a splended name I shall not forget it." << endl;
	cout << "Here is a key to the shrine to the EAST. I suggest you visit it before you go on your way with your quest." << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "'You recieved a mysterious key'" << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "King: Good Luck ";
	Player1.Name(playerName);
	cout << "!" << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "You head out to the Castle Town to start your adventure." << endl;
	system("pause");
	system("CLS");
	location = 12;
}

void Game::Menu()
{

	Player1.Location(location);
	cout << endl << endl;
	Player1.Name(playerName);
	cout << "'s Health : ";
	Player1.Health();
	cout << endl << endl;

	cout << "What would you like to do?" << endl << endl;
	cout << "1. Look around" << endl;
	cout << "2. Move to a new loaction" << endl;
	cout << "3. Look at equipment" << endl;
	cout << "4. Exit game" << endl << endl;

}

void Game::Choices()
{
	Menu();
	do
	{
		cout << "Enter Choice: ";
		cin >> option;
		cout << endl;
		if (option == "1")
		{
			Area1.LookAround();
			correct = true;
			system("pause");
			system("CLS");
			Choices();
		}
		else if (option == "2")
		{
			cout << "Which direction would you like to head?" << endl;
			cin >> direction;
			do
			{
				for (int i = 0, n = direction.size(); i < n; i++)
				{
					direction[i] = toupper(direction[i]);
				}
				if (direction == "NORTH")
				{
					Area1.WalkNorth();
				}
				else if (direction == "SOUTH")
				{
					Area1.WalkSouth();
					if (location == 16)
					{
						if (resistance == true)
						{
							cout << "You are able to pass into the poisonous swamp unharmed because of the antidote you drank." << endl;
							location = location + 5;
							able = true;
						}
						else
						{
							cout << "You try to continue into the poisonous swamp and begin feeling sick." << endl;
							cout << "You took 30 damage!" << endl;							
							cout << "You head back to the swamp enterance before you end up passing out." << endl;
							Player1.AddHealth(-30);
							location = location + 5;
							direction = "NORTH";
							system("pause");
							system("CLS");
						}
					}					
				}
				else if (direction == "WEST")
				{
					Area1.WalkWest();
				}
				else if (direction == "EAST")
				{
					Area1.WalkEast();
				}
				else
				{
					cout << "Please enter 'NORTH' 'SOUTH' 'EAST' or 'WEST'." << endl;
					cin >> direction;
				}
			} while (able == false);
			correct = true;
			system("CLS");
			Choices();
		}
		else if (option == "3")
		{
			correct = true;
		}
		else if (option == "4")
		{
			system("CLS");
			cout << "Good bye!" << endl << endl;
			correct = true;
			game = false;
		}
		else
		{
			system("CLS");
			Menu();
			cout << "Please enter a correct option." << endl;
		}
	} while (!correct);
}

void Game::Play()
{
	//items
	const int NUM_ITEMS = 5;
	const string items[NUM_ITEMS] = { "Strange Key", "Antidote", "OathKeeper Sword", "Legandary Armour", "Health Potion" };

	//inventory
	const int INVENTORY_CAPACITY = 8;		//Can hold all items plus 3 Health Potions
	const string* inventory[INVENTORY_CAPACITY];

	Intro();
	Inventory1.Add(&items[0], inventory, INVENTORY_CAPACITY);		//Give player 'strange key'
	Inventory1.Add(&items[4], inventory, INVENTORY_CAPACITY);		//Give player 'health potion'
	Choices();

	do
	{
		if (game == true)
		{
			cout << "INVENTORY" << endl << endl;
			Inventory1.Display(inventory, INVENTORY_CAPACITY);
			system("pause");
			system("CLS");
			Choices();
		}
	} while (game == true);
}