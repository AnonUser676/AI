#pragma once
#include "DecisionTree.h"
#include "defines.h"
#include "BehaviorWander.h"
#include "DynamicArray.h"
#include "IBehavior.h"

class DecisionTree;
class BehaviorWander;

class DecisionWander : public DecisionTree
{
public:
	DecisionWander();
	~DecisionWander();

	void makeDecision(Entity* Agent, float deltaTime);

protected:
	Vector2 Pos;
	DynamicArray<IBehavior*> m_BehaviorList;
};

