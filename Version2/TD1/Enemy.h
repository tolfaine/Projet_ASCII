#pragma once

#include "Movable.h"

class Enemy : public Movable
{

public:

	Enemy(Game* g) : Movable(g) {}
	~Enemy();


	virtual void move();
	virtual void collide();


private:



};

