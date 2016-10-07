#include "MissileInputComponent.h"


MissileInputComponent::MissileInputComponent()
{

}


MissileInputComponent::~MissileInputComponent()
{
}


Direction MissileInputComponent::getDirection()
{
	Direction dir;
	dir.x = 1;
	dir.y = 0;
	return dir;
}


bool MissileInputComponent::isFiring()
{
	return false;
}