/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

BehaviorFlee - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "IBehavior.h"
#include "Entity.h"
#include "Input.h"

using namespace std;
using namespace aie;

/********************************************************************************************
Class BehaviorArrival inherits from class IBehavior
*********************************************************************************************/
class BehaviorFlee : public IBehavior
{
public:
	BehaviorFlee(float fWeighting);							   //Constructor used with fWeighting
	~BehaviorFlee();										   //Destructor

	Vector2 update(Entity* Agent, float deltaTime);			   //Update function with Entity and deltaTime parameter passed in returning a Vector2 value
};

