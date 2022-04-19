#pragma once
#include <string>
using namespace std;
class SomeCommands
{


public:
	string getVerb(string line);
	string getNoun(string line);
	void checkCommand(string linee, Room* currentRoom);
};

