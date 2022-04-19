#pragma once
#include <string>
#include "Room.h"
using namespace std;
class SomeCommands
{


public:
	string getVerb(string line);
	string getNoun(string line);
	void checkCommand(string linee, Room* currentRoom);
	void listCommands(Room* currentRoom);
};

