#include "Bot.h"

int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{
	int difX = abs(((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX);
	int difY = abs(((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY);

	return sqrt((difX * difX) + (difY * difY));
	//return 0;
}

Bot::Bot(GridNode** ppGrid)
{
	m_ppGrid = ppGrid;

	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	m_pAStar->SetHeuristic(CalcHeuristic);

	nxtNode = 0;

	m_Default = new Texture("./textures/car.png");
	m_Ship = new Texture("./textures/ship.png");
	m_Car = m_Default;
	start = 0;
	end = 224;
}


Bot::~Bot()
{
	delete m_Default;
	delete m_Ship;
	delete m_pAStar;
}


void Bot::BotDraw(Renderer2D* m_Renderer)
{
	
	for (int i = 0; i < m_path.size(); i++)
	{
		GridNode* pNode = (GridNode*)m_path[i];
		m_Renderer->setRenderColour(0xFF1493FF);
		m_Renderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_Renderer->setRenderColour(0xFFFFFFFF);
	}

	m_Renderer->drawSprite(m_Car,Pos.x,Pos.y,0.0f,0.0f);

}


void Bot::Update(float deltaTime)
{
	m_path.clear();

	m_pAStar->CalculatePath(m_ppGrid[start], m_ppGrid[end], &m_path);

	if (nxtNode >= m_path.size())
	{
		nxtNode = 0;
		m_Car = m_Ship;
	}

	if (nxtNode != 0)
	{
		m_Car = m_Default;
	}

	Vector2 dest = ((GridNode*)m_path[nxtNode])->m_v2Pos;
	Vector2 dir = dest - Pos;

	dir.normalise();

	Pos = Pos + dir * 300.0f * deltaTime;

	Vector2 dist = dest - Pos;
	float mDist = dist.magnitude();

	if (mDist < 25)
	{
		++nxtNode;
	}
}

void Bot::onEnter() {}
void Bot::EnUpdate(float deltaTIme, Entity* Agent) {}
void Bot::onDraw(Renderer2D* renderer2D) {}
void Bot::onExit() {}