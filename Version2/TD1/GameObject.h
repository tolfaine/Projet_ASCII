#pragma once


#include <array>
#include <Windows.h>

#include "Component.h"
#include "PhysicsComponent.h"


class Game;


enum GameObjectType
{
	WALL,
	HERO,
	ENEMY,
	MISSILE,
	MISSILE_H
};

struct Coord
{
	double x;
	double y;
};

struct RectangleShape {
	Coord leftTop;//if used this, need to update it when object moves
	int width;
	int height;
};

class GameObject : public Component
{

public:

	GameObject(Game* g) : Component(g) {}
	~GameObject();

	virtual void update(long ellapsedMs);
	virtual void render();

	virtual COORD checkMove(long ellapsedMS);
	virtual void move(COORD);
	virtual bool collide(COORD);


	void takeDamage(const int d);
	inline const int getDamage() const { return damage; }
	void destroy();



	bool operator==(Component* c) { return this == c; }

	GameObjectType getType() { return _type; }
	Coord& getCoord() { return _coord; }
	PhysicsComponent* getPhysicsComponent() { return _physics; }

protected:
	GameObjectType _type;
	//Coord _coord;
	//PhysicsComponent* _physics;

	bool invulnerability;
	int damage;
	int life;

	double speed;
	std::vector<bool> direction;
	RectangleShape hitbox;
	COORD refCoord;//leftTop of the sprite
	std::vector<COORD> coords;
	//Sprite sprite

};

