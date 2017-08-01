#pragma once
#include "DecisionTree.h"
#include "Entity.h"

class DecisionToggled : public DecisionTree
{
public:
	DecisionToggled();
	~DecisionToggled();

	void Update(Entity* Agent, float deltaTime);

private:
	DecisionTree*	m_Root;
};

