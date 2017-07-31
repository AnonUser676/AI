#pragma once
#include "Renderer2D.h"
#include "StateMachine.h"
#include "Entity.h"
#include "IBehavior.h"
#include "DynamicArray.h"

using namespace aie;
using namespace std;

enum STATE
{
	STATE_AGGRESSIVE,
	STATE_PASSIVE,
	STATE_COUNTER
};

class Entity;
class IBehavior;

class BaseStateAI
{
public:
	BaseStateAI() {}
	virtual ~BaseStateAI() {}

	virtual void onEnter() = 0;
	virtual void EnUpdate(float deltaTIme, Entity* State) = 0;
	virtual void onDraw(Renderer2D* renderer2D) = 0;
	virtual void onExit() = 0;

protected:
	DynamicArray<IBehavior*> m_BehaviorList;
};