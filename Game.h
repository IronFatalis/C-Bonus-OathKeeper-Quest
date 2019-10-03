#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game
{

private:
	void Intro();
	void Choices();
	void Menu();
	void SlowText(string text);

	string playerName;
	string option;
	string direction;
	bool correct = false;
	bool game = true;
	bool resistance = false;
	string usePotion;

	int x = 0;
	string king1 = "Welcome to my Throne Room, knight.\nWhat was your name again?";
	string king2 = "Oh yes, now I remember. ";
	string king3 = " is a splendid name I shall not forget it.";
	string king4 = "I have a quest for you to undertake, should you succeed,\nI shall grant you any one thing from my kingdom that is within my power.";
	string king5 = "What is this task you might ask? Well it's to slay the\ndragon plaguing our kingdom of course!";
	string king6 = "Here are some health potions and a key to the shrine to the EAST. I suggest you\nvisit it before you go on your way with your quest.";
	string king7 = "Good luck ";
public:
	void Play();
};