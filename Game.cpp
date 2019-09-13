#include "Game.h"
#include "Player.h"
#include "Inventory.h"
#include "Location.h"
#include <iostream>
#include <string>

using namespace std;
Player Player1 = Player();
Inventory Inventory1 = Inventory();
Location Location1 = Location();

void Game::Intro()
{
	cout << "________          __  .__     ____  __.                                  ________                          __   " << endl;
	cout << "\\_____  \\ _____ _/  |_|  |__ |    |/ _|____   ____ ______   ___________  \\_____  \\  __ __   ____   _______/  |_ " << endl;
	cout << " /   |   \\\\__  \\\\   __\\  |  \\|      <_/ __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\  /  / \\  \\|  |  \\_/ __ \\ /  ___/\\   __\\" << endl;
	cout << "/    |    \\/ __ \\|  | |   Y  \\    |  \\  ___/\\  ___/|  |_> >  ___/|  | \\/ /   \\_/.  \\  |  /\\  ___/ \\___ \\  |  |  " << endl;
	cout << "\\_______  (____  /__| |___|  /____|__ \\___  >\\___  >   __/ \\___  >__|    \\_____\\ \\_/____/  \\___  >____  > |__|  " << endl;
	cout << "        \\/     \\/          \\/        \\/   \\/     \\/|__|        \\/               \\__>           \\/     \\/        " << endl << endl;
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
	cout << " is a splendid name I shall not forget it." << endl << endl;
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
	cout << "Here are some health potions and a key to the shrine to the EAST. I suggest you " << endl;
	cout << "visit it before you go on your way with your quest." << endl << endl;
	system("pause");
	system("CLS");
	cout << "\tThrone Room" << endl << endl;
	cout << "'You recieved a Mysterious Key'" << endl;
	cout << "'You recieved Health Potions X 2'" << endl << endl;
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

void Hints()
{
	if (Inventory1.Antidote == false)
	{
		cout << "There is an item that can ward off poison in the highest peaks."<<endl;
	}
	else if (Inventory1.Antidote == true && Inventory1.PlateArmour == false)
	{
		cout << "You've recieved the cure, now it's time to venture forth though the poison." << endl;
	}
	else if (Inventory1.PlateArmour == true && Inventory1.OathKeeperSword == false)
	{
		cout << "The 'lost woods' may drive you mad, but not if you follow the 'SWaN'" << endl;
	}
	else if (Inventory1.OathKeeperSword == true)
	{
		cout << "The time has come to finish your mission, in the dark cave the dragon remains." << endl;
	}
	system("pause");
	system("CLS");
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
	cout << "2. Move to a new location" << endl;
	cout << "3. Look at equipment" << endl;
	cout << "4. Exit game" << endl;
	if (Location1.location == 9)
	{
		cout << "5. Hint" << endl;
	}
	cout << endl;
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
					system("CLS");
				}
				else if (direction == "SOUTH")
				{
					Location1.WalkSouth();
					system("CLS");	
				}
				else if (direction == "WEST")
				{
					Location1.WalkWest();
					system("CLS");
				}
				else if (direction == "EAST")
				{
					Location1.WalkEast();
					system("CLS");
				}
				else
				{
					cout << "Please enter 'NORTH' 'SOUTH' 'EAST' 'WEST' or anything else to pick a new option." << endl;
					cin >> direction;
				}
				if (Location1.location == 0 && Inventory1.OathKeeperSword == true)
				{
					Player1.HaveSword = true;
				}
				else if (Location1.location == 0)
				{
					Inventory1.OathKeeperSword=true;
				}
				else if (Location1.location == 4 && Inventory1.Antidote == true)
				{
					Player1.HaveAnti = true;
				}
				else if (Location1.location == 4)
				{
					Inventory1.Antidote = true;
				}
				else if (Location1.location == 21 && Inventory1.Antidote == false)
				{
					Location1.location = Location1.location -5;
					Player1.AddHealth(-30);
					cout << "The swamp to the 'SOUTH' begins to burn your skin as you attempt to walk through it." << endl;
					cout << "'You took 30 damage'" << endl;
					cout << "I think I should probably head back and think of a better way to make it through this." << endl;
					system("pause");
					if (Player1.health <= 0)
					{
						system("CLS");
						cout << "You have lost all your health!" << endl;
						cout << "GAME OVER!" << endl << endl;
						correct = true;
						game = false;
					}
				}
				else if (Location1.location == 20 && Inventory1.PlateArmour == true)
				{
					Player1.HaveArmour = true;
				}
				else if (Location1.location == 20)
				{
					Inventory1.PlateArmour = true;
				}
				else if (Location1.location == 24 && Inventory1.OathKeeperSword == true && Inventory1.PlateArmour == true)
				{
					Player1.win = true;
					correct = true;
					game = false;
				}
			} while (Location1.able == false);
			correct = true;
			system("CLS");
		}
		else if (option == "3")
		{
			correct = true;
			Inventory1.DrawInventory();
			cout << endl << endl;
			if (Inventory1.HealthPotion > 0 && Player1.health < 100)
			{
				cout << "Would you like to use a potion?\nYES/NO" << endl;
				cin >> usePotion;
				for (int i = 0, n = usePotion.size(); i < n; i++)
				{
					usePotion[i] = toupper(usePotion[i]);
				}
				if (usePotion == "YES")
				{
					if (Player1.health < 50)
					{
						Inventory1.HealthPotion--;
						Player1.AddHealth(+50);
						cout << "You feel refreshed and gained 50 health back." << endl;
					}
					else
					{
						Inventory1.HealthPotion--;
						Player1.health=100;
						cout << "You feel refreshed and gained 50 health back." << endl;
					}
				}
			}
			system("pause");
			system("CLS");
			Choices();
		}
		else if (option == "4")
		{
			system("CLS");
			cout << "Good bye!" << endl << endl;
			correct = true;
			game = false;
		}
		else if (option == "5" && Location1.location == 9)
		{
			Hints();
		}
		else
		{
			system("CLS");
			Menu();
			correct = false;
			cout << "Please enter a correct option." << endl;
		}
	} while (!correct);
}

void Game::Play()
{
	Intro();
	Choices();
	do
	{
		if (game == true)
		{
			Choices();
		}
		if (Player1.win == true)
		{
			cout << "\tDragon's Nest" << endl << endl;
			cout << "You walk over to the dragon sleeping on the ground. Slowly unsheething your sword as you" << endl;
			cout << "approach it. Now standing next to it's head you raise your sword for a quick kill as you" << endl;
			cout << "see it's eye open. The dragon lets out a massive roar as it knocks you back. You quickly" << endl;
			cout << "get to your feet and thrust your sword swiftly through the bottom of it's head. The dragon" << endl;
			cout << "falls to the floor, lifeless. You have finally completed your quest and Castle Town is safe" << endl;
			cout << "once again" << endl << endl;
			cout << "CONGRAGULATIONS ON COMPLETING THE GAME!" << endl << endl;
		}
	} while (game == true);
}