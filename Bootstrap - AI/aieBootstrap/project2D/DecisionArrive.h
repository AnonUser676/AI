#pragma once
#include "DecisionTree.h"
#include "defines.h"
#include "BehaviorArrival.h"
#include "DynamicArray.h"
#include "IBehavior.h"

class DecisionTree;
class BehaviorArrive;

class DecisionArrive : public DecisionTree
{
public:
	DecisionArrive();
	~DecisionArrive();

	void makeDecision(Entity* Agent, float deltaTime);

protected:
	Vector2 Pos;
	DynamicArray<IBehavior*> m_BehaviorList;
};

