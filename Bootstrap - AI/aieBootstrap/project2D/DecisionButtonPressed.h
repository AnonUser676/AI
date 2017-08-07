#pragma once
#include "DecisionTree.h"
#include "Input.h"
#include "Decision.h"

class DecisionTree;
class Decision;

class DecisionButtonPressed : public DecisionTree
{
public:
	DecisionButtonPressed();
	~DecisionButtonPressed();

	void makeDecision(Entity* Agent, float deltaTime);

protected:
	int toggle;
};

