#pragma once
#include "Entity.h"
#include "Vector2.h"

class Entity;

class IBehavior
{
public:
	IBehavior(float fWeighting)
	{
		m_fWeighting = fWeighting;
	}

	virtual Vector2 update(Entity* Agent,float deltaTime) = 0;

	float m_fWeighting;
};