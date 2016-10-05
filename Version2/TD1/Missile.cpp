#include "Missile.h"



Missile::~Missile()
{
}


void Missile::collide()
{
	Component* otherComponent = game->getComponentAt(coord.X, coord.Y);

	if (otherComponent != nullptr)
	{
		if (getType() == MISSILE_H)
		{
			if (otherComponent->getType() == ENEMY)
			{
				otherComponent->takeDamage(damage);
				takeDamage(otherComponent->getDamage());
			}
		}
		else if (getType() == MISSILE)
		{
			if (otherComponent->getType() == HERO)
			{
				otherComponent->takeDamage(damage);
				takeDamage(otherComponent->getDamage());
			}
		}
	}
}