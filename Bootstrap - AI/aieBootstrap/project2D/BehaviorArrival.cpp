#include "BehaviorArrival.h"
#include "Input.h"
#include "Vector2.h"
#include "Entity.h"

using namespace aie;

BehaviorArrival::BehaviorArrival(float fWeighting) : IBehavior(fWeighting)
{}


BehaviorArrival::~BehaviorArrival()
{}

Vector2 BehaviorArrival::update(Entity* Agent, float deltaTime)
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