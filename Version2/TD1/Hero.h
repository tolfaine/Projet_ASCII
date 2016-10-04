#pragma once

#include <array>


enum Direction { UP, DOWN, RIGHT, LEFT };


class Hero
{
public:
	Hero();
	~Hero();

	void update();

	void move(Direction);

private:
	int x;
	int y;
	int speed;

	std::array<bool, 4> directions;




};

