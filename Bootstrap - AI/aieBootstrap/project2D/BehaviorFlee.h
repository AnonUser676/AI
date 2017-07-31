#pragma once
#include "IBehavior.h"
#include "Entity.h"
#include "Input.h"

using namespace std;
using namespace aie;

class BehaviorFlee : public IBehavior
{
public:
	BehaviorFlee(float fWeighting);
	~BehaviorFlee();

	Vector2 update(Entity* Agent, float deltaTime);
};

