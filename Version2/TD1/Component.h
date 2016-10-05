#pragma once



#include "Game.h"

class Game;

enum ComponentType
{
	HERO,
	ENEMY,
	MISSILE,
	MISSILE_H,
	WALL
};


class Component
{

public:

	Component(Game* g) : game(g) {}
	Component(Game* g, ComponentType t) : game(g), type(t) {}
	~Component();

	const ComponentType getType() const { return type; }

	virtual void update() = 0;
	virtual void render() = 0;



protected:
	Game* game;
	ComponentType type;

};

