#pragma once


#include "Enemy.h"

class Missile : public Movable
{

public:

	Missile(Game* g) : Movable(g) {}
	~Missile();


	virtual void move();
	virtual void collide();

protected:


};

