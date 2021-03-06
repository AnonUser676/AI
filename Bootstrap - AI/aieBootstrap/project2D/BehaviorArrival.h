/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

BehaviorArrival - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "IBehavior.h"
#include "Entity.h"

/********************************************************************************************
Class BehaviorArrival inherits from class IBehavior
*********************************************************************************************/
class BehaviorArrival : public IBehavior
{
public:
	BehaviorArrival(float fWeighting);							//Constructor used with fWeighting
	~BehaviorArrival();											//Destructor

	Vector2 update(Entity* Agent, float deltaTime);				//Update function with Entity and deltaTime parameter passed in returning a Vector2 value
};

