#include "Movable.h"

Movable::~Movable()
{

}

void Movable::update(long ellapsedMs)
{
	move();
}

void Movable::render()
{
	//sprite + position
}

