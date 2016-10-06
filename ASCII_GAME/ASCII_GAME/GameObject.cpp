#include "GameObject.h"


using namespace std;


GameObject::GameObject(Game* g, InputComponent* i, double x, double y, int life, int damage, GameObjectType type) : _game(g), _input(i)
{
	this->setPosition(Coord{ x,y });

	_direction.x = 0;
	_direction.y = 0;

	_life = life;
	_damage = damage;

	_type = type;

	_hitbox.height = 5;
	_hitbox.width = 5;

	_speed = 2.0;

	_dead = false;

}


GameObject::~GameObject()
{
}


void GameObject::handleInputs()
{
	setDirection(_input->getDirection());
}

void GameObject::takeDamage(GameObject* obj)
{
	//cout << "TAKE THAT MOTHERFUCKER" << endl;
	if (obj->getType() == _type)
	{
		_life -= obj->getDamage();
		if (_life < 0)
		{
			_dead = true;
		}
	}

}


void GameObject::setPosition(Coord newCoord)
{
	_coord = newCoord;
	_sprite.coord.X = (SHORT)_coord.x;
	_sprite.coord.Y = (SHORT)_coord.y;
}


void GameObject::setSprite(vector<Pixel> pixels)
{
	_sprite.pixels = pixels;
}


void GameObject::setDirection(_Direction direction)
{
	resetDirection();
	switch (direction)
	{
	case UP:
		_direction.y = 1;
		break;
	case DOWN:
		_direction.y = -1;
		break;
	case LEFT:
		_direction.x = -1;
		break;
	case RIGHT:
		_direction.x = 1;
		break;
	case CENTER:
		break;
	}
		
}


void GameObject::resetDirection()
{
	_direction.x = 0;
	_direction.y = 0;
}



