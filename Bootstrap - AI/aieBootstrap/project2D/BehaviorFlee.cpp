#include "BehaviorFlee.h"

using namespace aie;

BehaviorFlee::BehaviorFlee(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorFlee::~BehaviorFlee()
{}

Vector2 BehaviorFlee::update(Entity* Agent, float deltaTime)
{
	Input* input = Input::getInstance();

	Vector2 pos;
	Vector2 tarPos;
	tarPos.x = input->getMouseX();
	tarPos.y = input->getMouseY();
	pos = Agent->getPos();

	Vector2 Force = (pos - tarPos) * Agent->getSpeed();
	Force.normalise();

	return Force;
}