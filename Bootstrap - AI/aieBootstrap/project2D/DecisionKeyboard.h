#pragma once
#include "DecisionTree.h"

class DecisionKeyboard : public DecisionTree
{
public:
	DecisionKeyboard();
	~DecisionKeyboard();

	void makeDecision(Entity* Agent, float deltaTime);
};

