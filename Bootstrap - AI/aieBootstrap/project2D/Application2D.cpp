#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"



using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	m_timer = 0;
	//Create Grid
	m_ppGrid = new GridNode*[ GRID_SIZE * GRID_SIZE ];

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			//Calculate the index
			int index = (y*GRID_SIZE) + x;
			
			//calculate the position
			Vector2 pos((float)x * NODE_SIZE,(float) y * NODE_SIZE);

			//Create the nodes
			m_ppGrid[index] = new GridNode(pos, index , x , y);

			if (x % 3 == 0 && y != 0)
			{
				m_ppGrid[index]->m_blocked = true;
			}
		}
	}

	//connect up adjacent nodes

	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int index = (y * GRID_SIZE) + x;
			GridNode* currentNode = m_ppGrid[index];
			//adjacent nodes
			for (int a = 0; a < 4; a++)
			{
				//check adjacent nodes
				int localX = x;
				int localY = y;

				if (a % 2 == 0)
				{
					localX += a - 1;
				}
				else
				{
					localY += a - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_ncost = 10;
			
				currentNode->m_AdjacentList.push_back(pEdge);
			}

			//diagonal nodes
			for (int d = 0; d < 4; d++)
			{
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}
				else
				{
					localX += d - 2;
					localY -= d - 2;
				}
				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				GridNode* adjNode = m_ppGrid[localIndex];

				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_ncost = 10;

				currentNode->m_AdjacentList.push_back(pEdge);
			}
		}
	}
	bot = new Bot(m_ppGrid);
	return true;
}

void Application2D::shutdown() 
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		delete m_ppGrid[i];
	}

	delete[] m_ppGrid;
	
	delete m_2dRenderer;

	delete bot;

}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();

	bot->Update(deltaTime);
}

void Application2D::draw() 
{
	clearScreen();

	m_2dRenderer->setCameraPos(-100, -100);
	m_2dRenderer->begin();

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;
		if (m_ppGrid[i]->m_blocked)
		{
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
		else
		{
			m_2dRenderer->setRenderColour(0x0000FFFF);
		}
		m_2dRenderer->drawBox(x, y, NODE_SIZE - 6, NODE_SIZE - 6);

	}
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;
		for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.size(); a++)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherx = otherNode->m_v2Pos.x;
			float othery = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(0xF0001020);
			m_2dRenderer->drawLine(x, y, otherx, othery, 10);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
	}

	bot->BotDraw(m_2dRenderer);
	m_2dRenderer->end();
}