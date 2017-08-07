/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

BehaviorWander - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "IBehavior.h"
#include "Entity.h"

/********************************************************************************************
Class BehaviorWander inherits from class IBehavior
*********************************************************************************************/
class BehaviorWander : public IBehavior
{
public:
	BehaviorWander(float fWeighting);								   //Constructor used with fWeighting
	~BehaviorWander();												   //Destructor

	Vector2 update(Entity* Agent, float deltaTime);					   //Update function with Entity and deltaTime parameter passed in returning a Vector2 value
	int RandomClamped();											   //Function that retrieves a random integer to be used for update

};