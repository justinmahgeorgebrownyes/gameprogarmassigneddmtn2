#pragma once
#include "Entity.h"
#include "Item.h"
#include <vector>
#include "DynamicStack.h"
class Player :
    public Entity 
{

private:
    vector<Item*> m_inventory;
    //dynamicstack
    DynamicStack<Item*> &playerStack;
  





public:
    //return inventory
    //update inventory
    void pushInventory(Item* item);


 /*   void popInventory() {
        return playerStack.pop();
    }*/

    //Player(string name, string description, string detailed_description, vector<Room*> rooms, vector<Furniture*> furniture, vector<Item*> items, string content_description)
    //    : Entity(name, description, "red"), m_detailedDescription(detailed_description), m_connectedRooms(rooms), m_furniture(furniture), m_items(items), m_contentDescription(content_description)
    //{

    //}








};

