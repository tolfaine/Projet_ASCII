
#include "PhysicsEngine.h"


//Give the game reference in the constructor
PhysicsEngine::PhysicsEngine(Game* game)
{
	this->game = game;
}

PhysicsEngine::~PhysicsEngine()
{
}

/*
std::vector<GameObject*> PhysicsEngine::getByRect(const RectangleShape& rect)
{
	std::vector<GameObject*> colliders;
	MapPixel pixel;
	for (int i = rect.leftTop.x; i < rect.leftTop.x + rect.width; i++) {
		for (int j = rect.leftTop.y; j < rect.leftTop.y + rect.height; j++) {
			if (i > -1 && i < SCREEN_WIDTH && j > -1 && j < SCREEN_HEIGHT) {
				pixel = mapPixel[x][y];
				if (pixel.reference != nullptr)//check if point out a black unique object ? (the background)
					colliders.push_back(pixel.reference);
			}
		}
	}
	return colliders;
}*/


void PhysicsEngine::update(long elaspedMS)
{
	std::vector<GameObject*> components = game->getComponents();
	Coord oCoord;


	for (GameObject* currentObj : components)
	{
		if (currentObj->isDead())
			continue;

		oCoord = currentObj->getCoord();//given by reference
		oCoord.x += currentObj->getDirection().x * currentObj->getSpeed() * elaspedMS;
		oCoord.y += currentObj->getDirection().y * currentObj->getSpeed() * elaspedMS;

		for (GameObject* currentObj2 : components)
		{
			if (currentObj != currentObj2 && !currentObj2->isDead() && currentObj->getRect().intersect(currentObj2->getRect()))
			{
				currentObj.collide(currentObj2);
				currentObj2.collide(currentObj);
			}
		}
	}

	/*
	Coord newCoord;
	Coord oCoord = o->getCoord();
	PhysicsComponent* oPhysics = o->getPhysicsComponent();
	newCoord.x = oCoord.x + oPhysics->_speedX * elaspedMS;
	newCoord.y = oCoord.y + oPhysics->_speedY * elaspedMS;

	//Caster en int nouvelles coordonnées
	//Check dans collision matrix
	//Recup les trucs touchés
	collisionMatrix->getByRect(o->hitbox);

	listWall = objsInHitbox->findByType("WALL");


	//Peut etre fait directement par l'objet ?
	if (listWall.size() > 0) {
		reajustPosition(listWall, newCoord);
	}

	oCoord = newCoord;

	for (GameObject* objInHitbox : objsInHitbox) {
		if (!objInHitbox->isDead()) {
			currentObj.collide(objInHitbox);
			objInHitbox.collide(currentObj);
		}
	}

	//Dire au game de le rajouter dans la liste de purge si mort
	//Purge avant render



	//vector<GameObject*> listWall = game->listComponent->findByType("WALL");

	//if () {
	//	o->setCoord(newCoord);
	//}

	*/
}
