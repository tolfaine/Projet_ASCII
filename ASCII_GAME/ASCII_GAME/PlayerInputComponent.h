#pragma once


#include "InputComponent.h"


class PlayerInputComponent : public InputComponent
{


public:

	PlayerInputComponent();
	~PlayerInputComponent();


	virtual Direction getDirection();
	virtual bool isFiring();




};

