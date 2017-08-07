#include "DecisionToggled.h"
#include "DecisionButtonPressed.h"
#include "DecisionKeyboard.h"
#include "DecisionWander.h"
#include "DecisionArrive.h"


DecisionToggled::DecisionToggled()
{
	m_Root = new DecisionButtonPressed();
	m_Root->mDecisionKeyboard = new DecisionKeyboard();
	m_Root->mDecisionWander = new DecisionWander();
	m_Root->mDecisionArrive = new DecisionArrive();
}


DecisionToggled::~DecisionToggled()
{
	
	delete m_Root->mDecisionKeyboard;
	delete m_Root->mDecisionWander;
	delete m_Root->mDecisionArrive;
	delete m_Root;
}

void DecisionToggled::makeDecision(Entity* Agent, float deltaTime)
{
	m_Root->makeDecision(Agent, deltaTime);
}
