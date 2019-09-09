#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{
	health = 100;
}

void Player::Health()
{
	cout << health;
}

void Player::Location(int location)
{
	if (location == 0)
	{
		cout << "\tOathKeeper Shrine" << endl << endl;
	}
	else if (location == 1)
	{
		cout << "\tDeep Forest" << endl;
	}
	else if (location == 2)
	{
		cout << "\tUphill Path" << endl;
	}
	else if (location == 3)
	{
		cout << "\tCliff Side Path" << endl;
	}
	else if (location == 4)
	{
		cout << "\tSmall Mountain Town" << endl;
	}
	else if (location == 5)
	{
		cout << "\tLost Forest" << endl;
	}
	else if (location == 6)
	{
		cout << "\tForest Enterance" << endl;
	}
	else if (location == 7)
	{
		cout << "\tThrone Room" << endl;
	}
	else if (location == 8)
	{
		cout << "\tMystical Door" << endl;
	}
	else if (location == 9)
	{
		cout << "\tHoly Shrine" << endl;
	}
	else if (location == 10)
	{
		cout << "\tRiver Side" << endl;
	}
	else if (location == 11)
	{
		cout << "\tRiver Bridge" << endl;
	}
	else if (location == 12)
	{
		cout << "\tCastle Town" << endl;
	}
	else if (location == 13)
	{
		cout << "\tFirefly Meadow" << endl;
	}
	else if (location == 14)
	{
		cout << "\tRocky Shoreline" << endl;
	}
	else if (location == 15)
	{
		cout << "\tThick Swamp" << endl;
	}
	else if (location == 16)
	{
		cout << "\tMarshlands" << endl;
	}
	else if (location == 17)
	{
		cout << "\tCastle Bridge" << endl;
	}
	else if (location == 18)
	{
		cout << "\tGrassy Field" << endl;
	}
	else if (location == 19)
	{
		cout << "\tBeach" << endl;
	}
	else if (location == 20)
	{
		cout << "\tVile Swamp" << endl;
	}
	else if (location == 21)
	{
		cout << "\tPoisonous Marsh" << endl;
	}
	else if (location == 22)
	{
		cout << "\tCave Enterance" << endl;
	}
	else if (location == 23)
	{
		cout << "\tDark Cave" << endl;
	}
	else if (location == 24)
	{
		cout << "\tDragon's Nest" << endl;
	}
	else
	{
		cout << "\tYou've left the quest area!" << endl;
	}
}

void Player::Name(string playerName)
{
	cout << playerName;
}

void Player::AddHealth(float Points)
{
	health += Points;
}
