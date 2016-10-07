#pragma once

#include <vector>
#include <iostream>


#include "Structures.h"
#include "Parametres.h"
#include "NYTimer.h"
#include "GameObject.h"
#include "PhysicsEngine.h"
#include "InputEngine.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "MissileInputComponent.h"
#include "UI.h"
#include "GraphicsEngine.h"


class GameObject;
class PhysicsEngine;
class GraphicsEngine;
class InputEngine;
class UI;




class Game
{

public:

	Game();
	~Game();

	// starts the game
	void run();
	void update();
	void inputs();
	void render();


	void createGameObject(GameObjectData);
	void addGameObjects();
	std::vector<GameObject*> getGameObjects() { return _gameObjects; }
	
	
	GameObject* getPlayer() { return player; }

	void takeCareOfDeadBodies();

	std::vector<Pixel>& populateSpriteHero(std::vector<Pixel>& spriteSheet);
	std::vector<Pixel>& populateSpriteMissile(std::vector<Pixel>& spriteSheet);
	std::vector<Pixel>& populateSpriteEnemy(std::vector<Pixel>& spriteSheet);

private:
	

	std::vector<GameObject*> _gameObjects;
	std::vector<GameObjectData> _gameObjectsData;


	GraphicsEngine* _graphics;
	PhysicsEngine* _physics;
	InputEngine* _inputs;
	UI* _gameUI;
	
	GameObject* player;

	
	NYTimer _timer;


};
