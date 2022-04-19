#include "Room.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void Room::loadFile(string fileName)
{
    fstream inFile;

    // Open the file for readding
    inFile.open(fileName, ios::in);
    if (!inFile)
    {
        cout << "Cannot open file " << fileName;
        return;
    }  

    if (inFile.is_open()) {   //checking whether the file is open
        string tp;
        int temp = 0;
        while (getline(inFile, tp)) {  //read data from file object and put it into string.
           // cout << tp << "\n";

            if (temp == 0) {
                m_name = tp;
            }

            if (temp == 1) {
                m_description = tp;
            }

            if (temp == 2) {

                m_verb = tp;


                std::istringstream ss(m_verb);
                std::string token;

                while (std::getline(ss, token, ',')) {
                    m_verbssString.push_back(token);
                }

            }

            if (temp == 3)
            {
                m_connectingRoom = tp;

                std::istringstream ss(m_connectingRoom);
                std::string token;

                while (std::getline(ss, token, ',')) {
                    m_connectingRoomString.push_back(token);
                }

            }
            if (temp == 4) {
                m_containedFurniture = tp;


                std::istringstream ss(m_containedFurniture);
                std::string token;

                while (std::getline(ss, token, ',')) {
                    m_containedFurnituredSTrig.push_back(token);
                }
            }

            if (temp == 5)
            {
                m_containedItemName = tp;


                std::istringstream ss(m_containedItemName);
                std::string token;

                while (std::getline(ss, token, ',')) {
                    m_containedItemNameSTring.push_back(token);
                }
            }

            //print the data of the string



            temp++;
        }
    }
}

void Room::fillConnectingRooms(map<string, Room*>&roomMap)
{
    for (int i = 0; i < m_connectingRoomString.size(); i++)
    {
        
        m_connectedRooms.push_back(roomMap[m_connectingRoomString[i]]);

        
    }


}
