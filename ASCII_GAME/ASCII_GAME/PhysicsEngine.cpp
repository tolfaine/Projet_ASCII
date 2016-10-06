
#include "PhysicsEngine.h"

using namespace std;

PhysicsEngine::PhysicsEngine(Game* g) : _game(g)
{

}





PhysicsEngine::~PhysicsEngine()
{
}





void PhysicsEngine::update(long elaspedMS)
{
	std::vector<GameObject*> gObjects = _game->getGameObjects();
	Coord oCoord;


	for (GameObject* current : gObjects)
	{
		if (current->isDead())
			continue;

		oCoord = current->getCoord();
		oCoord.x += current->getDirection().x * current->getSpeed() * elaspedMS;
		oCoord.y += current->getDirection().y * current->getSpeed() * elaspedMS;

		current->setPosition(oCoord);

		for (GameObject* other : gObjects)
		{
			if (current != other
				&& !other->isDead()
				&& intersect(current->getHitBox(),current->getCoord(),other->getHitBox(),other->getCoord()))
			{
				current->takeDamage(other);
				other->takeDamage(current);
			}
		}
	}

}

bool PhysicsEngine::intersect(HitBox hit1, Coord coord1, HitBox hit2, Coord coord2)
{
	if ( coord1.x < coord2.x + hit2.width
		&& coord2.x < coord1.x + hit1.width
		&& coord1.y < coord2.y + hit2.height
		&& coord2.y < coord1.y + hit1.height)
	{
		return true;
	}
	return false;
}
