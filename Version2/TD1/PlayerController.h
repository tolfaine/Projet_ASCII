#pragma once

#include "Controller.h"
#include "Hero.h"
#include <string>

class PlayerController : public Controller
{
public:
	PlayerController(Hero&);
	~PlayerController();

	virtual void inputs();

private:
	Hero mySpaceShip;
	//std::string name;
	//int score;
};

