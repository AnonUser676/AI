#include "BotUnit.h"


BotUnit::BotUnit()
{
	m_v2Pos.x = 0.0f;
	m_v2Pos.y = 0.0f;
	start = 0;
	setSpeed(50.0f);

	m_StateMachine = new StateMachineAI();
	m_Aggressive = new StateAggressive();
	

	m_StateMachine->RegisterState(STATE_AGGRESSIVE, m_Aggressive);
	

	m_StateMachine->PushState(STATE_AGGRESSIVE);
}


BotUnit::~BotUnit()
{
	delete m_StateMachine;
	delete m_Aggressive;
	
}

void BotUnit::onEnter()
{
}

void BotUnit::EnUpdate(float deltaTime, Entity* Agent)
{
	m_StateMachine->Update(deltaTime, Agent);
}


void BotUnit::onDraw(Renderer2D* renderer2D) 
{
	renderer2D->drawCircle(m_v2Pos.x - OFFSET, m_v2Pos.y - OFFSET, 20.0f);
}

void BotUnit::onExit() 
{}