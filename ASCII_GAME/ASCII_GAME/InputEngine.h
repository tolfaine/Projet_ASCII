#pragma once

#include "Game.h"
#include "Structures.h"

class Game;

class InputEngine
{


public:


	InputEngine(Game* g);
	~InputEngine();


	void handleInputs();


private:

	Game* _game;
};

