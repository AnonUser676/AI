#pragma once
#include "Texture.h"
#include "Vector2.h"
#include "Matrix3.h"
#include "DynamicArray.h"
#include "Renderer2d.h"
#include "StateMachineAI.h"

using namespace aie;
using namespace std;

class StateMachineAI;

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
	Vector2 getPos();
	void setPos(Vector2 Pos);

	virtual void onEnter() = 0;
	virtual void EnUpdate(float deltaTIme, Entity* Agent) = 0;
	virtual void onDraw(Renderer2D* renderer2D) = 0;
	virtual void onExit() = 0;

	Matrix3 LocalTransform;
	Matrix3 GlobalTransform;
	Vector2 getPosition();

	void updateGlobalTransform();

protected:
	int speed;
	int health;
	Vector2 m_v2Pos;
};

