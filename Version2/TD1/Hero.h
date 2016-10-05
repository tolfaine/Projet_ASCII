#pragma once

#include <array>
#include <Windows.h>
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

enum Direction { UP, DOWN, RIGHT, LEFT };

class Hero
{
public:
	Hero();
	~Hero();

	// called during inputs()
	void setDirection(Direction);

	// called during logic()
	void update();
	void updatePosition();
	void checkCollision();
	
	// called during render
	void renderHero();


private:

	COORD coord;
	int speed;
	CHAR_INFO sprite[7][4];
	std::array<bool, 4> directions;

};

