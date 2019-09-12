#pragma once
#include <iostream>
#include <string>

using namespace std;

class Location
{

private:

public:
	void LookAround();
	void WalkNorth();
	void WalkSouth();
	void WalkEast();
	void WalkWest();
	int location;
	bool able = false;
	int notLost = 0;
};