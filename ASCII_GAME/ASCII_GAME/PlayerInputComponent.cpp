#include "PlayerInputComponent.h"


using namespace std;


PlayerInputComponent::PlayerInputComponent()
{
	_timer.start();

	_previous = _timer.getElapsedSeconds();
	_current = _timer.getElapsedSeconds();
}


PlayerInputComponent::~PlayerInputComponent()
{
}


Direction PlayerInputComponent::getDirection()
{
	Direction dir;
	dir.x = 0;
	dir.y = 0;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		dir.x += -1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		dir.x += 1;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		dir.y += -1;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		dir.y+= 1;
	}
	return dir;
}


bool PlayerInputComponent::isFiring()
{

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		_current = _timer.getElapsedSeconds();
		//cout << _current - _previous << endl;
		if (_current - _previous > FIRING_FREQUENCE)
		{
			_previous = _current;
			return true;
		}
	}
	return false;
}