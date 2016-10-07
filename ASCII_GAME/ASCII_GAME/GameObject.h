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


	GameObject(Game* g,
		InputComponent* i,
		double x,
		double y,
		HitBox hitbox,
		int life,
		int damage,
		GameObjectFaction faction,
		GameObjectType type,
		double speed);

	~GameObject();


	void handleInputs();

	void takeDamage(GameObject*);

	void fire(bool);

	InputComponent* getInputComponent() { return _input; }

	const Direction getDirection() const { return _direction; }  
	double getSpeed() { return _speed; }
	SpriteData& getRenderInfo() { return _sprite; }
	Coord getCoord() { return _coord; }
	HitBox getHitBox() { return _hitbox; }
	int getDamage() { return _damage; }

	int getLife() { return _life; }

	int getMaxLife() { return _maxLife; }

	GameObjectFaction getFaction() { return _faction; }
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
	int _maxLife;
	int _damage;

	GameObjectFaction _faction;
	GameObjectType _type;
	HitBox _hitbox;

	InputComponent* _input;

	bool _isFiring;

	bool _dead;

	// position reelle de l'object
	Coord _coord;
	// sprite pour le dessin de l'objet
	SpriteData _sprite;
};
