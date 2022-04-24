#pragma once
#include "Item.h"
#include "Player.h"
class MasterKey :
    public Item
{

private:
 

public:

    MasterKey(){
    
    
    
    }

    /*MasterKey(string name, string description, bool inventory)
        : Item(name, description, inventory)
    {

    }*/


    //void use(Door* i );


 /*   void examine() {

        if (Door.) {
            cout << "locked"
    }*/





    void take();

    void use();

};

