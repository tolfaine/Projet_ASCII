#pragma once

#include <array>
#include <Windows.h>
#include <iostream>
#include <vector>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30


enum Direction { UP=0, DOWN=1, RIGHT=2, LEFT=3 };

class Hero
{
public:
	Hero();
	~Hero();
	static const int spriteX = 5;
	static const int spriteY = 3;

	// called during inputs()
	void setDirection(Direction, bool);

	// called during logic()
	void update();
	void updatePosition();
	void checkCollision();
	
	// called during render
	void renderHero();
	std::pair<COORD,CHAR_INFO*> getRenderInfo();

private:

	COORD coord;
	int speed;
	//CHAR_INFO sprite[spriteX][spriteY];

	CHAR_INFO sprite[spriteX][spriteY];


	std::array<bool, 4> directions;

};


