#pragma once


#include <vector>
#include <iostream>
#include <Windows.h>

#include "Parametres.h"
#include "NYTimer.h"
#include "Hero.h"
#include "GameObject.h"
#include "ComponentPool.h"


#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30
#define TIME_PER_FRAME 1000 / 10

//Used to create the array representative of the screen => used also as a collision matrix
struct MapPixel	{
	CHAR_INFO character;
	GameObject* reference;
};

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


	std::vector<GameObject*> getGameObjectAt(const int x, const int y);
	void setGameObjectAt(const int x, const int y, GameObject* c);
	void removeGameObjectAt(const int x, const int y, GameObject* c);


private:

	Hero* player;

	

	MapPixel mapScreen[SCREEN_HEIGHT][SCREEN_WIDTH];

	std::vector<GameObject*> collisionMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];
	std::vector<GameObject*> objects;

	//ComponentPool pool;


	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	NYTimer timer;

	int i = 0;


	//std::vector<Player> _players;

};
