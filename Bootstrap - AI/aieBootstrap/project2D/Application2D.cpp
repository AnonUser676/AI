/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

Application2D - CPP
*******************************************************************************************/

//include files to get references and required files

#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "BaseStateAI.h"
#include <iostream>
#include <cstring>


using namespace aie;														//namespace to use aie type files easier

Application2D::Application2D() {}											//Application2D constructor does nothing as Startup handles the creation of new objects
Application2D::~Application2D() {}											//Application2D constructor does nothing as Shutdown handles the destruction of created objects


/********************************************************************************************
Class Application2D startup (parameters - none)
acts as constructor for Application2D class
*********************************************************************************************/
bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();										 //creates instance of Renderer2D named m_2dRenderer for drawing objects

	m_timer = 0;															 //sets runtime at start to 0
	
	m_ppGrid = new GridNode*[ GRID_SIZE * GRID_SIZE ];						 //Create Grid with instance called m_ppGrid, has Grid size dependent on defines.h

	for (int x = 0; x < GRID_SIZE; x++)										 //Sets up for Loop for creating indexing the Grid and setting up positions
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			int index = (y*GRID_SIZE) + x;									 //Calculate the index			
			Vector2 pos((float)x * NODE_SIZE,(float) y * NODE_SIZE);		 //calculate the position
			m_ppGrid[index] = new GridNode(pos, index , x , y);				 //Create the nodes onto the position set

			if (x % 3 == 0 && y != 6 && y != 9 && y != 10)					 //Sets up blocked nodes which will be every 3 columns and any rows except the 6th, 9th and 10th rows
			{
				m_ppGrid[index]->m_blocked = true;							 //Sets those nodes to blocked
			}
		}
	}
	for (int x = 0; x < GRID_SIZE; x++)										 //connect up adjacent nodes with the similar methods above
	{
		for (int y = 0; y < GRID_SIZE; y++)									 
		{
			int index = (y * GRID_SIZE) + x;								 //To set up current Grid Index for AStarEdge and adjacent nodes
			GridNode* currentNode = m_ppGrid[index];
			
			for (int a = 0; a < 4; a++)										 //adjacent nodes with the int value a
			{
				int localX = x;												 //variables used to check adjacent nodes
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
				GridNode* adjNode = m_ppGrid[localIndex];					   //sets adjacent Nodes to be the value of local Index

				AStarEdge* pEdge = new AStarEdge();							   
				pEdge->m_pEndNode = adjNode;
				pEdge->m_ncost = 10;
			
				currentNode->m_AdjacentList.push_back(pEdge);
			}

			for (int d = 0; d < 4; d++)										   //checking diagonal nodes
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

				currentNode->m_AdjacentList.push_back(pEdge);				   //these codes are for measuring path costing for AStar
			}
		}
	}
	m_bot = new Bot(m_ppGrid);												  //creates new bot for pathfinding
	m_bot2 = new Bot2(m_ppGrid);											  //creates a 2nd bot for pathfinding
	m_botunit = new BotUnit;												  //creates a bot for State Machine behaviors
	m_botdecision = new BotDecision;										  //createe a bot for Decision Tree behaviors
	m_font = new Font("./font/consolas.ttf", 32);							  //creates an instance of Font for instructions
	return true;
}

/********************************************************************************************
Class Application2D shutdown (parameters - none)
acts as destructor for Application2D class
*********************************************************************************************/
void Application2D::shutdown() 
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)							 //runs through loop destroying all members of GridNode
	{
		delete m_ppGrid[i];
	}
	delete[] m_ppGrid;														 //deletes instance of GridNode afterwards
	delete m_2dRenderer;													 //deletes instance of Renderer2D
	delete m_bot;															 //deletes instance of Bot
	delete m_bot2;															 //deletes instance of Bot2
	delete m_botunit;														 //deletes instance of BotUnit
	delete m_botdecision;													 //deletes instance of BotDecision
	delete m_font;															 //deletes instance of Font
}

/********************************************************************************************
Class Application2D draw (parameters - none)
Renders objects created in Application2D class
*********************************************************************************************/
void Application2D::draw()
{
	clearScreen();															 //clears created window leaving black bg color

	m_2dRenderer->setCameraPos(-OFFSET, -OFFSET);							 //sets camera poition of window to the Offset
	m_2dRenderer->begin();													 //Renderer operation function begins

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)							 //creates a Loop for Rendering each Node of the Grid
	{
		float x = m_ppGrid[i]->m_v2Pos.x;									 //places Node with index number i on m_v2Pos
		float y = m_ppGrid[i]->m_v2Pos.y;
		
		if (m_ppGrid[i]->m_blocked)											 //An If Statement declares whch node color is to be used for blocked and unblocked Nodes
		{
			m_2dRenderer->setRenderColour(0xFFFFFFFF);						 //Blocked Node color
		}
		else
		{
			m_2dRenderer->setRenderColour(0x0000FFFF);						 //unblocked node color
		}

		m_2dRenderer->drawBox(x, y, NODE_SIZE - 6, NODE_SIZE - 6);			 //actual printing of the node as a box with Node_Size as size-6

	}
	m_2dRenderer->setRenderColour(0xFFFFFFFF);								 //resets Renderer color back to White
	
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)							 //Another Loop created to Render possible paths for Bot and Bot2 and display adjacent nodes
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;
		for (unsigned int a = 0; a < m_ppGrid[i]->m_AdjacentList.size(); a++)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherx = otherNode->m_v2Pos.x;
			float othery = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(0xF0001020);
			m_2dRenderer->drawLine(x, y, otherx, othery, 10);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
	}

	m_2dRenderer->drawText(m_font, m_instruction, -100, 900);				//Renders the instruction at Application window
	m_bot->BotDraw(m_2dRenderer);											//function call for Renderering instance of Bot
	m_bot2->BotDraw(m_2dRenderer);											//function call for Renderering instance of Bot2
	m_botunit->onDraw(m_2dRenderer);										//function call for Renderering instance of BotUnit
	m_botdecision->BotDraw(m_2dRenderer);									//function call for Renderering instance of BotDecision
	m_2dRenderer->end();												    //function call for Ending Rendering
}

/********************************************************************************************
Class Application2D Update (parameters - none)
Updates objects created in Application2D class
*********************************************************************************************/
void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;													//updates time float for measuring runtime

	Input* input = Input::getInstance();									//creates an Instance of Input on Application2D
	if (input->isKeyDown(INPUT_KEY_ESCAPE))									//If Statement that waits for Escape Key to be pressed
		quit();																//Exits Application2D calling on shutdown before ending when escape is presed

	m_bot->Update(deltaTime);												//function call for updating information about Bot
	m_bot2->Update(deltaTime);												//function call for updating information about Bot2
	m_botunit->EnUpdate(deltaTime, m_botunit);								//function call for updating information about BotUnit
	m_botdecision->Update(deltaTime);										//function call for updating information about BotDecision
	strcpy_s(m_instruction, "The White ball will change behavior if you hold F, the green box will change behavior if you press SPACE");
}