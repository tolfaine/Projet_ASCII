#pragma once


#include <array>
#include <Windows.h>
#include "Game.h"
class Game;

enum Direction { UP, DOWN, RIGHT, LEFT };

enum GameObjectType
{
	WALL,
	HERO,
	ENEMY
};

struct Coord
{
	double x;
	double y;
};

struct Pixel {
	CHAR_INFO c;
	int x;
	int y;
};

struct RectangleShape {
	//Coord leftTop;//if used this, need to update it when object moves
	int width;
	int height;
};

class GameObject
{

public:


	GameObject(Game* g);
	~GameObject();

	// called during inputs()
	void setDirection(Direction);
	void resetDirections();
	// called during logic()
	void update(long elapsedMs);
	//virtual bool collide(COORD);

	std::pair<COORD, std::vector<Pixel>> GameObject::getRenderInfo();

	//virtual void update(long ellapsedMs);
	//virtual void render();

	//virtual COORD checkMove(long ellapsedMS);
	//virtual void move(COORD);
	

	void takeDamage(const int d);
	inline const int getDamage() const { return damage; }
	void destroy();


	//bool operator==(Component* c) { return this == c; }

	GameObjectType getType() { return _type; }
	Coord& getCoord() { return coord; }

protected:
	Game* game;
	GameObjectType _type;

	bool invulnerability;
	int damage;
	int life;

	Coord coord;//leftTop of the sprite
	
	//Problem here !!!
	//CHAR_INFO sprite[spriteX][spriteY];
	int directions[2];

	double speed;
	RectangleShape hitbox;
	
	std::vector<Pixel> sprite;


};

