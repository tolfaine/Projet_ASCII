#pragma once

#include <vector>
#include <iostream>
#include <Windows.h>

#include "Parametres.h"
#include "NYTimer.h"
#include "Hero.h"
#include "GameObject.h"
#include "Controller.h"
#include "PlayerController.h"
#include "PhysicsEngine.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30
#define TIME_PER_FRAME 1000 / 10

//Used to create the array representative of the screen => used also as a collision matrix
struct MapPixel	{
	CHAR_INFO* character;
	std::vector<GameObject*> reference;
};

class Game
{
public:
	Game();
	~Game();

	void init();
	void run();
	void pause();
	void stop();
	void resume();

	void inputs();
	void update(long elapsedMs);
	void render();
	void Game::draw(const std::pair<COORD, std::vector<Pixel>>& renderInfo);
	//void renderPlayer();	
	void clear();


	//std::vector<GameObject*> getGameObjectAt(const int x, const int y);
	//void setGameObjectAt(const int x, const int y, GameObject* c);
	//void removeGameObjectAt(const int x, const int y, GameObject* c);
private:
	//Hero* player;
	CHAR_INFO map[SCREEN_HEIGHT][SCREEN_WIDTH];
	//std::vector<GameObject*> reference[SCREEN_HEIGHT][SCREEN_WIDTH];

	//std::vector<GameObject*> collisionMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];
	//std::vector<GameObject*> objects;

	//ComponentPool pool;

	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	//CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	NYTimer timer;

	std::vector<GameObject> components;
	std::vector<Controller> controllers;
	PhysicsEngine pEngine;

	//int i = 0;
	//std::vector<Player> _players;

};
