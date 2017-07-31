#pragma once
#include "IBehavior.h"
#include "Entity.h"

class BehaviorPursue : public IBehavior
{
public:
	BehaviorPursue(float fWeighting);
	~BehaviorPursue();

	Vector2 update(Entity* Agent, float deltaTime);
};

