#pragma once
#include "DecisionTree.h"

class DecisionWander : public DecisionTree
{
public:
	DecisionWander();
	~DecisionWander();

	void makeDecision(Entity* Agent, float deltaTime);
};

