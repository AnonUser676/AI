#include "BehaviorKeyboard.h"
#include "defines.h"


BehaviorKeyboard::BehaviorKeyboard(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorKeyboard::~BehaviorKeyboard()
{}

Vector2 BehaviorKeyboard::update(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();

	Vector2 pos = Agent->getPos();
	Vector2 tarPos;
	Vector2 Force;

	tarPos = pos;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		tarPos.x = pos.x - MOVE_VALUE;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		tarPos.x = pos.x + MOVE_VALUE;

	if (input->isKeyDown(INPUT_KEY_UP))
		tarPos.y = pos.y + MOVE_VALUE;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		tarPos.y = pos.y - MOVE_VALUE;


	Vector2 desiredVelocity = tarPos - pos;

	desiredVelocity = desiredVelocity.normalise() * MAX_VELOCITY;
	Force = desiredVelocity - Agent->getVelocity();

	return Force;

}