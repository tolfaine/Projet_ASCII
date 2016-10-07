#pragma once
#include "Game.h"
#include <sstream>
#include <string>

class Game;

class UI
{
public:
	UI(Game* g);
	~UI();

	void update();
	SpriteData& getRenderInfo() { return _sprite; }
	void clean();

protected:

	Game* _game;
	SpriteData _sprite;
};