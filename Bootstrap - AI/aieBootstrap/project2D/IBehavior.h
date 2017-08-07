/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

IBehavior - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include "Entity.h"
#include "Vector2.h"

class Entity;

/********************************************************************************************
Class IBehavior creating a Baseclass for all behavior files
*********************************************************************************************/
class IBehavior
{
public:
	IBehavior(float fWeighting)										   //IBehavior uses fWeighting for determining behavior
	{
		m_fWeighting = fWeighting;
	}
	virtual Vector2 update(Entity* Agent,float deltaTime) = 0;		   //Virtual update used as update template for all behavior classes

	float m_fWeighting;												   //float for behavior weighting
};