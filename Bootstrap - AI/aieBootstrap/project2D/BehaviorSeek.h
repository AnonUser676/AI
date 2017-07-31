#pragma once
#include "IBehavior.h"
#include "Entity.h"
#include "Input.h"

using namespace std;
using namespace aie;

class BehaviorSeek : public IBehavior
{
public:
	BehaviorSeek(float fWeighting);
	~BehaviorSeek();

	Vector2 update(Entity* Agent, float deltaTime);
};

