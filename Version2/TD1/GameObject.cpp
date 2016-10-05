#include "GameObject.h"

GameObject::~GameObject()
{

}

void GameObject::update(long ellapsedMs)
{
	// retourne la nouvelle position de l'objet
	COORD newCoord = checkMove(ellapsedMs);

	// vérifie si l'objet peut se déplacer vers la nouvelle position
	// renvoie faux uniquement si on essaye de se déplacer vers un mur ou hors des limites de la map
	if (collide(newCoord))
	{
		move(newCoord);
	}
	
}


/*
  Calcul la prochaine position de l'objet
*/
COORD GameObject::checkMove(long ellapsedMS)
{

}

void GameObject::move(COORD coord)
{

}

bool GameObject::collide(COORD coord)
{

}







void GameObject::render()
{
	//sprite + position
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
	game->removeGameObjectAt(coord.X, coord.Y, this);
}
