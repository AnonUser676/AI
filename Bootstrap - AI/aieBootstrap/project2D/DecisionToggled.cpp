#include "DecisionToggled.h"
#include "DecisionButtonPressed.h"
#include "DecisionKeyboard.h"
#include "DecisionWander.h"


DecisionToggled::DecisionToggled()
{
	m_Root = new DecisionButtonPressed();
	//m_Root->mDecisionKeyboard = new DecisionKeyboard();
	//m_Root->mDecisionWander = new DecisionWander();
}


DecisionToggled::~DecisionToggled()
{
	delete m_Root;
	//delete m_Root->mDecisionKeyboard;
	//delete m_Root->mDecisionWander;
}

void DecisionToggled::Update(Entity* Agent, float deltaTime)
{
	m_Root->makeDecision(Agent, deltaTime);
}
