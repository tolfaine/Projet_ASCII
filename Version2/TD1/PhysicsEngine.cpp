
#include "PhysicsEngine.h"




PhysicsEngine::~PhysicsEngine()
{
}

void update() {
	//collistionMatrix <= c'est le tableau d'affichage
}

bool PhysicsEngine::move(GameObject* o, long elaspedMS)
{
	Coord newCoord;
	Coord oCoord = o->getCoord();
	PhysicsComponent* oPhysics = o->getPhysicsComponent();
	newCoord.x = oCoord.x + oPhysics->_speedX * elaspedMS;
	newCoord.y = oCoord.y + oPhysics->_speedY * elaspedMS;

	//Caster en int nouvelles coordonnées
	//Check dans collision matrix
	//Recup les trucs touchés
	collisionMatrix->getByRect(position, oPhysics);

	listWall = listTouched->findByType("WALL");


	//Peut etre fait directement par l'objet ?
	if (listWall.size() > 0) {
		reajustPosition(listWall, newCoord);
	}

	oCoord = newCoord;

	for (GameObject* touched : listTouched) {
		if (type != wall) {
			o.collide(touched);
			touched.collide(o);
		}
	}

	//Dire au game de le rajouter dans la liste de purge si mort
	//Purge avant render



	//vector<GameObject*> listWall = game->listComponent->findByType("WALL");

	//if () {
	//	o->setCoord(newCoord);
	//}


}
