#pragma once


#include "Structures.h"

class InputComponent
{


public:

	InputComponent();
	~InputComponent();

	virtual Direction getDirection();
	virtual bool isFiring();

protected:


};

