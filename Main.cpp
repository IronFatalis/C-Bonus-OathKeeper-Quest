#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

//Prototypes
//initializes inventory
void Initialize(const string* container[], int capacity);

//checks to see if inventory is full
bool isFull(const string* const container[], int capacity);

//checks to is if inventory is empty
bool isEmpty(const string* const container[], int capacity);

//tests if an item is in inventory
bool Contains(const string* const pItem, const string* const container[], int capacity);

//displays the items in the inventory
void Display(const string* const container[], int capacity);

//adds an item to the inventory
void Add(const string* const pItem, const string* container[], int capacity);

//removes an item from the inventory
void Remove(const string* const pItem, const string* container[], int capacity);

//Sets intro of the game
void Intro();

//Menu for character choices
void Choices();

bool game = true;
Player Player1 = Player();
string playerName;
int location;
bool resistance = false;


int main()
{
	string option;

	//items
	const int NUM_ITEMS = 5;
	const string items[NUM_ITEMS] = { "Strange Key", "Antidote", "OathKeeper Sword", "Legandary Armour", "Health Potion"  };

	//inventory
	const int INVENTORY_CAPACITY = 8;		//Can hold all items plus 3 Health Potions
	const string* inventory[INVENTORY_CAPACITY];
	Initialize(inventory, INVENTORY_CAPACITY);

	int itemNumber;			//number of the item to add or remove

	Intro();
	Add(&items[0], inventory, INVENTORY_CAPACITY);		//Give player 'strange key'
	Add(&items[4], inventory, INVENTORY_CAPACITY);		//Give player 'health potion'
	Choices();

	do
	{
		if (game == true)
		{
			cout << "INVENTORY" << endl << endl;
			Display(inventory, INVENTORY_CAPACITY);
			system("pause");
			system("CLS");
			Choices();
		}
	} while (game == true);

	return 0;
}

void Initialize(const string* container[], int capacity)
{
	//set all elements to NULL
	for (int i = 0; i < capacity; ++i)
	{
		container[i] = NULL;
	}
}

bool isFull(const string* const container[], int capacity)
{
	bool full = true;
	int i = 0;

	while (full && i < capacity)
	{
		//if there's at least one empty slot...
		if (container[i] == NULL)
		{
			//then the container isn't full
			full = false;
		}
		++i;
	}
	return full;
}

bool isEmpty(const string* const container[], int capacity)
{
	bool empty = true;
	int i = 0;

	while (empty && i < capacity)
	{
		//if a slot isn't empty
		if (container[i] != NULL)
		{
			//then the container isn't empty
			empty = false;
		}
		++i;
	}
	return empty;
}

bool Contains(const string* const pItem, const string* const container[], int capacity)
{
	bool has = false;
	int i = 0;

	while (!has && i < capacity)
	{
		if (container[i] == pItem)
		{
			has = true;
		}
		++i;
	}
	return has;
}

void Display(const string* const container[], int capacity)
{
	//if container is empty, display message saying so and return
	if (isEmpty(container, capacity))
	{
		cout << "<Empty>" << endl;
		return;
	}
	//Otherwise, send all strings pointed to by elements of container to cout
	for (int i = 0; i < capacity; ++i)
	{
		if (container[i] != NULL)
		{
			cout << *(container[i]) << endl;
		}
	}
}

void Add(const string* const pItem, const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		return;
	}

	if (Contains(pItem, container, capacity))
	{
		cout << "I can't hold anymore of that.";
		cout << endl;
		return;
	}

	if (isFull(container, capacity))
	{
		cout << "My inventory is full." << endl;
		return;
	}

	//find first null pointer in container, point it to string pItem points to
	bool found = false;
	int i = 0;
	while (!found && i < capacity)
	{
		if (container[i] == NULL)
		{
			container[i] = pItem;			//add pointer to an item
			found = true;
		}
		++i;
	}
}

void Remove(const string* const pItem, const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		return;
	}

	//set element that is equal to pItem to NULL
	bool found = false;
	int i = 0;

	while (!found && i < capacity)
	{
		if (container[i] == pItem)
		{
			container[i] = NULL;			//remove pointer to an item
			found = true;
		}
		++i;
	}

	//if item wasn't found, say so
	if (!found)
	{
		cout << "Item not found." << endl;
	}
}

void Intro()
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

