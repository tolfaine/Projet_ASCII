#pragma once


#include <array>
#include <Windows.h>

#include "Component.h"

class Game;

class Movable : public Component
{

public:

	Movable(Game* g) : Component(g) {}
	~Movable();

	virtual void update(long ellapsedMs);
	virtual void render();

	virtual void move();
	virtual void collide();



protected:

		//sprite
	int speed;
	//direction

};

