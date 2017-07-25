#pragma once
#include "Texture.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "DynamicArray.h"

using namespace aie;
using namespace std;

class Entity
{
public:
	Entity();
	~Entity();

	Entity* m_pParent;
	DynamicArray<Entity*> m_childList;

	void setSpeed(int inSpeed);
	void setHealth(int inHealth);
	int getSpeed();
	int getHealth();

	Matrix3 LocalTransform;
	Matrix3 GlobalTransform;
	Vector2 getPosition();

	void updateGlobalTransform();

protected:
	int speed;
	int health;
};

