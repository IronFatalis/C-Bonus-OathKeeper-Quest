#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{

private:

public:
	float health;
	bool win = false;
	Player();
	void Health();
	void Name(string playerName);
	void AddHealth(float Points);
	void Location(int location);
	bool HaveSword = false;
	bool HaveArmour = false;
	bool HaveAnti = false;
};