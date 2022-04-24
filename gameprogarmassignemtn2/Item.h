#pragma once
#include "Entity.h"
class Item :
    public Entity
{


private:
  //  vector<Item*> m_items;
    char ch;
    


public: 

    void loadFile(string fileName);

    Item() {

    }


    //Item(string name, string description)
    //    : Entity(name, description, "green")
    //{


    //    inFile.open(name, ios::in);
    //    outFile.open(name, ios::out);

    //    ch = inFile.peek();
    //    while (ch != EOF)
    //    {
    //        // Examine current character
    //            ch = inFile.get();
    //            outFile << ch;
    //        }
    //        // Peek at the next character from input file
    //        ch = inFile.peek();
    //    }
    //    // Close the files
    //    inFile.close();
    //    outFile.close();
    //    return 0;
    //}




};

