#pragma once

#include <vector>
#include <iostream>
#include <Windows.h>



#include "Structures.h"
#include "Parametres.h"
#include "NYTimer.h"
#include "GameObject.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "UI.h"

class GameObject;
class PhysicsEngine;
class InputEngine;
class UI;

class Game
{

public:

	Game();
	~Game();

	// starts the game
	void run();
	void update(double);

	std::vector<GameObject*> getGameObjects() { return _gameObjects; }
	GameObject* getPlayer() { return player; }

	void takeCareOfDeadBodies();


	/*
	* THE FOLLOWING METHODS ARE USED IN THE GAME LOOP
	*/
	// renders the graphics
	void renderGraphics();

	// clears the graphics buffer, shall be put in graphicsengine at some point
	void clear();
	// draws a sprite in the graphics buffer at the coordinates indicated, shall be put in graphicsengine at some point
	void drawSprite(const SpriteData spriteToDraw);

	std::vector<Pixel>& populateSpriteHero(std::vector<Pixel>& spriteSheet);


private:
	

	std::vector<GameObject*> _gameObjects;


	PhysicsEngine* _physics;
	InputEngine* _inputs;
	UI* _gameUI;
	
	GameObject* player;

	/*
	* FOLLOWING MUST BE PUT IN GRAPHICSENGINE AT SOME POINT
	*/
	CHAR_INFO map[SCREEN_HEIGHT+10][SCREEN_WIDTH];
	
	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	
	NYTimer _timer;


};
