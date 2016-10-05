#include "Hero.h"
#include <iostream>
#include <vector>

using namespace std;

Hero::Hero()
{

	directions[0] = false;
	directions[1] = false;
	directions[2] = false;
	directions[3] = false; 

	coord.X = 0;
	coord.Y = 0;


	for (int i = 0; i < spriteX; i++)
	{
		for (int j = 0;j < spriteY; j++)
		{
			sprite[i][j].Char.UnicodeChar = '\0';
			sprite[i][j].Char.AsciiChar = '\0';
			sprite[i][j].Attributes = 0;

		}
	}

	sprite[0][0].Char.AsciiChar = '=';
	sprite[0][0].Attributes = 0x0A;
	sprite[0][1].Char.AsciiChar = '=';
	sprite[0][1].Attributes = 0x0A;
	sprite[0][2].Char.AsciiChar = '=';
	sprite[0][2].Attributes = 0x0A;

	sprite[1][0].Char.UnicodeChar = '|';
	sprite[1][0].Attributes = 0x0A;
	sprite[1][1].Char.AsciiChar = '|';
	sprite[1][1].Attributes = 0x0A;
	sprite[1][2].Char.AsciiChar = '|';
	sprite[1][2].Attributes = 0x0A;

	sprite[2][0].Char.AsciiChar = 92;
	sprite[2][0].Attributes = 0x0A;
	sprite[2][1].Char.AsciiChar = 'o';
	sprite[2][1].Attributes = 0x0A;
	sprite[2][2].Char.AsciiChar = 47;
	sprite[2][2].Attributes = 0x0A;

	sprite[3][0].Char.AsciiChar = '\0';
	sprite[3][0].Attributes = 0x0A;
	sprite[3][1].Char.AsciiChar = ')';
	sprite[3][1].Attributes = 0x0A;
	sprite[3][2].Char.AsciiChar = '\0';
	sprite[3][2].Attributes = 0x0A;

	sprite[4][0].Char.AsciiChar = '\0';
	sprite[4][0].Attributes = 0x0A;
	sprite[4][1].Char.AsciiChar = '>';
	sprite[4][1].Attributes = 0x0A;
	sprite[4][2].Char.AsciiChar = '\0';
	sprite[4][2].Attributes = 0x0A;

}


Hero::~Hero()
{
}


void Hero::setDirection(Direction dir, bool value)
{

	switch (dir)
	{
	case UP:
		directions[0] = value;
		break;
	case DOWN:
		directions[1] = value;
		break;
	case RIGHT:
		directions[2] = value;
		break;
	case LEFT:
		directions[3] = value;
		break;
	}
}

void Hero::update()
{
	updatePosition();
	checkCollision();

}


void Hero::updatePosition() {

	if (directions[0] && coord.Y> 0)
	{
		--coord.Y;
	}
	if (directions[1] && coord.Y+spriteY <SCREEN_HEIGHT)
	{
		++coord.Y;
	}
	if (directions[2] && coord.X + spriteX <SCREEN_WIDTH)
	{
		++coord.X;
	}
	if (directions[3] && coord.X >0)
	{
		--coord.X;
	}
	
}

void Hero::checkCollision()
{

}

void Hero::renderHero()
{ 

}
std::pair<COORD, CHAR_INFO*> Hero::getRenderInfo()
{


	return std::make_pair(coord,(CHAR_INFO*)&sprite);
}