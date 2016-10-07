#pragma once


#include <vector>
#include <Windows.h>


class Structures
{
public:
	Structures();
	~Structures();
};


enum GameObjectFaction
{
	F_WALL,
	F_HERO,
	F_ENEMY,
};

enum GameObjectType
{
	T_WALL,
	T_PLAYER,
	T_ENEMY,
	T_MISSILE
};


struct Coord
{
	double x;
	double y;
};

struct Direction
{
	int x;
	int y;
};

enum _Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CENTER
};

struct HitBox
{
	double width;
	double height;
};

struct GameObjectData
{
	Coord coord;
	GameObjectFaction faction;
	GameObjectType type;
};





struct Pixel {
	CHAR_INFO c;
	int x;
	int y;
};

struct SpriteData
{
	COORD coord;
	std::vector<Pixel> pixels;
};



