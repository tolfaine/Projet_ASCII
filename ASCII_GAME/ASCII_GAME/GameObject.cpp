#include "GameObject.h"


using namespace std;


GameObject::GameObject(
	Game* g,
	InputComponent* i,
	double x,
	double y,
	HitBox hitbox,
	int life,
	int damage,
	GameObjectFaction faction,
	GameObjectType type,
	double speed)
{
	_game = g;
	_input = i;
	setPosition(Coord{ x, y });
	_hitbox = hitbox;
	_life = life;
	_maxLife = life;
	_damage = damage;
	_faction = faction;
	_type = type;
	_speed = speed;
	_dead = false;
}



GameObject::~GameObject()
{
}


void GameObject::handleInputs()
{
	setDirection(_input->getDirection());
	fire(_input->isFiring());
}


void GameObject::fire(bool isFiring)
{
	//cout << "value" << isFiring << endl;
	if (isFiring)
	{
		_game->createGameObject(GameObjectData{ { _coord.x, _coord.y }, F_HERO, T_MISSILE });
	}

}



void GameObject::takeDamage(GameObject* obj)
{
	//cout << "TAKE THAT MOTHERFUCKER" << endl;
	if (obj->getFaction() != _faction)
	{
		_life -= obj->getDamage();
		if (_life <= 0)
		{
			_dead = true;
		}
	}

}


void GameObject::setPosition(Coord newCoord)
{
	_coord = newCoord;
	
	if (_coord.x > SCREEN_WIDTH || _coord.x < 0 || _coord.y > SCREEN_HEIGHT || _coord.y < 0)
	{
		_dead = true;
	}
	
	_sprite.coord.X = (SHORT)_coord.x;
	_sprite.coord.Y = (SHORT)_coord.y;

	
}


void GameObject::setSprite(vector<Pixel> pixels)
{
	_sprite.pixels = pixels;
}


void GameObject::setDirection(Direction direction)
{
	//resetDirection();
	_direction = direction;
		
}


void GameObject::resetDirection()
{
	_direction.x = 0;
	_direction.y = 0;
}



