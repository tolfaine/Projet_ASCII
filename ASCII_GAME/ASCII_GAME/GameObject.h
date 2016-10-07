#pragma once


#include <array>
#include <Windows.h>
#include <vector>

#include "Structures.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "Game.h"

class Game;

class GameObject
{

public:


	GameObject(Game* g, InputComponent* i, double x, double y, int life, int damage, GameObjectType type);
	~GameObject();


	void handleInputs();

	void takeDamage(GameObject*);


	InputComponent* getInputComponent() { return _input; }

	const Direction getDirection() const { return _direction; }  
	double getSpeed() { return _speed; }
	SpriteData& getRenderInfo() { return _sprite; }
	Coord getCoord() { return _coord; }
	HitBox getHitBox() { return _hitbox; }
	int getDamage() { return _damage; }

	int getLife() { return _life; }

	GameObjectType getType() { return _type; }

	bool isDead() { return _dead; }

	void setPosition(Coord newCoord);
	void setDirection(Direction);
	void setSprite(std::vector<Pixel> pixels);

	void resetDirection();

	

protected:
	
	Game* _game;

	Direction _direction;
	double _speed;
	int _life;
	int _damage;

	GameObjectType _type;

	HitBox _hitbox;

	InputComponent* _input;

	bool _dead;

	// position reelle de l'object
	Coord _coord;
	// sprite pour le dessin de l'objet
	SpriteData _sprite;
};
