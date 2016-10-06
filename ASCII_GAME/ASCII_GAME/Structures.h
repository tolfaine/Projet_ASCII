#pragma once


#include <Windows.h>
#include <vector>



class Structures
{
public:
	Structures();
	~Structures();
};


struct HitBox
{
	double width;
	double height;
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
