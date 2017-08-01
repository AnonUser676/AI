#include "StateAggressive.h"
#include "BehaviorArrival.h"
#include "BehaviorFlee.h"
#include "Entity.h"
#include "Input.h"

StateAggressive::StateAggressive()
{

	m_BehaviorList.pushBack(new BehaviorArrival(1.0f));
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
	Input* input = Input::getInstance();
	
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

	time += deltaTime;

	Vector2 ForceMax;

	for (unsigned int i = 0; i < m_BehaviorList.Size(); i++)
	{
		Vector2 ForceCurrent = m_BehaviorList[i]->update(Agent, deltaTime);
		ForceCurrent = ForceCurrent * m_BehaviorList[i]->m_fWeighting;
		ForceMax = ForceMax + ForceCurrent;

		float ForceMagnitude = ForceMax.magnitude();
		if (ForceMagnitude > TRUNCATE)
		{
			ForceMax.normalise();
			ForceMax = ForceMax * TRUNCATE;
			break;
		}
	}

	Vector2 velocity = Agent->getVelocity();

	velocity = velocity + ForceMax;

	Agent->setVelocity(velocity);

	Agent->setPos(Agent->getPos() + velocity * 10 * deltaTime);
}

void StateAggressive::onExit()
{
	time = 0.0f;
}
