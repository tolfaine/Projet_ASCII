#pragma once


#include <vector>


#include "Component.h"
#include "GameObject.h"
#include "PhysicsComponent.h"


class PhysicsEngine : public Component
{
		
public:
	~PhysicsEngine();
	bool move(GameObject* o, long elaspedMS);

private:
	//std::vector<GameObject*> getGameObjectsAt(PhysicsComponent* physicsC);
};

