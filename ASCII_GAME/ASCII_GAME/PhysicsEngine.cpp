
#include "PhysicsEngine.h"

using namespace std;

PhysicsEngine::PhysicsEngine()
{

}





PhysicsEngine::~PhysicsEngine()
{
}





void PhysicsEngine::update(vector<GameObject*>& gObjects)
{
	Coord oCoord;


	for (GameObject* current : gObjects)
	{
		if (current->isDead())
			continue;

		oCoord = current->getCoord();


		double modCoordX = current->getDirection().x * current->getSpeed(); // *elaspedMS;
		double modCoordY = current->getDirection().y * current->getSpeed() * 0.5;  //*elaspedMS;

		double newCoordX = oCoord.x + modCoordX;
		double newCoordY = oCoord.y + modCoordY;

		

		if (newCoordX>= MIN_WIDTH && newCoordX + current->getHitBox().width <= SCREEN_WIDTH) {
			oCoord.x += modCoordX;

		}
		if (newCoordY >= MIN_HEIGHT && newCoordY + current->getHitBox().height  <= SCREEN_HEIGHT) {
			oCoord.y += modCoordY;
		}

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
