#include "MasterKey.h"
#include "Door.h"
#include <iostream>
using namespace std;
void MasterKey::take()
{
	cout << "taking masterkey" << endl;
	
}
void MasterKey::use()
{
	cout << "using masterkey." << endl;
	cout << "congratulations you won!" << endl;
	exit(3);
}
