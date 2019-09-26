#include "Game.h"
#include "Player.h"
#include "Inventory.h"
#include "Location.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
Player Player1 = Player();
Inventory Inventory1 = Inventory();
Location Location1 = Location();

void Game::SlowText(string text)
{
	x = 0;										//resetting x for multiple uses
	while (text[x] != '\0')						//while the text isn't at the end of the word
	{
		if (text[x] != ' ' && text[x] != '\n')	//skip noise if it's a space or endl
			Beep(850, 50);						//make talking noise for each letter
		cout << text[x];						//outputs the next character in the string
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)	//if player holds enter key
		{
			Sleep(0);								//text will speed up
		}
		else
		{
			Sleep(50);								//pause for 50 milsec
		}
		x++;									//increases x
	};
}

void Game::Intro()	//title ascii art
{
	cout << "________          __  .__     ____  __.                                  ________                          __   " << endl;
	cout << "\\_____  \\ _____ _/  |_|  |__ |    |/ _|____   ____ ______   ___________  \\_____  \\  __ __   ____   _______/  |_ " << endl;
	cout << " /   |   \\\\__  \\\\   __\\  |  \\|      <_/ __ \\_/ __ \\\\____ \\_/ __ \\_  __ \\  /  / \\  \\|  |  \\_/ __ \\ /  ___/\\   __\\" << endl;
	cout << "/    |    \\/ __ \\|  | |   Y  \\    |  \\  ___/\\  ___/|  |_> >  ___/|  | \\/ /   \\_/.  \\  |  /\\  ___/ \\___ \\  |  |  " << endl;
	cout << "\\_______  (____  /__| |___|  /____|__ \\___  >\\___  >   __/ \\___  >__|    \\_____\\ \\_/____/  \\___  >____  > |__|  " << endl;
	cout << "        \\/     \\/          \\/        \\/   \\/     \\/|__|        \\/               \\__>           \\/     \\/        " << endl << endl;
	system("pause");
	system("CLS");

	//intro text of game
	cout << "\tThrone Room\n\n" << "King: ";
	SlowText(king1);		//SlowText function for king's text
	cout << endl << endl;
	cout << "ENTER NAME: ";
	cin >> playerName;		//Enter player's name
	system("CLS");

	cout << "\tThrone Room\n\nKing: ";
	SlowText(king2);		//SlowText function for king's text
	SlowText(playerName);	//SlowText function for playerName
	SlowText(king3);		//SlowText function for king's text
	cout << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room\n\nKing: ";
	SlowText(king4);		//SlowText function for king's text
	cout << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room\n\nKing: ";
	SlowText(king5);		//SlowText function for king's text
	cout << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room\n\nKing: ";
	SlowText(king6);		//SlowText function for king's text
	cout << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room" << endl << endl;
	cout << "'You recieved a Mysterious Key'" << endl;
	cout << "'You recieved Health Potions X 2'" << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room\n\nKing: ";
	SlowText(king7);		//SlowText function for king's text
	SlowText(playerName);	//SlowText function outputting playerName
	cout << "!" << endl << endl;
	system("pause");
	system("CLS");

	cout << "\tThrone Room" << endl << endl;
	cout << "You head out to the enterance of Castle Town to start your adventure." << endl << endl;
	system("pause");
	system("CLS");
	Location1.location = 17;	//set starting location for game
}

void Hints()
{	//checks if flags are passed
	if (Inventory1.Antidote == false)	//if player hasn't found antidote yet
	{
		cout << "There is an item that can ward off poison in the highest peaks."<<endl;
	}
	else if (Inventory1.Antidote == true && Inventory1.PlateArmour == false)	//if player hasn't found armour yet
	{
		cout << "You've recieved the cure, now it's time to venture forth though the poison." << endl;
	}
	else if (Inventory1.PlateArmour == true && Inventory1.OathKeeperSword == false)		//if player hasn't found sword yet
	{
		cout << "The 'lost woods' may drive you mad, but not if you follow the 'SWaN'" << endl;
	}
	else if (Inventory1.OathKeeperSword == true)	//if player has found sword
	{
		cout << "The time has come to finish your mission, in the dark cave the dragon remains." << endl;
	}
	system("pause");
	system("CLS");
}

