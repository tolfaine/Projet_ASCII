#pragma once

#include <vector>
#include <iostream>
#include <Windows.h>

#include "Parametres.h"
#include "NYTimer.h"
#include "Hero.h"
#include "GameObject.h"
#include "ComponentPool.h"


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

	std::vector<GameObject*> getGameObjectAt(const int x, const int y);
	void setGameObjectAt(const int x, const int y, GameObject* c);
	void removeGameObjectAt(const int x, const int y, GameObject* c);


private:

	Hero* player;


	std::vector<GameObject*> collisionMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];
	std::vector<GameObject*> objects;

	//ComponentPool pool;


	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	NYTimer timer;
	//std::vector<Player> _players;

};

