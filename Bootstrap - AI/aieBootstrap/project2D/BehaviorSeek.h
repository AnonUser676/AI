/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

BehaviorSeek - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "IBehavior.h"
#include "Entity.h"
#include "Input.h"

using namespace std;
using namespace aie;

/********************************************************************************************
Class BehaviorSeek inherits from class IBehavior
*********************************************************************************************/
class BehaviorSeek : public IBehavior
{
public:
	BehaviorSeek(float fWeighting);								 //Constructor used with fWeighting
	~BehaviorSeek();											 //Destructor

	Vector2 update(Entity* Agent, float deltaTime);				 //Update function with Entity and deltaTime parameter passed in returning a Vector2 value
};

