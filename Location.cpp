#include "Location.h"
#include "Inventory.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void Location::LookAround()
{
	cout << "You look around you and see..." << endl << endl;	//outputs this line everytime LookAround is called
	if (location == 0)											//checks location the outputs texts depending on where player is located
	{
		cout << "To the 'NORTH' and 'WEST' you see a dark, foggy forest." << endl;
		cout << "To the 'SOUTH' it seems like the path you travlled from but you're not sure." << endl;
		cout << "To the 'EAST' you see a dark forest with feight light off in the distance." << endl;
	}
	else if (location == 1)
	{
		cout << "To the 'NORTH' you see a dark, foggy forest." << endl << endl;
		cout << "To the 'SOUTH' you see the forest starting to thin out, possibly the enterance?" << endl << endl;
		cout << "To the 'EAST' you see a sunny clearing with a rocky path." << endl << endl;
		cout << "To the 'WEST' you see the forest is covered in a thick fog." << endl << endl;
	}
	else if (location == 2)
	{
		cout << "To the 'NORTH' you see the ocean off in the distance, but sadly there's " << endl;
		cout << "no time for a swim." << endl << endl;
		cout << "To the 'SOUTH' you see the back of the castle from here, but there's no " << endl;
		cout << "way to get to it." << endl << endl;
		cout << "To the 'EAST' you see the path continues upwards around a cliff." << endl << endl;
		cout << "To the 'WEST' you see a forest that becomes almost pitch black the further " << endl;
		cout << "in you look." << endl << endl;
	}
	else if (location == 3)
	{
		cout << "To the 'NORTH' you see endless waves from the ocean in the distance." << endl << endl;
		cout << "To the 'SOUTH' you can see the whole kingdom from here. You seem to be up " << endl;
		cout << "very high now." << endl << endl;
		cout << "To the 'EAST' you see a small town tucked away ontop a mountain." << endl << endl;
		cout << "To the 'WEST' you see the path leading back down towards the forest." << endl << endl;
	}
	else if (location == 4)
	{
		cout << "To the 'NORTH' you see an amazing view of the ocean, it seems like it goes " << endl;
		cout << "on forever." << endl << endl;
		cout << "To the 'SOUTH' you see the cliffside and a lake off in the distance, and the " << endl;
		cout << "dragon's den even farther than that." << endl << endl;
		cout << "To the 'EAST' you see the area is surrounded by tall mountains you'd never be " << endl;
		cout << "able to scale." << endl << endl;
		cout << "To the 'WEST' you see the path starting to lead down the mountain side." << endl << endl;
	}
	else if (location == 5)
	{
		cout << "A forest covered in a thick fog in every direction." << endl << endl;
	}
	else if (location == 6)
	{
		cout << "To the 'NORTH' you see the forest continues and becomes darker the further in." << endl << endl;
		cout << "To the 'SOUTH' you see a peaceful river with a bridge crossing over it." << endl << endl;
		cout << "To the 'EAST' you see the walls of the castle town from ealier." << endl << endl;
		cout << "To the 'WEST' you see the forest has a thick layer of fog and becomes very dense." << endl << endl;
	}
	else if (location == 7)
	{
		cout << "A massive throne room fit for a king. All the walls are heavly decorated and " << endl;
		cout << "there are guards all through the room." << endl << endl;
		cout << "To the 'SOUTH' you see the exit doors of the throne room, along with 2 guards" << endl;
		cout << "by them." << endl << endl;
	}
	else if (location == 8)
	{
		cout << "To the 'NORTH' you see a massively tall cliff wall." << endl << endl;
		cout << "To the 'SOUTH' you see a bunch of feight glowing lights off in the distance." << endl << endl;
		cout << "To the 'EAST' you see a strange looking door with a keyhole in it." << endl << endl;
		cout << "To the 'WEST' you see the outter wall of the castle town." << endl << endl;
	}
	else if (location == 9)
	{
		cout << "A room that seems impossible. All the cave walls are brightly lit and covered" << endl;
		cout << "with waterfalls." << endl << endl;
		cout << "To the 'WEST' you see the strange door you came through." << endl << endl;
	}
	else if (location == 10)
	{
		cout << "To the 'NORTH' you see a peaceful river that splits into a forest and further west." << endl << endl;
		cout << "To the 'SOUTH' you see dark clouds in the sky and what looks to be a marsh." << endl << endl;
		cout << "To the 'EAST' you see the river continues and a bridge is crossing over it." << endl << endl;
		cout << "To the 'WEST' you see the river bends around and blocks your path." << endl << endl;
	}
	else if (location == 11)
	{
		cout << "To the 'NORTH' you see across the bridge that there's a forest." << endl << endl;
		cout << "To the 'SOUTH' you see what you think is a marsh in the distance." << endl << endl;
		cout << "To the 'EAST' you see a thick stone wall, probably the castle towns outter wall." << endl << endl;
		cout << "To the 'WEST' you see the river continues along, then splits into two streams." << endl << endl;
	}
	else if (location == 12)
	{
		cout << "To the 'NORTH' you see the main castle. The throne room is this way." << endl << endl;
		cout << "To the 'SOUTH' you see an open drawbridge leading to a grassy field." << endl << endl;
		cout << "To the 'EAST' you see a few townsfolk going about their daily business." << endl << endl;
		cout << "To the 'WEST' you see a shop but it seems to be closed." << endl << endl;
	}
	else if (location == 13)
	{
		cout << "To the 'NORTH' you see a tranquil looking area. It looks like no one has" << endl;
		cout << "visited it for years." << endl << endl;
		cout << "To the 'SOUTH' you see a giant open, grassy field." << endl << endl;
		cout << "To the 'EAST' you see a rocky shore expanding onto a huge lake." << endl << endl;
		cout << "To the 'WEST' you see the castle town's outter wall, it seems like there is a " << endl;
		cout << "bit of damage done to it." << endl << endl;
	}
	else if (location == 14)
	{
		cout << "To the 'NORTH' you see a stone mountain wall, it looks like it leads up very high." << endl << endl;
		cout << "To the 'SOUTH' you see the shoreline continues to a beach area." << endl << endl;
		cout << "To the 'EAST' you see the lake continues on farther than you can see. There's a " << endl;
		cout << "small island out in the middle of it." << endl << endl;
		cout << "To the 'WEST' you see a few dim lights floating off in the distance." << endl << endl;
	}
	else if (location == 15)
	{
		cout << "To the 'NORTH' you see the swampy area ends. Farther out you see a peaceful " << endl;
		cout << "river and a forest." << endl << endl;
		cout << "To the 'SOUTH' you see the swamp has huge spikey logs shooting from it, like " << endl;
		cout << "something wants you to stay out." << endl << endl;
		cout << "To the 'EAST' you see the fades into a shallow marshland." << endl << endl;
		cout << "To the 'WEST' you see the swamp becomes very deep and looks impassible." << endl << endl;
	}
	else if (location == 16)
	{
		cout << "To the 'NORTH' you see a peaceful river and a bridge that leads into a forest." << endl << endl;
		cout << "To the 'SOUTH' you see the marsh becomes thick and has a purple tint to it, " << endl;
		cout << "I should probably be prepared before going through it." << endl << endl;
		cout << "To the 'EAST' you see a big open field and the castle town walls in the distance." << endl << endl;
		cout << "To the 'WEST' you see the waters get a lot thicker and deeper the further west you go." << endl << endl;
	}
	else if (location == 17)
	{
		cout << "To the 'NORTH' you can see into the castle town from here." << endl << endl;
		cout << "To the 'SOUTH' you see a dark cave. That's probably where the dragon was that " << endl;
		cout << "the king spoke about." << endl << endl;
		cout << "To the 'EAST' you see the open field continues for miles." << endl << endl;
		cout << "To the 'WEST' you see some marshlands that don't look very healthy." << endl << endl;
	}
	else if (location == 18)
	{
		cout << "To the 'NORTH' you see tiny shimmering lights floating through the air." << endl << endl;
		cout << "To the 'SOUTH' you see a big stone cliffside." << endl << endl;
		cout << "To the 'EAST' you see a beach to a lake in the distance." << endl << endl;
		cout << "To the 'WEST' you see the field continuing and an opening in the cliffside." << endl << endl;
	}
	else if (location == 19)
	{
		cout << "To the 'NORTH' you see a rocky area continuing beside the lake." << endl << endl;
		cout << "To the 'SOUTH' you see the cliff continues past the shoreline into the water." << endl << endl;
		cout << "To the 'EAST' you see water that goes on for miles with a little island very far out." << endl << endl;
		cout << "To the 'WEST' you see a vast field and the Castle Town looks like a tiny speck " << endl;
		cout << "from here." << endl << endl;
	}
	else if (location == 20)
	{
		cout << "Bramble and pikes line the walls all around you. There are a bunch of small " << endl;
		cout << "goblins hiding in various places" << endl << endl;
		cout << "To the 'EAST' you see the exit to the goblin fortress." << endl << endl;
	}
	else if (location == 21)
	{
		cout << "To the 'NORTH' you see the swamp thins out into a shallow marsh." << endl << endl;
		cout << "To the 'SOUTH' you see thick bramble and the poison swamp goes on for miles." << endl << endl;
		cout << "To the 'EAST' you see a stone wall rapping around to the grassy plains." << endl << endl;
		cout << "To the 'WEST' you see a small wodden fortress in the middle of the swamp." << endl << endl;
	}
	else if (location == 22)
	{
		cout << "To the 'NORTH' you see the grassy field with the Castle Town not to far off in " << endl;
		cout << "the distance." << endl << endl;
		cout << "To the 'SOUTH' you see a cave wall with a single lit torch on it." << endl << endl;
		cout << "To the 'EAST' you see the cave becomes very dark, almost pitch black farther in." << endl << endl;
		cout << "To the 'WEST' you see a cave wall with huge scratch marks all over it." << endl << endl;
	}
	else if (location == 23)
	{
		cout << "You can't see much because of how dark it is but you hear dripping water from " << endl;
		cout << "off the walls" << endl << endl;
		cout << "To the 'EAST' you hear a low grumbling noise coming from deeper into the cave." << endl << endl;
		cout << "To the 'WEST' you see a dim light coming from what you think is the enterance " << endl;
		cout << "to the cave." << endl << endl;
	}
	else if (location == 24)
	{
		cout << "A fire on the ground with the dragon sleeping next to it. Now would be your best chance " << endl;
		cout << "to slay the beast if you had a sword!" << endl << endl;
		cout << "To the 'WEST' you can see a verry dim light coming from the enterance." << endl << endl;
	}
	else
	{
		cout << "You see darkness all around you." << endl << endl;	//will output if player uses lookaround when outside of game area
	}
}

