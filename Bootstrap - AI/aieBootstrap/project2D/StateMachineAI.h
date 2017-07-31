#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "Entity.h"
#include "Stack.h"
#include "BaseStateAI.h"

using namespace aie;
using namespace std;

class Entity;
class BaseStateAI;

class StateMachineAI
{
public:
	StateMachineAI();
	virtual ~StateMachineAI();

	void Update(float fDetaTime, Entity* Agent);
	void Draw(Renderer2D* m_2dRenderer);
	void Draw2ndFromTop(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void RegisterState(int nStateIndex, BaseStateAI* pState);
	void PopState();
	bool bDrawLowerState;

	
protected:
	Renderer2D* m_renderer;
	DynamicArray<BaseStateAI*> m_StateList;
	Stack<BaseStateAI*> m_Stack;
};

