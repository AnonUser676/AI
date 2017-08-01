#include "DecisionButtonPressed.h"



DecisionButtonPressed::DecisionButtonPressed()
{
}


DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::makeDecision(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_SPACE))
		toggle = true;

	else
		toggle = false;

	//if (toggle == true)
		//mDecisionKeyboard->makeDecision(Agent, deltaTime)
}