#include "Hero.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

Hero::Hero()
{

	directions[0] = false;
	directions[1] = false;
	directions[2] = false;
	directions[3] = false; 

	coord.X = 0;
	coord.Y = 0;

	sprite[0][0].Char.AsciiChar = '=';
	sprite[0][0].Attributes = 0x0A;
	sprite[1][0].Char.AsciiChar = ' ';
	sprite[1][0].Attributes = 0x0A;
	sprite[2][0].Char.AsciiChar = '=';
	sprite[1][0].Attributes = 0x0A;

	sprite[0][1].Char.AsciiChar = '|';
	sprite[0][1].Attributes = 0x0A;
	sprite[1][1].Char.AsciiChar = '|';
	sprite[1][1].Attributes = 0x0A;
	sprite[2][1].Char.AsciiChar = '|';
	sprite[2][1].Attributes = 0x0A;

	sprite[0][2].Char.UnicodeChar = 92;
	sprite[0][2].Attributes = 0x0A;
	sprite[1][2].Char.AsciiChar = 'o';
	sprite[1][2].Attributes = 0x0A;
	sprite[2][2].Char.UnicodeChar = 47;
	sprite[2][2].Attributes = 0x0A;

	sprite[0][3].Char.AsciiChar = ' ';
	sprite[0][3].Attributes = 0x0A;
	sprite[1][3].Char.AsciiChar = ')';
	sprite[1][3].Attributes = 0x0A;
	sprite[2][3].Char.AsciiChar = ' ';
	sprite[2][3].Attributes = 0x0A;
}


Hero::~Hero()
{
}


void Hero::setDirection(Direction dir)
{
	switch (dir)
	{
	case UP:
		directions[0] = true;
	case DOWN:
		directions[1] = true;
	case RIGHT:
		directions[2] = true;
	case LEFT:
		directions[3] = true;
	}
}

void Hero::update()
{
	updatePosition();
	checkCollision();

}


void Hero::updatePosition() {

	if (directions[0])
	{
		--coord.X;
	}
	if (directions[1])
	{
		++coord.X;
	}
	if (directions[2])
	{
		++coord.Y;
	}
	if (directions[3])
	{
		--coord.Y;
	}
}

void Hero::checkCollision()
{

}

void Hero::renderHero()
{ 

}
