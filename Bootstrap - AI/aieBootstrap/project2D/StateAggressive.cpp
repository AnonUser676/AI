#include "StateAggressive.h"
#include "BehaviorSeek.h"
#include "BehaviorFlee.h"
#include "Entity.h"
#include "Input.h"

StateAggressive::StateAggressive()
{

	m_BehaviorList.pushBack(new BehaviorSeek(0.0f));
	m_BehaviorList.pushBack(new BehaviorFlee(0.0f));

	m_car = new Texture("./textures/car.png");
}


StateAggressive::~StateAggressive()
{
	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		delete m_BehaviorList[i];
	}
	delete m_car;
}

void StateAggressive::onEnter()
{
	time = 0.0f;
}

void StateAggressive::onDraw(Renderer2D* renderer2D)
{
	renderer2D->drawSprite(m_car, Pos.x, Pos.y, m_car->getWidth(), m_car->getHeight());
}

void StateAggressive::onUpdate(float deltaTIme, StateMachine* State)
{
	time += deltaTIme;
}

void StateAggressive::EnUpdate(float deltaTime, Entity* Agent)
{
	time += deltaTime;

	Vector2 ForceMax;

	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		Input* input = Input::getInstance();

		if (m_BehaviorList[i]->m_fWeighting < 0.50f)
		{

			if (input->isKeyDown(INPUT_KEY_F))
			{
				m_BehaviorList[0]->m_fWeighting -= 0.01f;
				m_BehaviorList[1]->m_fWeighting += 0.01f;
			}
			else
			{
				m_BehaviorList[0]->m_fWeighting += 0.01f;
				m_BehaviorList[1]->m_fWeighting -= 0.01f;
			}
		}
		Vector2 ForceCurrent = m_BehaviorList[i]->update(Agent, deltaTime);
		ForceCurrent = ForceCurrent * m_BehaviorList[i]->m_fWeighting;
		ForceMax = ForceMax + ForceCurrent;

		float ForceMagnitude = ForceMax.magnitude();
		if (ForceMagnitude > 10.0f)
		{
			ForceMax.normalise();
			ForceMax = ForceMax * 10.0f;
			break;
		}


	}
	Agent->setPos(Agent->getPos() + ForceMax);
}

void StateAggressive::onExit()
{
	time = 0.0f;
}
/*
class composite : public BehaviorNode
{
public:

EBehqaviorResult:Execute()
{
	BehaviorNode* child = pendingNode;
	unsigned int index = -1

	if (!child)
	{
		i = 0;

	}

	for (;i < children.size(); i++)
	{
		if (i >= 0)
			{
				child = children[i];
			}

		EBehaviorResult result = child->Execute();
		if (result == EBehavior_Success)
			{
			pendingnode = nullptr;
			return EBEHavior_Success;
			}

		if (result == EBehavior_Failure)
		{
			index++;
			child = children[index];
		}
	}

	for (unsigned int i = 0; 1 < children.size(); i++)
	{
		if(children[i]->execute() == EBehavior_SUCCESS)
		{
			return EBehavior_Success;
		}
	
	}
	return EBehavior_fAIL;
}
}
*/