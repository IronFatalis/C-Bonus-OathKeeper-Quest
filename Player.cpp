#include "Player.h"
#include "Inventory.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{
	health = 100;		//setting health for player
}

void Player::Health()
{
	cout << health;		//outputs the current health of player
}

void Player::Location(int location)
{
	if (location == 0)		//checks location of player and outputs decription of current area.
	{
		if (HaveSword == true)	//checks if player already has sword
		{
			cout << "\tOathKeeper Shrine" << endl << endl;
			cout << "You come to a beautiful clearing in the forest with light shimmering down from the treetops " << endl;
			cout << "In the middle of the clearing you can see a pedestal with a dim glowing light coming from it." << endl;
			cout << "You move over and touch the light..." << endl;
			cout << "Nothing happens." << endl;
		}
		else               //If player does not have sword, run a different description
		{
			cout << "\tOathKeeper Shrine" << endl << endl;
			cout << "You come to a beautiful clearing in the forest with light shimmering down from the treetops " << endl;
			cout << "In the middle of the clearing you can see a pedestal with a bright glowing light coming from it." << endl;
			cout << "You move over and touch the light to find the Legendary OathKeeper Sword in your hand!" << endl;
			cout << "'You obtained the OathKeeper Sword'" << endl;
		}
	}
	else if (location == 1)
	{
		cout << "\tDeep Forest" << endl << endl;
		cout << "You move deeper into the woods and feel an odd feeling. It's like this forest has a mind of " << endl;
		cout << "it's own, bending and shaping itself however it pleases." << endl;
		cout << "It's probably not a good idea to stay here for to long." << endl << endl;
	}
	else if (location == 2)
	{
		cout << "\tUphill Path" << endl << endl;
		cout << "You come to a path beside the forest that leads up the side of a mountain." << endl;
		cout << "The road seems a bit rocky, but nothing to hard to travel up. You can't really" << endl;
		cout << "tell how high up this path leads, but the crisp smell of ocean air is refreshing" << endl << endl;
	}
	else if (location == 3)
	{
		cout << "\tCliff Side Path" << endl << endl;
		cout << "The path is becoming steeper the higher up it goes. On each side of you there" << endl;
		cout << "is a massive drop as the path becomes narrower. It doesn't seem dangerous though" << endl;
		cout << "as long as you keep paying attention." << endl << endl;
	}
	else if (location == 4)
	{
		if (HaveAnti == true)	//checks if player has antidote, if so outputs this description
		{
			cout << "\tSmall Mountain Town" << endl << endl;
			cout << "You come to a small mountain town with only a few villagers. There's kids running around playing" << endl;
			cout << "and some adults sitting and talking. It seems like a very peaceful little village. This might be" << endl;
			cout << "a nice place to go retire after finishing this quest." << endl << endl;
		}
		else                   //if player does not have antidote, outputs this
		{
			cout << "\tSmall Mountain Town" << endl << endl;
			cout << "You come to a small mountain town with only a few villagers. There's kids running around playing" << endl;
			cout << "and some adults sitting and talking. It seems like a very peaceful little village. You notice a" << endl;
			cout << "stand with a bunch of potions on it and the adult behind it calls you over and hands you an antidote." << endl;
			cout << "'You obtained an Antidote'" << endl;
		}
	}
	else if (location == 5)
	{
		cout << "\tLost Forest" << endl << endl;
		cout << "You move deep into the forest, fog is surrounding you and you're not sure if you've " << endl;
		cout << "been here before or not. Everything looks the same and it feels like you've been walking " << endl;
		cout << "for hours. It feels like there's some sort of magic in this forest and you wont be able " << endl;
		cout << "to pass through until you figure it out" << endl;
	}
	else if (location == 6)
	{
		cout << "\tForest Enterance" << endl << endl;
		cout << "The outskirts of the forest seems very peaceful, with the light noise of the river in the " << endl;
		cout << "distance. This looks like your typical forest, with a few logs tipped over by the enterance" << endl;
		cout << "and the noise of a few wildlife coming from within. You get the strange feeling that something" << endl;
		cout << "might be a bit off with this forest though." << endl;
	}
	else if (location == 7)
	{
		cout << "\tThrone Room" << endl << endl;
		cout << "As you enter the Throne Room, two guards come to halt your progress. The king waves them down and asks" << endl;
		cout << "King: Have you completed your quest? If not please do not return until you have. Our kingdom is " << endl;
		cout << "counting on you." << endl;
		cout << "You should really get back to fulfilling the King's orders." << endl;
	}
	else if (location == 8)
	{
		cout << "\tMystical Door" << endl << endl;
		cout << "You come to a meadow that seems like it has some sort of mystical power coming from it." << endl;
		cout << "In the cliffside there is a very strange looking door but it seems like one shrine the King was" << endl;
		cout << "talking about easlier. You pull out your strange key and surprisingly it fits perfectly to open " << endl;
		cout << "the door." << endl;
	}
	else if (location == 9)
	{
		cout << "\tHoly Shrine" << endl << endl;
		cout << "This area seems like it's not from this world. There's a big marble bridge that leads to a shrine in" << endl;
		cout << "the middle of the giant room. All the walls look pitch black with waterfalls glistening on every wall." << endl;
		cout << "The shrine in the middle has fountains all around it and a slab that reads 'IF THOU SEEKS KNOWLEDGE," << endl;
		cout << "THEN SPEAK HINT AT THE VISAGE OF THY SHRINE'" << endl;
	}
	else if (location == 10)
	{
		cout << "\tRiver Side" << endl << endl;
		cout << "You come to the riverside and see the water is beginning to speed up a bit before splitting " << endl;
		cout << "into a few streams. The water looks to deep to be able to cross, but I bet there'd be no issues" << endl;
		cout << "crossing the bridge to the 'EAST'. For now though, this seems like a relaxing area to take a seat" << endl << endl;
	}
	else if (location == 11)
	{
		cout << "\tRiver Bridge" << endl << endl;
		cout << "You come to a bridge crossing over a calm river. There's flowers planted around both sides of the bridge" << endl;
		cout << "and you can see a log with a family of frogs in the river and some fish swimming by." << endl;
		cout << "It's areas like this that make me motivated to keep the peace in this kingdom." << endl << endl;
	}
	else if (location == 12)
	{
		cout << "\tCastle Town" << endl << endl;
		cout << "Oh Castle Town. It's always busy here with people going about their daily lives and shop keeps " << endl;
		cout << "always trying to swindle people out of their hard earned money. The kingdom is safe because of the" << endl;
		cout << "gaint stone wall surounding it and the huge castle to the 'NORTH' end of the city." << endl;
		cout << "It's probably time I head on my journey." << endl;
	}
	else if (location == 13)
	{
		cout << "\tFirefly Meadow" << endl << endl;
		cout << "For some strange reason this place always appears as if it's night time. Because of that " << endl;
		cout << "though it attacts all sorts of insects and nocturnal creatures. It's always filled with " << endl;
		cout << "fireflys too, that's how it got it's name as the FireFly Meadow." << endl << endl;
	}
	else if (location == 14)
	{
		cout << "\tRocky Shoreline" << endl << endl;
		cout << "You come to a rocky shore that would probably be great for fishing. The rocks here " << endl;
		cout << "look fairly stable and have eroded away with time from the water. The ground it covered" << endl;
		cout << "in gravel the closer you get to the water." << endl << endl;
	}
	else if (location == 15)
	{
		cout << "\tThick Swamp" << endl << endl;
		cout << "You come to a thick sticky swamp. The water is gross walking through but you have no choice." << endl;
		cout << "Moving farther in you notice it just gets deeper and deeper, then decide to turn back," << endl;
		cout << "pulling peices of bramble off you." << endl << endl;
	}
	else if (location == 16)
	{
		cout << "\tMarshlands" << endl << endl;
		cout << "You come to a shallow marsh, the noise of frogs and crickets almost deafening. The water here" << endl;
		cout << "seems clean enough, atleast for a marsh, but to the 'SOUTH' the water begins to turn purple in" << endl;
		cout << "color. There's definitally something wrong with it. No noise can be hear from that direction either" << endl << endl;
	}
	else if (location == 17)
	{
		cout << "\tCastle Bridge" << endl << endl;
		cout << "You see a huge portcullis with a lowered drawbridge infront of it. The gate is what seperates" << endl;
		cout << "the Castle City from the huge grassy field just outside of it. There's some water running across" << endl;
		cout << "the front of the town's outter wall and a few small flower patches in various places." << endl << endl;
	}
	else if (location == 18)
	{
		cout << "\tGrassy Field" << endl << endl;
		cout << "You come to a large, grassy field that goes on for a few miles in each direction" << endl;
		cout << "The field is very flat and covered in a bright carpet of grass. A family of elf can " << endl;
		cout << "been seen off in the distance but other than that and a ton of bugs the field is empty." << endl << endl;
	}
	else if (location == 19)
	{
		cout << "\tBeach" << endl << endl;
		cout << "You come to a small beach on the side of the lake. It seems deserted and you can guess that the" << endl;
		cout << "dragon has something to do with it because of the giant claw marks on the cliffside to the 'SOUTH'" << endl;
		cout << "of you. Out in the middle of the lake there is a small island, to far to be able to tell if anything " << endl;
		cout << "inhabits it though." << endl;
	}
	else if (location == 20)
	{
		if (HaveArmour == false)	//checks if player has armour, if so outputs this
		{
			cout << "\tGoblin Fortress" << endl << endl;
			cout << "You see an inclosed fortress filled with dozens of tiny goblins, all seemingly covering in fear of you. At the" << endl;
			cout << "back of you fortress you see a giant goblin with 2 others decked out in full armour about your size. There's an" << endl;
			cout << "empty set of armour beside the giant goblin that he points to and grunts. The the goblin points to you and out " << endl;
			cout << "the door towards the cave wall. You hesitantly grab the armour from the giant goblin. 'You obtained a set of armour'" << endl;
		}
		else                      //if player does not have armour outputs this
		{
			cout << "\tGoblin Fortress" << endl << endl;
			cout << "You return to the Goblin Fortress to see the giant goblin from before staring at you growling." << endl;
			cout << "He takes a swing at you with his club but misses. All the other goblins are hiding and seem scared." << endl;
			cout << "You should probably leave before the giant goblin decides to take another swing." << endl << endl;
		}
	}
	else if (location == 21)
	{
		cout << "\tPoisonous Marsh" << endl << endl;
		cout << "You entered the purple water, the antidote you took seems to be warding off the poison from within." << endl;
		cout << "Though you are not taking damage, the water is still gross to walk through. It's sticky and has" << endl;
		cout << "rotting corpses of animals in it, some looking fairly fresh with spears sticking out of them. The" << endl;
		cout << "water is about chest high but does not seem to be getting any deeper unless you're heading 'SOUTH'." << endl;
	}
	else if (location == 22)
	{
		cout << "\tCave Enterance" << endl << endl;
		cout << "You come to a wet, dark cave. There are scratch marks all around the enterance and it looks like" << endl;
		cout << "they continue inside. You can't see very far into the cave because of how dark it is, but there is" << endl;
		cout << "a single torch mounted on the wall by the enterance. You're guessing that this is the location of" << endl;
		cout << "the dragon you were sent to defeat." << endl;
	}
	else if (location == 23)
	{
		cout << "\tDark Cave" << endl << endl;
		cout << "You move deeper in the cave, to where it's almost pitch black now. You can hear dripping coming " << endl;
		cout << "from the walls and a low rumbling off in the distance. The only way you can tell where you're " << endl;
		cout << "going is by clinging to the walls as you walk." << endl << endl;
	}
	else if (location == 24)
	{
			cout << "\tDragon's Nest" << endl << endl;
			cout << "You enter the Dragon's Nest, where you see the dragon sleeping beside a fire. It seems " << endl;
			cout << "like a small area in the back of this cave where you wouldn't have space for a full combate " << endl;
			cout << "with the dragon. This could be your best chance, to strike while it's sleeping." << endl << endl;
	}
	else       //if player somehow leaves gamespace it'll output this line
	{
		cout << "\tYou've left the quest area!" << endl;
	}
}

void Player::Name(string playerName)
{
	cout << playerName;	//outputs players inputted name
}

void Player::AddHealth(float Points)
{
	health += Points;	//can add or subtract "Points" value from health
}