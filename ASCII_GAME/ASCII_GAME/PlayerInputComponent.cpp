#include "PlayerInputComponent.h"


PlayerInputComponent::PlayerInputComponent()
{
}


PlayerInputComponent::~PlayerInputComponent()
{
}


_Direction PlayerInputComponent::getDirection()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return RIGHT;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		return DOWN;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		return UP;
	}
	else
	{
		return CENTER;
	}
}