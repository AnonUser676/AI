#pragma once
#include "Decision.h"
#include "Entity.h"

class DecisionTree : public Decision
{
public:
	virtual void makeDecision(Entity* Agent, float deltaTime) = 0;

	Decision* mDecisionKeyboard;
	Decision* mDecisionWander;

};