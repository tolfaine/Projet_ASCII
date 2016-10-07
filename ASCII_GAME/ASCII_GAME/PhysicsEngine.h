#pragma once

#include <vector>
#include <iostream>

#include "Structures.h"
#include "GameObject.h"
#include "Parametres.h"

class GameObject;

class PhysicsEngine
{

public:

	
	PhysicsEngine();
	~PhysicsEngine();

	void update(std::vector<GameObject*>&);

	bool intersect(HitBox hit1, Coord coord1, HitBox hit2, Coord coord2);

private:
	

};

