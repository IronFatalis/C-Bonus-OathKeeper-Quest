#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{

private:

public:
	float health;
	Player();
	void Health();
	void Name(string playerName);
	void AddHealth(float Points);
	void Location(int location);
};

