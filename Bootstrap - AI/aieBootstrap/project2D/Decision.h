#pragma once
#include "Entity.h"

class Decision
{
	virtual void makeDecision(Entity* Agent, float deltaTime) = 0;
};