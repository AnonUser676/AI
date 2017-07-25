#include "StateMachine.h"
#include <crtdbg.h>

StateMachine::StateMachine()
{
	bDrawLowerState = false;
}

StateMachine::~StateMachine()
{
	m_StateList.Clear();
}

void StateMachine::Update(float fDetaTime)
{
	_ASSERT(m_StateList.Size() > 0);
	if (m_StateList.Size() <= 0)
		return;

	_ASSERT(m_Stack.size() >= 0);
	if (m_Stack.size() < 0)
		return;

	m_Stack.top()->onUpdate(fDetaTime,this);
}

void StateMachine::Draw(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return;

	m_Stack.top()->onDraw(m_2dRenderer);

	if (bDrawLowerState)
		Draw2ndFromTop(m_2dRenderer);
}

void StateMachine::Draw2ndFromTop(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return;

	m_Stack.SecondLast()->onDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;
	if (m_Stack.size() > 0)
		m_Stack.top()->onExit();

	m_Stack.push(m_StateList[nStateIndex]);

	m_Stack.top()->onEnter();
}

void StateMachine::RegisterState(int nStateIndex, BaseState* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::PopState()
{
	if (m_Stack.size() > 0)
		m_Stack.top()->onExit();

	if (m_Stack.size() > 0)
		m_Stack.pop();
}