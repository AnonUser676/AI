#include "DecisionArrive.h"



DecisionArrive::DecisionArrive()
{
	m_BehaviorList.pushBack(new BehaviorArrival(1.0f));
}


DecisionArrive::~DecisionArrive()
{
	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		delete m_BehaviorList[i];
	}
}

void DecisionArrive::makeDecision(Entity * Agent, float deltaTime)
{
	Vector2 ForceMax;

	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		Vector2 ForceCurrent = m_BehaviorList[i]->update(Agent, deltaTime);
		ForceCurrent = ForceCurrent * m_BehaviorList[i]->m_fWeighting;
		ForceMax = ForceMax + ForceCurrent;

		float ForceMagnitude = ForceMax.magnitude();
		if (ForceMagnitude > TRUNCATE)
		{
			ForceMax.normalise();
			ForceMax = ForceMax * TRUNCATE;
			break;
		}
	}

	Vector2 velocity = Agent->getVelocity();

	velocity = velocity + ForceMax;

	float VelocityMagnitude = velocity.magnitude();
	if (VelocityMagnitude > TRUNCATE)
	{
		velocity.normalise();
		velocity = velocity * TRUNCATE;
	}

	Agent->setVelocity(velocity);

	Agent->setPos(Agent->getPos() + velocity * 10 * deltaTime);
}
