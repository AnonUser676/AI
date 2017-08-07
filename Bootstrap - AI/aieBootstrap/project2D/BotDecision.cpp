#include "BotDecision.h"



BotDecision::BotDecision()
{
	m_v2Pos.x = 550.0f;
	m_v2Pos.y = 550.0f;
	
	setSpeed(50.0f);
	Vector2 initialVelocity(0.0f, 0.0f);
	setVelocity(initialVelocity);
	m_Decision = new DecisionToggled();
}


BotDecision::~BotDecision()
{
	delete m_Decision;
}

void BotDecision::BotDraw(Renderer2D * m_Renderer)
{
	m_Renderer->setRenderColour(0x28F21BFF);
	m_Renderer->drawBox(m_v2Pos.x - OFFSET, m_v2Pos.y - OFFSET, 25.0f, 25.0f);
	m_Renderer->setRenderColour(0xFFFFFFFF);
}

void BotDecision::Update(float deltaTime)
{
	m_Decision->makeDecision(this, deltaTime);
}
