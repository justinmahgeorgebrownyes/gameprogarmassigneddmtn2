#include "Furniture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void Furniture::loadFile(string fileName)
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
            temp++;
        }
    }

}