#pragma once
#include "Entity.h"

class Decision
{
public:
	virtual void makeDecision(Entity* Agent, float deltaTime) = 0;
};