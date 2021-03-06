#include "DecisionKeyboard.h"



DecisionKeyboard::DecisionKeyboard()
{
	m_BehaviorList.pushBack(new BehaviorKeyboard(1.0f));
}


DecisionKeyboard::~DecisionKeyboard()
{
	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		delete m_BehaviorList[i];
	}
}

void DecisionKeyboard::makeDecision(Entity * Agent, float deltaTime)
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

	Agent->setVelocity(velocity);

	Agent->setPos(Agent->getPos() + velocity * 10 * deltaTime);

}
