#include "Game.h"
#include "Player.h"
#include "Inventory.h"
#include "Location.h"
#include <iostream>
#include <string>

using namespace std;
Player Player1 = Player();
Inventory Inventory1= Inventory();
Location Location1 = Location();



void Game::Intro()
{
	cout << "\tOathkeeper Quest" << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room" << endl << endl;

	cout << "King: Welcome to my Throne Room knight." << endl;
	cout << "What was your name again?" << endl << endl;
	cout << "ENTER NAME: ";
	cin >> playerName;
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "King: Oh yes, now I remember. ";
	Player1.Name(playerName);
	cout << " is a splended name I shall not forget it." << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "I have a quest for you to undertake, should you succeed, " << endl;
	cout << "I shall grant you any one thing from my kingdom that is within my power." << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "What is this task you might ask? Well it's to slay the " << endl;
	cout << "dragon plaguing our kingdom of course!" << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "Here is a key to the shrine to the EAST. I suggest you " << endl;
	cout << "visit it before you go on your way with your quest." << endl << endl;
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
	cout << "You head out to the enterance of Castle Town to start your adventure." << endl << endl;
	system("pause");
	system("CLS");
	Location1.location = 17;
}

void Game::Menu()
{

	Player1.Location(Location1.location);
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
			Location1.LookAround();
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
					Location1.WalkNorth();
					system("pause");
					system("CLS");
				}
				else if (direction == "SOUTH")
				{
					Location1.WalkSouth();
					system("pause");
					system("CLS");
					if (Location1.location == 16)
					{
						if (resistance == true)
						{
							cout << "You are able to pass into the poisonous swamp unharmed because of the antidote you drank." << endl;
							Location1.location = Location1.location + 5;
							Location1.able = true;
						}
						else
						{
							cout << "You try to continue into the poisonous swamp and begin feeling sick." << endl;
							cout << "You took 30 damage!" << endl;							
							cout << "You head back to the swamp enterance before you end up passing out." << endl;
							Player1.AddHealth(-30);
							Location1.location = Location1.location + 5;
							direction = "NORTH";
							system("pause");
							system("CLS");
						}
					}					
				}
				else if (direction == "WEST")
				{
					Location1.WalkWest();
					system("pause");
					system("CLS");
				}
				else if (direction == "EAST")
				{
					Location1.WalkEast();
					system("pause");
					system("CLS");
				}
				else
				{
					cout << "Please enter 'NORTH' 'SOUTH' 'EAST' or 'WEST'." << endl;
					cin >> direction;
				}
			} while (Location1.able == false);
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
	Intro();
	//Inventory1.Add(&items[0], inventory, INVENTORY_CAPACITY);		//Give player 'strange key'
	//Inventory1.Add(&items[0], inventory, 8);
	//Inventory1.Add(&items[4], inventory, INVENTORY_CAPACITY);		//Give player 'health potion'
	Choices();

	do
	{
		if (game == true)
		{
			cout << "INVENTORY" << endl << endl;
			Inventory1.inventory();
			//Inventory1.Add(&items[0], inventory, INVENTORY_CAPACITY);
			system("pause");
			system("CLS");
			Choices();
		}
	} while (game == true);
}