void Choices()
{
	string option;
	string direction;
	bool able = false;
	bool correct = false;

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

	do
	{
		cout << "Enter Choice: ";
		cin >> option;
		cout << endl;
		if (option == "1")
		{
			cout << "You look around you and see..." << endl << endl;
			if (location == 0)
			{
				cout << "To the 'NORTH' you see a dark, foggy forest. You probably shouldn't head any further in or you might get lost forever." << endl;
				cout << "To the 'SOUTH' it seems like the path you travlled from but you're not sure." << endl;
				cout << "To the 'EAST' you see a dark forest with feight light off in the distance." << endl;
				cout << "To the 'WEST' you see a dark, foggy forest. You probably shouldn't head any further in or you might get lost forever." << endl;
			}
			else if (location == 1)
			{
				cout << "To the 'NORTH' you see a dark, foggy forest. You probably shouldn't head any further in or you might get lost forever." << endl;
				cout << "To the 'SOUTH' you see the forest starting to thin out, possibly the enterance?" << endl;
				cout << "To the 'EAST' you see a sunny clearing with a rocky path." << endl;
				cout << "To the 'WEST' you see the forest is covered in a thick fog." << endl;
			}
			else if (location == 2)
			{
				cout << "To the 'NORTH' you see the ocean off in the distance, but sadly there's no time for a swim." << endl;
				cout << "To the 'SOUTH' you see the back of the castle from here, but there's no way to get to it." << endl;
				cout << "To the 'EAST' you see the path continues upwards around a cliff." << endl;
				cout << "To the 'WEST' you see a forest that becomes almost pitch black the further in you look." << endl;
			}
			else if (location == 3)
			{
				cout << "To the 'NORTH' you see endless waves from the ocean in the distance." << endl;
				cout << "To the 'SOUTH' you can see the whole kingdom from here. You seem to be up very high now." << endl;
				cout << "To the 'EAST' you see a small town tucked away ontop a mountain." << endl;
				cout << "To the 'WEST' you see the path leading back down towards the forest." << endl;
			}
			else if (location == 4)
			{
				cout << "To the 'NORTH' you see an amazing view of the ocean, it seems like it goes on forever." << endl;
				cout << "To the 'SOUTH' you see the cliffside and a lake off in the distance, and the dragon's den even farther than that." << endl;
				cout << "To the 'EAST' you see the area is surrounded by tall mountains you'd never be able to scale." << endl;
				cout << "To the 'WEST' you see the path starting to lead down the mountain side." << endl;
			}
			else if (location == 5)
			{
				cout << "A forest covered in a thick fog in every direction." << endl;
			}
			else if (location == 6)
			{
				cout << "To the 'NORTH' you see the forest continues and becomes darker the further in." << endl;
				cout << "To the 'SOUTH' you see a peaceful river with a bridge crossing over it." << endl;
				cout << "To the 'EAST' you see the walls of the castle town from ealier." << endl;
				cout << "To the 'WEST' you see the forest has a thick layer of fog and becomes very dense." << endl;
			}
			else if (location == 7)
			{
				cout << "A massive throne room fit for a king. All the walls are heavly decorated and there are guards all through the room." << endl;
				cout << "To the 'SOUTH' you see the exit doors of the throne room, along with 2 guards by them." << endl;
			}
			else if (location == 8)
			{
				cout << "To the 'NORTH' you see a massively tall cliff wall." << endl;
				cout << "To the 'SOUTH' you see a bunch of feight glowing lights off in the distance." << endl;
				cout << "To the 'EAST' you see a strange looking door with a keyhole in it." << endl;
				cout << "To the 'WEST' you see the outter wall of the castle town." << endl;
			}
			else if (location == 9)
			{
				cout << "A room that seems impossible. All the cave walls are brightly lit and covered with waterfalls." << endl;
				cout << "To the 'WEST' you see the strange door you came through." << endl;
			}
			else if (location == 10)
			{
				cout << "To the 'NORTH' you see a peaceful river that splits into a forest and further west." << endl;
				cout << "To the 'SOUTH' you see dark clouds in the sky and what looks to be a marsh." << endl;
				cout << "To the 'EAST' you see the river continues and a bridge is crossing over it." << endl;
				cout << "To the 'WEST' you see the river bends around and blocks your path." << endl;
			}
			else if (location == 11)
			{
				cout << "To the 'NORTH' you see across the bridge that there's a forest." << endl;
				cout << "To the 'SOUTH' you see what you think is a marsh in the distance." << endl;
				cout << "To the 'EAST' you see a thick stone wall, probably the castle towns outter wall." << endl;
				cout << "To the 'WEST' you see the river continues along, then splits into two streams." << endl;
			}
			else if (location == 12)
			{
				cout << "To the 'NORTH' you see the main castle. The throne room is this way." << endl;
				cout << "To the 'SOUTH' you see an open drawbridge leading to a grassy field." << endl;
				cout << "To the 'EAST' you see a few townsfolk going about their daily business." << endl;
				cout << "To the 'WEST' you see a shop but it seems to be closed." << endl;
			}
			else if (location == 13)
			{
				cout << "To the 'NORTH' you see a tranquil looking area. It looks like no one has visited it for years." << endl;
				cout << "To the 'SOUTH' you see a giant open, grassy field." << endl;
				cout << "To the 'EAST' you see a rocky shore expanding onto a huge lake." << endl;
				cout << "To the 'WEST' you see the castle town's outter wall, it seems like there is a bit of damage done to it." << endl;
			}
			else if (location == 14)
			{
				cout << "To the 'NORTH' you see a stone mountain wall, it looks like it leads up very high." << endl;
				cout << "To the 'SOUTH' you see the shoreline continues to a beach area." << endl;
				cout << "To the 'EAST' you see the lake continues on farther than you can see. There's a small island out in the middle of it." << endl;
				cout << "To the 'WEST' you see a few dim lights floating off in the distance." << endl;
			}
			else if (location == 15)
			{
				cout << "To the 'NORTH' you see the swampy area ends. Farther out you see a peaceful river and a forest." << endl;
				cout << "To the 'SOUTH' you see the swamp has huge spikey logs shooting from it, like something wants you to stay out." << endl;
				cout << "To the 'EAST' you see the fades into a shallow marshland." << endl;
				cout << "To the 'WEST' you see the swamp becomes very deep and looks impassible." << endl;
			}
			else if (location == 16)
			{
				cout << "To the 'NORTH' you see a peaceful river and a bridge that leads into a forest." << endl;
				cout << "To the 'SOUTH' you see the marsh becomes thick and has a purple tint to it, I should probably be prepared before going through it." << endl;
				cout << "To the 'EAST' you see a big open field and the castle town walls in the distance." << endl;
				cout << "To the 'WEST' you see the waters get a lot thicker and deeper the further west you go." << endl;
			}
			else if (location == 17)
			{
				cout << "To the 'NORTH' you can see into the castle town from here." << endl;
				cout << "To the 'SOUTH' you see a dark cave. That's probably where the dragon was that the king spoke about." << endl;
				cout << "To the 'EAST' you see the open field continues for miles." << endl;
				cout << "To the 'WEST' you see some marshlands that don't look very healthy." << endl;
			}
			else if (location == 18)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 19)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 20)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 21)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 22)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 23)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else if (location == 24)
			{
				cout << "To the 'NORTH' you see..." << endl;
				cout << "To the 'SOUTH' you see..." << endl;
				cout << "To the 'EAST' you see..." << endl;
				cout << "To the 'WEST' you see..." << endl;
			}
			else
			{
				cout << "You see darkness all around you." << endl;
			}
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
					if (location == 0)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 1)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction; 
						cout << endl;
					}
					else if (location == 2)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 3)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 4)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 7)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 8)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 9)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 10)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 14)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 20)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 23)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 24)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else
					{
						location = location - 5;
						able = true;
					}
				}
				else if (direction == "SOUTH")
				{
					if (location == 2)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 3)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 4)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 5)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 9)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 15)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 16)
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
					else if (location == 18)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 19)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 20)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 21)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 22)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 23)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 24)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else
					{
						location = location + 5;
						able = true;
					}
				}
				else if (direction == "WEST")
				{
					if (location == 0)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 5)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 7)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 9)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 10)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 12)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 13)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 15)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 20)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 22)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else
					{
						location = location - 1;
						able = true;
					}
				}
				else if (direction == "EAST")
				{
					if (location == 4)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 6)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 7)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 8)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 11)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 12)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 14)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 19)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 21)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else if (location == 24)
					{
						cout << "You can't go that way" << endl;
						cout << "Please enter a new direction:" << endl;
						cin >> direction;
						cout << endl;
					}
					else
					{
						location = location + 1;
						able = true;
					}
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
			cout << "Good bye!"<<endl << endl;
			correct = true;
			game = false;
		}
		else
		{
			system("CLS");
			Player1.Location(location);
			cout << endl << endl << "HEALTH : ";
			Player1.Health();
			cout << endl << endl;
			cout << "What would you like to do?" << endl << endl;
			cout << "1. Look around" << endl;
			cout << "2. Move to a new loaction" << endl;
			cout << "3. Look at equipment" << endl;
			cout << "4. Exit game" << endl << endl;
			cout << "Please enter a correct option." << endl;
		}
	} while (!correct);
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
