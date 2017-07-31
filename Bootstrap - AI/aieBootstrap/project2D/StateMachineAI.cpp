#include "StateMachineAI.h"
#include <crtdbg.h>

StateMachineAI::StateMachineAI()
{
	bDrawLowerState = false;
}

StateMachineAI::~StateMachineAI()
{
	m_StateList.Clear();
}

void StateMachineAI::Update(float fDetaTime, Entity* Agent)
{
	_ASSERT(m_StateList.Size() > 0);
	if (m_StateList.Size() <= 0)
		return;

	_ASSERT(m_Stack.size() >= 0);
	if (m_Stack.size() < 0)
		return;

	m_Stack.top()->EnUpdate(fDetaTime, Agent);
}

void StateMachineAI::Draw(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return;

	m_Stack.top()->onDraw(m_2dRenderer);

	if (bDrawLowerState)
		Draw2ndFromTop(m_2dRenderer);
}

void StateMachineAI::Draw2ndFromTop(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return;

	m_Stack.SecondLast()->onDraw(m_2dRenderer);
}

void StateMachineAI::PushState(int nStateIndex)
{
	//_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;
	if (m_Stack.size() > 0)
		m_Stack.top()->onExit();

	m_Stack.push(m_StateList[nStateIndex]);

	m_Stack.top()->onEnter();
}

void StateMachineAI::RegisterState(int nStateIndex, BaseStateAI* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachineAI::PopState()
{
	if (m_Stack.size() > 0)
		m_Stack.top()->onExit();

	if (m_Stack.size() > 0)
		m_Stack.pop();
}