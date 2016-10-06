#pragma once


#include "InputComponent.h"


class PlayerInputComponent : public InputComponent
{


public:

	PlayerInputComponent();
	~PlayerInputComponent();


	virtual _Direction getDirection();





};

