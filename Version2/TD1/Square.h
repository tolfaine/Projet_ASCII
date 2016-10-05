#pragma once



enum SquareType
{
	WALL,
	WALL_LEFT,
	WALL_RIGHT,
	EMPTY,
	ENEMY,
};


class Square
{

public:

	Square();
	~Square();

	inline void setType(SquareType t) { type = t; };

private:

	SquareType type;
};