void Location::WalkNorth()
{
	if (location == 0)	//checks location of player, then outputs correct data if player is trying to walk North
	{
		cout << "I probably shouldn't head any further in or I might get lost forever." << endl;
		system("pause");
	}
	else if (location == 1)
	{
		cout << "I probably shouldn't head any further in or I might get lost forever." << endl;
		system("pause");
	}
	else if (location == 2)
	{
		cout << "Now it no time for a swim, maybe after my adventure is finished." << endl;
		system("pause");
	}
	else if (location == 3)
	{
		cout << "The cliff is to steep, one wrong move and I'd be a gonner." << endl;
		system("pause");
	}
	else if (location == 4)
	{
		cout << "I'm way to high up, maybe if I had some sort of rope I could make my " << endl;
		cout << "way down." << endl;
		system("pause");
	}
	else if (location == 5)
	{
		if (notLost == 2)	//checks if on correct step for lost woods "lock"
		{
			notLost++;		//add to counter for lost woods "lock" 
		}
		if (notLost < 3)	//if lost woods "lock" is not broken, does not move to next area
		{
			cout << "This forest is so foggy I can barely see, I can't tell if I'm going the right way" << endl;
			cout << "or not." << endl;
			notLost = 0;	//resets lost woods "lock"
			system("pause");
		}
		else               //if the lost woods "lock" is broken
		{
			location = location - 5;	//move to next area
			able = true;				//passes check for if player is able to move
		}
	}
	else if (location == 7)
	{
		cout << "Even if I could go through the wall somehow, the guards would have my head." << endl;
		system("pause");
	}
	else if (location == 8)
	{
		cout << "I could maybe scale this wall if I had the proper gear." << endl;
		system("pause");
	}
	else if (location == 9)
	{
		cout << "There's no possible way I could even try going over there." << endl;
		system("pause");
	}
	else if (location == 10)
	{
		cout << "I have no way to cross the river from here, maybe I should head back " << endl;
		cout << "to the bridge?" << endl;
		system("pause");
	}
	else if (location == 14)
	{
		cout << "I think the only way I'd make it up that wall is if I could fly." << endl;
		system("pause");
	}
	else if (location == 20)
	{
		cout << "The walls here don't look the sturdiest, but I still wouldn't want to " << endl;
		cout << "be impaled by them." << endl;
		system("pause");
	}
	else if (location == 23)
	{
		cout << "There seems to be a damp wall here." << endl;
		system("pause");
	}
	else if (location == 24)
	{
		cout << "I should either finish the dragon or leave before it wakes." << endl;
		system("pause");
	}
	else                            //anything in this means the player is able to walk this direction
	{
		location = location - 5;	//moves player North 1 space
		able = true;				//passes check for if player is able to move
	}
}

