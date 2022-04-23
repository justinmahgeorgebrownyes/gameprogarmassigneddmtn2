#pragma once
#include <string>
#include "Room.h"
#include "Item.h"
using namespace std;
class SomeCommands
{


public:
	vector<string> inputt{};
	string command;
	void takeAndExecuteCommand(Room* &currentRoom, Item* &currentItem);
	string getVerb(string line);
	string getNoun(string line);
	bool checkCommand(string linee, Room* &currentRoom, Item*& currentItem);
	void listCommands(Room* currentRoom);
};

