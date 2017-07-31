#pragma once
# include "Entity.h"
#include "Renderer2D.h"
#include "Matrix3.h"
#include "GridNode.h"
#include "defines.h"
#include "AStar.h"
#include "DynamicArray.h"
#include <stdlib.h>

using namespace aie;
using namespace std;

class Bot:public Entity
{
public:
	Bot(GridNode** ppGrid);
	~Bot();

	virtual void onEnter();
	virtual void EnUpdate(float deltaTIme, Entity* Agent);
	virtual void onDraw(Renderer2D* renderer2D);
	virtual void onExit();

	void BotDraw(Renderer2D* m_Renderer);
	void Update(float deltaTime);

protected:
	Renderer2D*		m_Renderer;
	Texture*		m_Default;
	Texture*		m_Car;
	Texture*		m_Ship;
	Vector2			velocity;
	AStar*			m_pAStar;
	GridNode**		m_ppGrid;
	vector<AStarNode*> m_path;

	Vector2 Pos;
	unsigned int nxtNode;
	int start;
	int end;
};

