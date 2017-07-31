#pragma once
#include "StateMachine.h"
#include "Renderer2D.h"
#include "GridNode.h"
#include "defines.h"
#include "AStar.h"
#include "Matrix3.h"
#include "Entity.h"
#include "StateAggressive.h"
#include "StateMachineAI.h"

using namespace aie;
using namespace std;

class StateAggressive;
class StatemachineAI;

class BotUnit : public Entity
{
public:
	BotUnit();
	virtual ~BotUnit();
		
	virtual void onEnter();
	virtual void EnUpdate(float deltaTime,Entity* Agent);
	virtual void onDraw(Renderer2D* renderer2D);
	virtual void onExit();

private:
	
	Renderer2D* m_Renderer;
	StateMachineAI* m_StateMachine;
	StateAggressive* m_Aggressive;
	
	int start;
};