void Location::WalkSouth()
{
	if (location == 2)	//checks location of player, then outputs correct data if player is trying to walk North
	{
		cout << "I'm pretty sure if I tried to break into the Castle Town from here " << endl;
		cout << "I'd be hung by the King." << endl;
		system("pause");
	}
	else if (location == 3)
	{
		cout << "Let's not go this way, one wrong move and I'd be a gonner." << endl;
		system("pause");
	}
	else if (location == 4)
	{
		cout << "I'd rather not fall to my death." << endl;
		system("pause");
	}
	else if (location == 5)
	{
		if (notLost < 3)	//checks to see if lost woods "lock" is broken
		{	//if "lock" is not broken...
			cout << "This forest is so foggy I can barely see, I can't tell if I'm going the right way" << endl;
			cout << "or not." << endl;
			if (notLost == 0)		//checks if on correct step for lost woods "lock"
			{
				notLost++;			//add to counter for lost woods "lock" if direction is correct
			}
			else if (notLost != 3)  //if lost woods "lock" is not broken, does not move to next area
			{
				notLost = 0;		//Reset lost woods "lock"
			}
			system("pause");
		}
		else       //if "lock" is broken...
		{
			cout << "I think I can see the river this way. Maybe I should head to the " << endl;
			cout << "bridge instead?" << endl;
			system("pause");
		}
	}
	else if (location == 9)
	{
		cout << "There is no possible way I could even attempt to go that way." << endl;
		system("pause");
	}
	else if (location == 15)
	{
		cout << "Even if I made it through all the bramble, there's no way I'd be " << endl;
		cout << "able to go over that wall." << endl;
		system("pause");
	}
	else if (location == 18)
	{
		cout << "Maybe I should go back to the cave enterance instead of making a new one?" << endl;
		system("pause");
	}
	else if (location == 19)
	{
		cout << "I'd be washed away by the tide if I tried to continue." << endl;
		system("pause");
	}
	else if (location == 20)
	{
		cout << "I'd rather not get impailed by the giant spikes of wood, maybe I " << endl;
		cout << "should just leave?" << endl;
		system("pause");
	}
	else if (location == 21)
	{
		cout << "There's no way I'd make it across this whole swamp without some " << endl;
		cout << "sort of boat." << endl;
		system("pause");
	}
	else if (location == 22)
	{
		cout << "This wall looks pretty sturdy, maybe a kick will... 'kicks wall'... nope." << endl;
		system("pause");
	}
	else if (location == 23)
	{
		cout << "Ouch, I think I just walked into a wall, it was slimey too!" << endl;
		system("pause");
	}
	else if (location == 24)
	{
		cout << "Maybe I shouldn't stick around here if I'm not going to finish off " << endl;
		cout << "this dragon." << endl;
		system("pause");
	}
	else     //everything here tells the player they are able to move South
	{
		location = location + 5;	//moves player South one space
		able = true;				//passes check for if player is able to move
	}
}

