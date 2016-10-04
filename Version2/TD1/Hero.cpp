#include "Hero.h"


Hero::Hero()
{

}


Hero::~Hero()
{
}


void Hero::move(Direction dir)
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