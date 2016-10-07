#pragma once

#include <vector>

#include "GameObject.h"
#include "Structures.h"

class GameObject;

class InputEngine
{


public:


	InputEngine();
	~InputEngine();


	void handleInputs(std::vector<GameObject*>&);


private:


};

