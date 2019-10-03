#pragma once
#include <iostream>
#include <string>

using namespace std;

class Location
{

private:
	int notLost = 0;
public:
	void LookAround();
	void WalkNorth();
	void WalkSouth();
	void WalkEast();
	void WalkWest();
	int location;
	bool able = false;

};