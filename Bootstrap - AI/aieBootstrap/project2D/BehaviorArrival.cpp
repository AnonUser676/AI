#include "BehaviorArrival.h"
#include "Input.h"
#include "Vector2.h"
#include "Entity.h"
#include "defines.h"

using namespace aie;

BehaviorArrival::BehaviorArrival(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorArrival::~BehaviorArrival()
{}

Vector2 BehaviorArrival::update(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();

	Vector2 pos;
	Vector2 tarPos;
	
	tarPos.x = input->getMouseX();
	tarPos.y = input->getMouseY();
	pos = Agent->getPos();

	Vector2 desiredVelocity = tarPos - pos;
	float dist = pos.distance(tarPos);

	Vector2 Force;
	
	if (dist < 50.0f)
	{
		desiredVelocity = desiredVelocity.normalise() * MAX_VELOCITY * (dist / RADIUS_LIMIT);	
	}

	else
	{
		desiredVelocity = desiredVelocity.normalise() * MAX_VELOCITY;
	}

	Force = desiredVelocity - Agent->getVelocity();
	return Force;
}