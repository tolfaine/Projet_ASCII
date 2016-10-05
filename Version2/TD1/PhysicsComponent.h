#pragma once


#include "Component.h"

class PhysicsComponent : public Component
{

public:

	~PhysicsComponent();

	double _l;
	double _h;
	double _speedX;
	double _speedY;
};

