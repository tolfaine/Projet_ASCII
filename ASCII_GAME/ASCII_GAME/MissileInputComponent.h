#pragma once


#include "Structures.h"
#include "InputComponent.h"

class MissileInputComponent : public InputComponent
{


public:

	MissileInputComponent();
	~MissileInputComponent();

	virtual Direction getDirection();
	virtual bool isFiring();

protected:


};

