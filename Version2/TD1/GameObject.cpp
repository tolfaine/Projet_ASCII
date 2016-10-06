#include "GameObject.h"


using namespace std;

GameObject::GameObject(Game* game)
{
	this->game = game;

	CHAR_INFO c;
	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;

	sprite.push_back(Pixel{c,0,0});
}

GameObject::~GameObject()
{

}

void GameObject::update(long ellapsedMs)
{
	// retourne la nouvelle position de l'objet
	//COORD newCoord = checkMove(ellapsedMs);

	// vérifie si l'objet peut se déplacer vers la nouvelle position
	// renvoie faux uniquement si on essaye de se déplacer vers un mur ou hors des limites de la map
	/*if (collide(newCoord))
	{
		move(newCoord);
	}*/	
}

/*
  Calcul la prochaine position de l'objet

bool GameObject::collide(COORD coord)
{

}
*/

std::pair<COORD, vector<Pixel>> GameObject::getRenderInfo()
{


	return std::make_pair(COORD{coord.x, coord.y}, sprite);//conversion to int
}

void GameObject::resetDirections()
{
	directions[0] = 0;
	directions[1] = 0;
}


void GameObject::setDirection(Direction dir)
{

	switch (dir)
	{
	case UP:
		directions[1] = -1;
		break;
	case DOWN:
		directions[1] = 1;
		break;
	case RIGHT:
		directions[0] = 1;
		break;
	case LEFT:
		directions[0] = -1;
		break;
	}
}

void GameObject::takeDamage(const int d)
{
	life -= d;
	if (life < 0)
	{
		destroy();
	}
}


void GameObject::destroy()
{
	//game->removeGameObjectAt(coord.X, coord.Y, this);
}
