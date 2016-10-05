#pragma once


#include <vector>
#include <iostream>
#include <Windows.h>
#include "NYTimer.h"
#include "Hero.h"


#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30
#define TIME_PER_FRAME 1000 / 10


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
	void renderPlayer();	
	void clear();


private:

	Hero* player;

	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	NYTimer timer;

	int i = 0;


	//std::vector<Player> _players;

};
