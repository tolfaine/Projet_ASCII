#pragma once


#include <iostream>


#include "InputComponent.h"
#include "NYTimer.h"

#define FIRING_FREQUENCE 0.2


class PlayerInputComponent : public InputComponent
{


public:

	PlayerInputComponent();
	~PlayerInputComponent();


	virtual Direction getDirection();
	virtual bool isFiring();

private:

	NYTimer _timer;

	double _previous;
	double _current;

};

