#include "DecisionButtonPressed.h"

using namespace std;

DecisionButtonPressed::DecisionButtonPressed()
{
	toggle = 0;
}


DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::makeDecision(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();
	
	if (input->wasKeyPressed(INPUT_KEY_SPACE) && toggle == 0)
		toggle = 1;
	
	else if (input->wasKeyPressed(INPUT_KEY_SPACE) && toggle == 1)
		toggle = 2;

	else if (input->wasKeyPressed(INPUT_KEY_SPACE) && toggle == 2)
		toggle = 0;


	if (toggle == 0)
		mDecisionKeyboard->makeDecision(Agent, deltaTime);

	else if (toggle == 1)
		mDecisionWander->makeDecision(Agent, deltaTime);

	else
		mDecisionArrive->makeDecision(Agent, deltaTime);
}