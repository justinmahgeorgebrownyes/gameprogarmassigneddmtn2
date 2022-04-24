#pragma once
#include "Room.h"
class Elevator :
    public Room
{

public: 


    Elevator() {

    }

    //Elevator(string name, string description, string detailed_description, vector<string> rooms, vector<string> entities, string content_description)
    //    : Room(name, description, detailed_description, rooms, entities, content_description)
    //{

    //}

  
    void examine();

};

