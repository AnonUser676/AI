#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "GridNode.h"
#include "defines.h"
#include "AStar.h"
#include "Bot.h"

using namespace aie;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Renderer2D*	m_2dRenderer;
	Texture* m_ship;
	
	float m_timer;

	GridNode** m_ppGrid;
	Bot*		bot;
};