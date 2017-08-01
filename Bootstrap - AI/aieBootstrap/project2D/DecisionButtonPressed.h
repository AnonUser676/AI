#pragma once
#include "DecisionTree.h"
#include "Input.h"

class DecisionButtonPressed : public DecisionTree
{
public:
	DecisionButtonPressed();
	~DecisionButtonPressed();

	void makeDecision(Entity* Agent, float deltaTime);

protected:
	bool toggle;
};

