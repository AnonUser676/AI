#pragma once
#include "Renderer2D.h"
#include "BaseStateAI.h"
#include "StateMachine.h"
#include "IBehavior.h"
#include "LinkedList.h"
#include "Texture.h"
#include "GridNode.h"
#include "defines.h"
#include "AStar.h"
#include "DynamicArray.h"
#include "Entity.h"

using namespace std;
using namespace aie;

class StateAggressive : public BaseStateAI
{
public:

	StateAggressive();
	virtual ~StateAggressive();
	void onEnter();
	void onUpdate(float deltaTIme, StateMachine* State);
	void EnUpdate(float deltaTime, Entity* Agent);
	void onDraw(Renderer2D* renderer2D);
	void onExit();

	Texture* m_car;

	Vector2 Pos;
	unsigned int nxtNode;
	int start;
	int end;

	float time;

};

