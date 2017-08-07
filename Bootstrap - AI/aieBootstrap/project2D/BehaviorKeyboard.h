/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

BehaviorKeyboard - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "IBehavior.h"
#include "Entity.h"
#include "Input.h"

using namespace std;
using namespace aie;

/********************************************************************************************
Class BehaviorKeyboard inherits from class IBehavior
*********************************************************************************************/
class BehaviorKeyboard : public IBehavior
{
public:
	BehaviorKeyboard(float fWeighting);							    //Constructor used with fWeighting
	~BehaviorKeyboard();										    //Destructor

	Vector2 update(Entity* Agent, float deltaTime);				    //Update function with Entity and deltaTime parameter passed in returning a Vector2 value
};

