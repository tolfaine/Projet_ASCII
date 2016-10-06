#include "InputEngine.h"


InputEngine::InputEngine(Game* g) : _game(g)
{

}


InputEngine::~InputEngine()
{
}


void InputEngine::handleInputs()
{
	for (GameObject* gObject : _game->getGameObjects())
	{
		gObject->handleInputs();
	}
}