void Location::WalkWest()
{
	if (location == 0)	//checks location of player, then outputs correct data if player is trying to walk North
	{
		cout << "I probably shouldn't head any further in or I might get lost forever." << endl;
		system("pause");
	}
	else if (location == 1 && notLost != 3)
	{
		cout << "The fog is so thick, I can't even see infront of me." << endl;
		system("pause");
	}
	else if (location == 5)
	{
		if (notLost < 3)		//checks if lost woods "lock" is broken
		{		//if "lock" is not broken
			cout << "This forest is so foggy I can barely see, I can't tell if I'm going the right way" << endl;
			cout << "or not." << endl;
			if (notLost == 1)	//checks if it's the correct step for "lock" progression
			{
				notLost++;		//adds to "lock" counter
			}
			else if (notLost != 3)	//if "lock" is not on correct step or finished
			{
				notLost = 0;	//resets "lock" counter
			}
			system("pause");
		}
		else
		{
			cout << "I probably shouldn't head any further in or I might get lost forever." << endl;
			system("pause");
		}
	}
	else if (location == 7)
	{
		cout << "I don't think the guards would act to kindly if I tried to enter the " << endl;
		cout << "King's bedroom." << endl;
		system("pause");
	}
	else if (location == 8)
	{
		cout << "No matter how many times I try, I still can't walk through walls." << endl;
		system("pause");
	}
	else if (location == 10)
	{
		cout << "I have no way to cross this river, maybe I can find something?" << endl;
		system("pause");
	}
	else if (location == 12)
	{
		cout << "If this shop wasn't closed I could be finished with my quest right now." << endl;
		system("pause");
	}
	else if (location == 13)
	{
		cout << "Maybe if I punch the wall I can make a new enterance... Nope but now " << endl;
		cout << "my hand hurts." << endl;
		system("pause");
	}
	else if (location == 15)
	{
		cout << "This swamp looks way to dangerous to cross without a boat. I'm not " << endl;
		cout << "going and you can't make me." << endl;
		system("pause");
	}
	else if (location == 20)
	{
		cout << "Pretty sure that huge goblin will eat me if I try to pass him." << endl;
		system("pause");
	}
	else if (location == 22)
	{
		cout << "There's something weird growing on this wall, maybe I should eat it? " << endl;
		cout << "Bad choice..." << endl;
		system("pause");
	}
	else                            //anything in this means the player is able to walk this direction
	{
		location = location - 1;	//moves player West one space
		able = true;				//passes check for if player is able to move
	}
}

