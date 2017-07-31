#include "Entity.h"



Entity::Entity()
{
	m_pParent = nullptr;
}


Entity::~Entity()
{
}


void Entity::setSpeed(int inSpeed)
{
	speed = inSpeed;
}

void Entity::setHealth(int inHealth)
{
	health = inHealth;
}

int Entity::getSpeed() 
{
	return speed;
}

int Entity::getHealth()
{
	return health;
}

void Entity::setPos(Vector2 Pos)
{
	m_v2Pos = Pos;
}

Vector2 Entity::getPos()
{
	return m_v2Pos;
}

Vector2 Entity::getPosition()
{
	Vector2 pos;
	pos.x = GlobalTransform.matrix[2][0];
	pos.y = GlobalTransform.matrix[2][1];
	return pos;
}

void Entity::updateGlobalTransform()
{
	if (m_pParent != nullptr)
	{
		GlobalTransform = m_pParent->GlobalTransform * LocalTransform;
	}
	else
	{
		GlobalTransform = LocalTransform;
	}
	for (int i = 0; i < m_childList.Size(); i++)
	{
		m_childList[i]->updateGlobalTransform();
	}
}