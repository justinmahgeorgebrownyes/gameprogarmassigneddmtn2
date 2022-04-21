// gameprogarmassignemtn2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <string>
#include <iostream>
#include "Room.h"
#include "Elevator.h"
#include "Lobby.h"
#include <map>
#include "GuestingRoom.h"
#include "HallWay.h"
#include "Closet.h"
#include "SomeDialogue.h"
#include "SomeCommands.h"
#include "Safe.h"
#include "MasterKey.h"
using namespace std;
int main()
{
    vector<Room*> roomsContainer;
    vector<Item*> itemsContainer;
    vector<Furniture*> furnitureContainer;

    map <string, Room*> roomMap;
    map <string, Item*> itemMap;
    map <string, Furniture*> furnitureMap;

    
    Room* currentRoom ;


    Elevator *pElevator = new Elevator();
    pElevator->loadFile("Elevator.room");
    roomsContainer.push_back((Room*)pElevator);
    roomMap[pElevator->getName()] = (Room*)pElevator;

    Lobby *pLobby= new Lobby();
    pLobby->loadFile("Lobby.room");
    roomsContainer.push_back((Room*)pLobby);
    roomMap[pLobby->getName()] = (Room*)pLobby;


    HallWay* pHallWay = new HallWay();
    pHallWay->loadFile("HallWay.room");
    roomsContainer.push_back((Room*)pHallWay);
    roomMap[pHallWay->getName()] = (Room*)pHallWay;


    GuestingRoom* pGuestingRoom = new GuestingRoom();
    pGuestingRoom->loadFile("GuestingRoom.room");
    roomsContainer.push_back((Room*)pGuestingRoom);
    roomMap[pGuestingRoom->getName()] = (Room*)pGuestingRoom;


    Closet* pCloset = new Closet();
    pCloset->loadFile("Closet.room");
    roomsContainer.push_back((Room*)pCloset);
    roomMap[pCloset->getName()] = (Room*)pCloset;

    for (size_t i = 0; i < roomsContainer.size(); i++)
    {
        roomsContainer[i]->fillConnectingRooms(roomMap);
        
    }

    Safe* pSafe = new Safe();
    pSafe ->loadFile("Safe.furniture");
    furnitureContainer.push_back((Furniture*)pSafe);
    furnitureMap[pSafe->getName()] = (Furniture*)pSafe;
    //to keep doing this for the other furnitures



    MasterKey* pMasterKey = new MasterKey();
    pMasterKey->loadFile("MasterKey.item");
    itemsContainer.push_back((Item*)pMasterKey);
    itemMap[pMasterKey->getName()] = (Item*)pMasterKey;
    //to keep doing this for the other items


    //craete all furniture objectsusing .furniture files
    //make sure to create furniture map
    for (size_t i = 0; i < roomsContainer.size(); i++)
    {
        //
   // implement fillcontain furniture in room class
        roomsContainer[i]->fillContainedFurniture(furnitureMap);
        
    } 

    //craete all item objectsusing .item files
//make sure to create item map
    for (size_t i = 0; i < roomsContainer.size(); i++)
    {

   // implement fillcontain items in room class
        roomsContainer[i]->fillContainedItems(itemMap);
        
    }


    SomeCommands commandSystem;
    SomeDialogue dialogueSystem;

    for (size_t i = 0; i < roomsContainer.size(); i++)
    {
        commandSystem.listCommands(roomsContainer[i]);
    }


    


    currentRoom = pLobby;
    currentRoom->enter();

    bool playerWin = false;

    bool playerLose = false;

    while (playerWin == false && playerLose == false)
    {
        commandSystem.takeAndExecuteCommand(currentRoom);
    }


    //Item hammer ;


    std::cout << "Hello World!\n";
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