void Game::Menu()
{

	Player1.Location(Location1.location);	//run location function
	cout << endl << endl;
	Player1.Name(playerName);		//run playerName function
	cout << "'s Health : ";
	Player1.Health();			// run player's Health function
	cout << endl << endl;

	cout << "What would you like to do?" << endl << endl;
	cout << "1. Look around" << endl;
	cout << "2. Move to a new location" << endl;
	cout << "3. Look at equipment" << endl;
	cout << "4. Exit game" << endl;
	if (Location1.location == 9)		//adds an extra option for hints if in area 9
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
		if (option == "1")		//if player inputs "1"
		{
			Location1.LookAround();		//run lookAround function
			correct = true;				//sets correct input has been met
			system("pause");
			system("CLS");
		}
		else if (option == "2")		//if player inputs "2"
		{		
			cout << "Which direction would you like to head?" << endl;
			cin >> direction;		//player inputs direction to walk
			do
			{
				for (int i = 0, n = direction.size(); i < n; i++)		//Set input above to caps
				{
					direction[i] = toupper(direction[i]);
				}
				if (direction == "NORTH")		//if player inputs NORTH
				{
					Location1.WalkNorth();		//run WalkNorth funcation
					system("CLS");
				}
				else if (direction == "SOUTH")	//if player inputs SOUTH
				{
					Location1.WalkSouth();		//run WalkSouth funcation
					system("CLS");	
				}
				else if (direction == "WEST")	//if player inputs WEST
				{
					Location1.WalkWest();		//run WalkWest funcation
					system("CLS");
				}
				else if (direction == "EAST")	//if player inputs EAST
				{
					Location1.WalkEast();		//run WalkEast funcation
					system("CLS");
				}
				else                           //if NORTH, SOUTH, EAST, or WEST was not input
				{
					cout << "Please enter 'NORTH' 'SOUTH' 'EAST' 'WEST' or anything else to pick a new option." << endl;
					cin >> direction;		//Ask for direction again or if anything else was entered, go back to option select
				}
				if (Location1.location == 0 && Inventory1.OathKeeperSword == true)		//checks if player already has sword
				{
					Player1.HaveSword = true;		//player has sword now
				}
				else if (Location1.location == 0)	//if player doesn't have sword but is in correct area
				{
					Inventory1.OathKeeperSword=true;	//adds sword to players inventory
				}
				else if (Location1.location == 4 && Inventory1.Antidote == true)	//checks if player already has antidote
				{
					Player1.HaveAnti = true;		//player has antidote now
				}
				else if (Location1.location == 4)	//if player doesn't have antidote but is in correct area
				{
					Inventory1.Antidote = true;			//adds antidote to players inventory
				}
				else if (Location1.location == 21 && Inventory1.Antidote == false)	//if player doesn't have antidote and is in correct space
				{
					Location1.location = Location1.location -5;		//move back to previous location
					Player1.AddHealth(-30);			//player loses 30 health
					cout << "The swamp to the 'SOUTH' begins to burn your skin as you attempt to walk through it." << endl;
					cout << "'You took 30 damage'" << endl;
					cout << "I think I should probably head back and think of a better way to make it through this." << endl;
					system("pause");
					if (Player1.health <= 0)	//if player's health is 0 or less
					{
						system("CLS");
						cout << "You have lost all your health!" << endl;
						cout << "GAME OVER!" << endl << endl;
						correct = true;		//sets correct input has been met
						game = false;		//end game
					}
				}
				else if (Location1.location == 20 && Inventory1.PlateArmour == true)	//checks if player already has armour
				{
					Player1.HaveArmour = true;		//player has armour now
				}
				else if (Location1.location == 20)		//if player doesn't have armour but is in correct area
				{
					Inventory1.PlateArmour = true;		//adds armour to players inventory
				}
				else if (Location1.location == 24 && Inventory1.OathKeeperSword == true && Inventory1.PlateArmour == true)	//checks if player already has armour and sword
				{
					Player1.win = true;		//sets var for end of game
					correct = true;			//sets correct input has been met
					game = false;			//ends game
				}
			} while (Location1.able == false);	//continue loop until player picks direction they can walk
			correct = true;		//sets correct input has been met
			system("CLS");
		}
		else if (option == "3")		//if player inputs "3"
		{
			correct = true;			//sets correct input has been met
			Inventory1.DrawInventory();		//runs inventory function
			cout << endl << endl;
			if (Inventory1.HealthPotion > 0 && Player1.health < 100)		//if player has health potion and health is less than 100
			{
				cout << "Would you like to use a potion?\nYES/NO" << endl;
				cin >> usePotion;
				for (int i = 0, n = usePotion.size(); i < n; i++)		//switches case to upper
				{
					usePotion[i] = toupper(usePotion[i]);
				}
				if (usePotion == "YES")			//if input is YES
				{
					if (Player1.health < 50)	//if players health is below 50
					{
						Inventory1.HealthPotion--;	//decrease potion count by 1
						Player1.AddHealth(+50);		//heal 50 damage
						cout << "You feel refreshed and gained 50 health back." << endl;
					}
					else                            //if health is between 51-99
					{
						Inventory1.HealthPotion--;	//decrease potion count by 1
						Player1.health=100;			//heal back to 100 health
						cout << "You feel refreshed and gained 50 health back." << endl;
					}
				}
			}
			system("pause");
			system("CLS");
			Choices();	//run Choices funcation
		}
		else if (option == "4")		//if player inputs "4"
		{
			system("CLS");
			cout << "Good bye!" << endl << endl;
			correct = true;		//sets correct input has been met
			game = false;		//ends game
		}
		else if (option == "5" && Location1.location == 9)		//if player inputs "5"
		{
			Hints();		//runs hint funcation
		}
		else
		{
			system("CLS");
			Menu();		//runs menu function
			correct = false;	//sets correct input has been met
			cout << "Please enter a correct option." << endl;
		}
	} while (!correct); //loops until correct input has been met
}

void Game::Play()
{
	Intro();		//runs intro function
	Choices();		//runs Choices funcation
	do
	{
		if (game == true)	//if the game is still running
		{
			Choices();		//run Choices funcation
		}
		if (Player1.win == true)	//if player wins
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
	} while (game == true);	//run loop while game is still running
}


