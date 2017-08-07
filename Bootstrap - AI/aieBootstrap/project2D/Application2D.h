/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

Application2D - header
*******************************************************************************************/

//include files to get references and required files

#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GridNode.h"
#include "defines.h"
#include "AStar.h"
#include "Bot.h"
#include "Bot2.h"
#include "BotUnit.h"
#include "BotDecision.h"
#include "Font.h"


using namespace aie;															//namespace to use aie type files easier

/********************************************************************************************
Class Application2D inherits from class Application 
*********************************************************************************************/
class Application2D : public Application {
public:

	Application2D();															//Application2D constructor
	virtual ~Application2D();													//Application2D destructor
																				
	virtual bool startup();														//Startup initiates objects and classes to be used
	virtual void shutdown();													//Shutdown destructs and deletes objects that were used																			
	virtual void update(float deltaTime);										//Update runs through the program continously until stopped updating information about objects
	virtual void draw();														//Draw renders objects created in the program
																				
protected:																		
	float		 m_timer;														//float m_timer is used for keeping track of runtime
	char		 m_instruction[200];											//m_instruction Char array for displaying intructions on the screen

	Renderer2D*	 m_2dRenderer;													//m_2dRenderer is the instance of Renderer2d in Application2D
	GridNode**   m_ppGrid;														//m_ppGrid is the instance used for GrindNodes in Application2D
	Bot*		 m_bot;															//m_bot is the instance of Bot for pathfinding
	Bot2*		 m_bot2;														//m_bot2 is the instance of Bot2 for pathfinding
	BotUnit*	 m_botunit;														//m_botunit is the instance of BotUnit for State behaviors
	BotDecision* m_botdecision;													//m_botdecision is the instance of BotDecision for Decision Tree behaviors
	Font*		 m_font;														//m_Font is the instance of Font for creating texts for Instuctions
};