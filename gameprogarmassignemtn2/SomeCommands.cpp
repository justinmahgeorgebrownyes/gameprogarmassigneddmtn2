#include "SomeCommands.h"
#include "Room.h"


#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector> 
#include <sstream>
#include <string>
#include <windows.h>
#include "Player.h"
#include "DynamicStack.h"
#include <stdlib.h>
#include "Door.h"


void SomeCommands::takeAndExecuteCommand(Room* &currentRoom, Item* &currentItem)
{
	cout << endl;
	cout << "list of available commands" << endl;
	listCommands(currentRoom);

	

	cout << "command please" << endl;
	std::getline(std::cin, command);
	//cin >> command;

	//string space_delimiter = " ";
	//

	//size_t pos = 0;
	//while ((pos = command.find(space_delimiter)) != string::npos) {
	//	inputt.push_back(command.substr(0, pos));
	//	command.erase(0, pos + space_delimiter.length());
	//}


	bool commandValid = checkCommand(command, currentRoom, currentItem);

	if (!commandValid)
	{
		cout << "invalid command" << endl;
		return ;
	}


	return ;
}

string SomeCommands::getVerb(string line)
{
	auto first_token = line.substr(0, line.find(' '));
	return string(first_token);


}

string SomeCommands::getNoun(string line)
{
	int pos = line.find(" ");
	string sub = line.substr(pos + 1);

string second_token = sub;
	return sub;


}



bool SomeCommands::checkCommand(string linee, Room* &currentRoom, Item* &currentItem)
{
	

	//std::for_each(linee.begin(), linee.end(), [](char& c) {
	//	c = ::tolower(c);
	//	});

	string verbz = getVerb(command);
	string nounz = getNoun(linee);
	Door hid;

	

	for (size_t i = 0; i < currentRoom->getconnectedRooms().size(); i++)
	{
		vector <Room*> hiRoom = currentRoom->getconnectedRooms();

		if (nounz == hiRoom[i]->getName()) {

			for (size_t j = 0; j < hiRoom[i]->getVerbs().size(); j++)
			{

				if (verbz == hiRoom[i]->getVerbs()[j])
				{
					cout << "good" << endl;

					//
					if (verbz == "Enter")
					{
						hiRoom[i]->enter();
						currentRoom = hiRoom[i];

					}
					if (verbz == "Examine")
					{
						hiRoom[i]->examine();
						

					}

					return true;
				}


			}


		}

	



	}

	vector <Furniture*> hiFurniture = currentRoom->getContainedFurniture();

	
	for (size_t i = 0; i < currentRoom->getContainedFurniture().size(); i++)
	{
		

		if (nounz == hiFurniture[i]->getName()) {

			for (size_t j = 0; j < hiFurniture[i]->getVerbs().size(); j++)
			{

				if (verbz == hiFurniture[i]->getVerbs()[j])
				{
					cout << "good" << endl;

					//support all other verbs for aother possible furnitures
					//makes sure all the fuctions exist for all the verbs that do support
					//add support for all of the items
					if (verbz == "Smash")
					{
						hiFurniture[i]->smash();
					}
					if (verbz == "Open")
					{
						hiFurniture[i]->open();
					}
					if (verbz == "Close")
					{
						hiFurniture[i]->close();
					}	
					if (verbz == "Search")
					{
						hiFurniture[i]->search();
					}
					if (verbz == "Examine")
					{
						hiFurniture[i]->examine();
					}
				
				}


			}
		}
	}


	for (size_t i = 0; i < currentRoom->getContainedItem().size(); i++)
	{
		vector <Item*> hiItem = currentRoom->getContainedItem();

		if (nounz == hiItem[i]->getName()) {

			for (size_t j = 0; j < hiItem[i]->getVerbs().size(); j++)
			{

				if (verbz == hiItem[i]->getVerbs()[j])
				{
					cout << "good" << endl;

					//support all other verbs for aother possible furnitures
					//makes sure all the fuctions exist for all the verbs that do support
					//add support for all of the items
					if (verbz == "Take")
					{
						hiItem[i]->take();
						currentItem = hiItem[i];
						
					}	
					
					if (verbz == "Use")
					{
					//	hiItem[i]->use();
						currentItem->use();
						currentItem = nullptr;
						
			
					}
			

					return true;
				}


			}
		}
	}



	//also chekc furniture and items. 
	return false;

}


	//if (linee == "" && )
	//{

	//}

//	"Enter elevator"



void SomeCommands::listCommands(Room* currentRoom) {

	

	vector <Room*> connectedRooms= currentRoom->getconnectedRooms();
		
	for (int i = 0; i < connectedRooms.size(); i++)
	{
		string konnectedName = connectedRooms[i]->getName(); 
		vector<string> konnectedRoomVerbss = connectedRooms[i]->getVerbs();

		HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int j = 0; j < konnectedRoomVerbss.size(); j++)
		{
			SetConsoleTextAttribute(hstdout, 0x09);

			cout << konnectedRoomVerbss[j] << " ";

			SetConsoleTextAttribute(hstdout, 0x04);


			cout << konnectedName << endl;
			

		}
		
		SetConsoleTextAttribute(hstdout, 0x0F);


	}

	vector <Furniture*> containedFurniture = currentRoom->getContainedFurniture();
	for (int i = 0; i < containedFurniture.size(); i++)
	{
		string kontainedFurnitureName = containedFurniture[i]->getName();
		vector<string> kontainedFurnitureVerb = containedFurniture[i]->getVerbs();

		HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int j = 0; j < kontainedFurnitureVerb.size(); j++)
		{
			SetConsoleTextAttribute(hstdout, 0x09);

			cout << kontainedFurnitureVerb[j] << " ";

			SetConsoleTextAttribute(hstdout, 0x06);

			cout << kontainedFurnitureName << endl;
			

		}
	
		SetConsoleTextAttribute(hstdout, 0x0F);
			
		/*	<< system("Color 0A") << system("Color 0F")*/
		
		//std::cout << "Press any key to quit.\n";

	}


	vector <Item*> containedItem = currentRoom->getContainedItem();
	for (int i = 0; i < containedItem.size(); i++)
	{
		string kontainedItemName = containedItem[i]->getName();
		vector<string> kontainedItemVerb = containedItem[i]->getVerbs();


		HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int j = 0; j < kontainedItemVerb.size(); j++)
		{
			SetConsoleTextAttribute(hstdout, 0x09);


			cout << kontainedItemVerb[j] << " ";

			SetConsoleTextAttribute(hstdout, 0x0A);

			cout << kontainedItemName << endl;
			

			

		}

		SetConsoleTextAttribute(hstdout, 0x0F);


	}


	/*• 
		• Push button
		• Exit elevator
		• Open door
		• Talk tot lceaninrg person
		• Move desk
		• Search desk
		• Search bed
		• Open drawer
		• Enter closet
		• Take hammer
		• Shake iron board
		• Smash closet
		• Smash chair
		• Smash bed
		• Smash tv
		• Smash toilet
		• Smash desk*/


}




