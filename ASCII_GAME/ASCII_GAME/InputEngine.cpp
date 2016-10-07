#include "InputEngine.h"


using namespace std;



InputEngine::InputEngine()
{

}


InputEngine::~InputEngine()
{
}


void InputEngine::handleInputs(vector<GameObject*>& gObjects)
{
	for (GameObject* gObject : gObjects)
	{
		gObject->handleInputs();
	}
}
