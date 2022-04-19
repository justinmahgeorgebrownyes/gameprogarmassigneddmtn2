#include "Door.h"

#include <iostream>
using namespace std;
void Door::use()
{





	if (m_locked) {
		cout << "locked";
	}
	else
		cout << "unlocked";


}



void Door::unlock() {

	m_locked = false;



}

void Door::lock() {
	m_locked = true;
}
