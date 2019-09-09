#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game
{

private:

public:
	void Intro();
	void Choices();
	void Menu();
	void Play();
	string playerName;
	string option;
	string direction;
	bool correct = false;
	bool game = true;
	bool resistance = false;
};
