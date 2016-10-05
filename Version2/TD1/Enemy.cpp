#include "Enemy.h"




Enemy::~Enemy()
{
}


void Enemy::collide()
{
	Component* otherComponent = game->getComponentAt(coord.X,coord.Y);

	if (otherComponent != nullptr)
	{
		if (otherComponent->getType() == MISSILE_H || otherComponent->getType() == HERO)
		{
			otherComponent->takeDamage(damage);
			takeDamage(otherComponent->getDamage());
		}
	}
}