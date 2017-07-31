#include "BehaviorSeek.h"

using namespace aie;

BehaviorSeek::BehaviorSeek(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorSeek::~BehaviorSeek()
{}

Vector2 BehaviorSeek::update(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();

	Vector2 pos;
	Vector2 tarPos;
	tarPos.x = input->getMouseX();
	tarPos.y = input->getMouseY();
	pos = Agent->getPos();

	Vector2 Force = (tarPos - pos) * Agent->getSpeed();
	Force.normalise();

	return Force;
}