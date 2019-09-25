#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"
#include "Inventory.h"

using namespace std;

int main()
{
	system("mode 125");			//setting screen size
	Game PlayGame = Game();		//creating instance of PlayGame from Game class.
	PlayGame.Play();			//running PlayGame class function
	return 0;					//Exits out of program
}