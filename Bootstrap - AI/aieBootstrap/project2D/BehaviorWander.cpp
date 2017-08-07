#include "BehaviorWander.h"
#include "Input.h"
#include "Vector2.h"
#include "Entity.h"
#include "defines.h"

using namespace aie;

BehaviorWander::BehaviorWander(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorWander::~BehaviorWander()
{}

Vector2 BehaviorWander::update(Entity* Agent, float deltaTime)
{
	Vector2 tarPos;
	tarPos += Vector2(RandomClamped() * m_WanderJitter, RandomClamped() * m_WanderJitter);

	tarPos.normalise();

	tarPos *= m_WanderRadius;

	Vector2 velocity = Agent->getVelocity();

	velocity.normalise();

	Vector2 Force = tarPos + velocity * m_WanderDistance;

	return Force;
}

int BehaviorWander::RandomClamped()
{
	int decider = rand() % 10 + 1;
	
	if (decider % 2 == 0)
		return 1;
	else
		return -1;
}