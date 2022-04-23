#include "Door.h"

#include <iostream>
using namespace std;
void Door::use()
{
	




	if (m_locked) {
		cout << "door is locked";
	}
	else
		cout << "door is unlocked";


}

void Door::enter() {

	if (m_locked) {
		cout << "door is locked";
	}
	else
		cout << "door is unlocked";

}


void Door::unlock() {

	m_locked = false;
	cout << "door open";


}

void Door::lock() {
	m_locked = true;
	cout << "door close";
}
