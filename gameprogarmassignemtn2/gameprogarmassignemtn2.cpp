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
#include "Desk.h"
#include "ButtonPanel.h"
#include "Dresser.h"
#include "Desk.h"
#include "FilingCabinet.h"
#include "Bathrobes.h"
#include "Door.h"
#include "StickyNote.h"
#include "Player.h"
#include "Lamp.h"
#include "Couch.h"
#include "FrontDesk.h"

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
    Item* currentItem = nullptr;


    Player hiP();
    DynamicStack<Item*> hieP;
    //figure out how to use when access door 
    //door check inventory or else fail2


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

    Desk* pDesk = new Desk();
    pDesk->loadFile("Desk.furniture");
    furnitureContainer.push_back((Furniture*)pDesk);
    furnitureMap[pDesk->getName()] = (Furniture*)pDesk;
    //to keep doing this for the other furnitures   
    
    
    ButtonPanel* pButtonPanel = new ButtonPanel();
    pButtonPanel->loadFile("ButtonPanel.furniture");
    furnitureContainer.push_back((Furniture*)pButtonPanel);
    furnitureMap[pButtonPanel->getName()] = (Furniture*)pButtonPanel;
    //to keep doing this for the other furnitures
    
    
    Dresser* pDresser = new Dresser();
    pDresser->loadFile("Dresser.furniture");
    furnitureContainer.push_back((Furniture*)pDresser);
    furnitureMap[pDresser->getName()] = (Furniture*)pDresser;
    //to keep doing this for the other furnitures    
    
    FilingCabinet* pFilingCabinet = new FilingCabinet();
    pFilingCabinet->loadFile("FilingCabinet.furniture");
    furnitureContainer.push_back((Furniture*)pFilingCabinet);
    furnitureMap[pFilingCabinet->getName()] = (Furniture*)pFilingCabinet;
    //to keep doing this for the other furnitures  
    
    
    Bathrobes* pBathrobes = new Bathrobes();
    pBathrobes->loadFile("Bathrobes.furniture");
    furnitureContainer.push_back((Furniture*)pBathrobes);
    furnitureMap[pBathrobes->getName()] = (Furniture*)pBathrobes;
    //to keep doing this for the other furnitures
        
    
    Door* pDoor = new Door();
    pDoor->loadFile("Door.furniture");
    furnitureContainer.push_back((Furniture*)pDoor);
    furnitureMap[pDoor->getName()] = (Furniture*)pDoor;
    //to keep doing this for the other furnitures


    Couch* pCouch = new Couch();
    pCouch->loadFile("Couch.furniture");
    furnitureContainer.push_back((Furniture*)pCouch);
    furnitureMap[pCouch->getName()] = (Furniture*)pCouch;
    //to keep doing this for the other furnitures



    Lamp* pLamp = new Lamp();
    pLamp->loadFile("Lamp.furniture");
    furnitureContainer.push_back((Furniture*)pLamp);
    furnitureMap[pLamp->getName()] = (Furniture*)pLamp;
    //to keep doing this for the other furnitures


   

    FrontDesk* pFrontDesk = new FrontDesk();
    pFrontDesk->loadFile("FrontDesk.furniture");
    furnitureContainer.push_back((Furniture*)pFrontDesk);
    furnitureMap[pFrontDesk->getName()] = (Furniture*)pFrontDesk;
    //to keep doing this for the other furnitures





    MasterKey* pMasterKey = new MasterKey();
    pMasterKey->loadFile("MasterKey.item");
    itemsContainer.push_back((Item*)pMasterKey);
    itemMap[pMasterKey->getName()] = (Item*)pMasterKey;
    //to keep doing this for the other items

    StickyNote* pStickyNote = new StickyNote();
    pStickyNote->loadFile("StickyNote.item");
    itemsContainer.push_back((Item*)pStickyNote);
    itemMap[pStickyNote->getName()] = (Item*)pStickyNote;
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

   /* for (size_t i = 0; i < roomsContainer.size(); i++)
    {
        commandSystem.listCommands(roomsContainer[i]);
    }*/

    dialogueSystem.start();

    

    currentRoom = pLobby;
    currentRoom->enter();

    bool playerWin = false;

    bool playerLose = false;

    while (playerWin == false && playerLose == false)
    {
    


        cout << "curent room is " << currentRoom->getName() << endl;


        commandSystem.takeAndExecuteCommand(currentRoom, currentItem);


        if (currentItem != nullptr)
        {
         
            hieP.push(currentItem);

            cout << "curent item is " << currentItem->getName() << endl;
         
        }


        //check the handout and see if the player obeject should also contain currentRoom memeber and 
        //if so update the players current room with the one that is here
        
 //player object inventory which will be a stack of items* take currentItem and push onto the player object invetnroy
        //after push set currentItem to nullptr again



    }



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
