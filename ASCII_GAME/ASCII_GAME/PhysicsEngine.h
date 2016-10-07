#pragma once

#include <vector>
#include <iostream>

#include "Structures.h"
#include "Game.h"
#include "GameObject.h"
#include "Parametres.h"

class Game;

class PhysicsEngine
{

public:

	
	PhysicsEngine(Game* g);
	~PhysicsEngine();

	void update(long elapsedMs);

	bool intersect(HitBox hit1, Coord coord1, HitBox hit2, Coord coord2);

private:
	Game* _game;



};

