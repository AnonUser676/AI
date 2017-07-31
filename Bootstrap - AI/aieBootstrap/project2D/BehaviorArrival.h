#pragma once
#include "IBehavior.h"
#include "Entity.h"

class BehaviorArrival : public IBehavior
{
public:
	BehaviorArrival(float fWeighting);
	~BehaviorArrival();

	Vector2 update(Entity* Agent, float deltaTime);
};

