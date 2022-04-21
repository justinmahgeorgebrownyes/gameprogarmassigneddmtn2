#pragma once
#include <string>
#include "Room.h"
#include "Item.h"
using namespace std;
class SomeCommands
{


public:
	Item* takeAndExecuteCommand(Room* currentRoom);
	string getVerb(string line);
	string getNoun(string line);
	bool checkCommand(string linee, Room* currentRoom);
	void listCommands(Room* currentRoom);
};