void Location::WalkEast()	//checks location of player, then outputs correct data if player is trying to walk North
{
	if (location == 4)
	{
		cout << "Maybe if I had wings I could go up there." << endl;
		system("pause");
	}
	else if (location == 5 && notLost != 3)	//Checks if lost woods "lock" is broken
	{								//if "lock" is not broken
		notLost = 0;				//resets "lock"
		location = location + 1;	//moves player outside of lost woods
		able = true;				//passes check for if player is able to move
	}
	else if (location == 6)
	{
		cout << "Another stone wall to Castle Town eh, maybe I can walk through this " << endl;
		cout << "one... Nope." << endl;
		system("pause");
	}
	else if (location == 7)
	{
		cout << "I know the banquet hall is this way, but I don't think the King would " << endl;
		cout << "like me feasting before I'm finished my quest." << endl;
		system("pause");
	}
	else if (location == 9)
	{
		cout << "There is no possible way I could get over there, even if there was " << endl;
		cout << "somewhere to go when I did." << endl;
		system("pause");
	}
	else if (location == 11)
	{
		cout << "This wall is so big. I wonder why they have problems with monsters?" << endl;
		system("pause");
	}
	else if (location == 12)
	{
		cout << "Mamma told me never to talk to strangers." << endl;
		system("pause");
	}
	else if (location == 14)
	{
		cout << "Maybe if I'd focused on my STR stat I could have swam over to that " << endl;
		cout << "island... oh well." << endl;
		system("pause");
	}
	else if (location == 19)
	{
		cout << "If only I had a cannon..." << endl;
		system("pause");
	}
	else if (location == 21)
	{
		cout << "If I could climb this wall I could skip this whole swampy area... " << endl;
		cout << "to bad that's impossible." << endl;
		system("pause");
	}
	else if (location == 24)
	{
		cout << "Maybe I could just cuddle up to the dragon and we could be friends? " << endl;
		cout << "Or it'll eat me... either way." << endl;
		system("pause");
	}
	else                            //anything in this means the player is able to walk this direction
	{
		location = location + 1;	//moves player East one space
		able = true;				//passes check for if player is able to move
	}
}