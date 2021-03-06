#pragma once
#include "DecisionTree.h"
#include "defines.h"
#include "BehaviorKeyboard.h"
#include "DynamicArray.h"
#include "IBehavior.h"

class DecisionTree;

class DecisionKeyboard : public DecisionTree
{
public:
	DecisionKeyboard();
	~DecisionKeyboard();

	void makeDecision(Entity* Agent, float deltaTime);

protected:
	Vector2 Pos;
	DynamicArray<IBehavior*> m_BehaviorList;
};

