#pragma once


#include <vector>
#include <iostream>
#include <Windows.h>
#include "NYTimer.h"
#include "Hero.h"


#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define TIME_PER_FRAME 1000 / 120


class Game
{
public:
	Game();
	~Game();


	void run();
	void pause();
	void stop();
	void resume();

	void inputs();
	void update();
	void render();
	void clear();

private:

	Hero* player;




	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO** buffer;

	NYTimer timer;
	//std::vector<Player> _players;

};

