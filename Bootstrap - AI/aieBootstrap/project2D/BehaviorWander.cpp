#include "BehaviorPursue.h"
#include "Input.h"
#include "Vector2.h"
#include "Entity.h"

using namespace aie;

BehaviorPursue::BehaviorPursue(float fWeighting) : IBehavior(fWeighting)
{

}


BehaviorPursue::~BehaviorPursue()
{
}

Vector2 BehaviorPursue::update(Entity* Agent, float deltaTime)
{
	Vector2 Force(0.0f, 0.0f);
	return Force;
}