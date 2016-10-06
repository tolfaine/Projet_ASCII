#pragma once

#include <vector>
#include "GameObject.h"

class PhysicsEngine
{
public:
	PhysicsEngine();
	PhysicsEngine(Game* game);
	~PhysicsEngine();
	
	bool move(GameObject* o, long elaspedMS);

	void update(long elapsedMs);
private:
	Game* game;
	//std::vector<GameObject*> getGameObjectsAt(PhysicsComponent* physicsC);
};

