#include "PlayerController.h"


PlayerController::PlayerController(Hero& mySpaceShip)
{
	this->mySpaceShip = mySpaceShip;
}


PlayerController::~PlayerController()
{

}

void PlayerController::inputs()
{
	mySpaceShip.resetDirections();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mySpaceShip.setDirection(LEFT);
		//	cout << "LEFT" << endl;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mySpaceShip.setDirection(RIGHT);
		//	cout << "RIGHT" << endl;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mySpaceShip.setDirection(UP);
		//cout << "UP" << endl;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mySpaceShip.setDirection(DOWN);
		//	cout << "DOWN" << endl;
	}

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		cout << "SHOT DAT MORTHAFUCKA" << endl;
	}
}