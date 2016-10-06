#pragma once

#include <array>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "GameObject.h"

class Hero : public GameObject
{
public:
	Hero(Game* game, Coord position, double speed) : GameObject(game) {}
	~Hero();
	//void updatePosition();
	//void checkCollision();
	
	// called during render
	//void renderHero();
private:

	//COORD coord;
	//int speed;
	//CHAR_INFO sprite[spriteX][spriteY];
	//CHAR_INFO sprite[spriteX][spriteY];
	//int directions[2];

};


