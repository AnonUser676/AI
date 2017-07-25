#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
#include "Stack.h"

using namespace aie;
using namespace std;

class BaseState;

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();

	void Update(float fDetaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void Draw2ndFromTop(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void RegisterState(int nStateIndex, BaseState* pState);
	void PopState();
	bool bDrawLowerState;

	
protected:
	Renderer2D* m_renderer;
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_Stack;
};

