#pragma once
#include <vector> //used linkedlist

using namespace std;

struct AStarNode;

struct AStarEdge
{
	AStarNode* m_pEndNode;

	int m_ncost;
};

struct AStarNode
{
	AStarNode(int Index)
	{
		m_pPrevious = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = Index;
		m_blocked = false;
	}

	virtual ~AStarNode()
	{
		for(unsigned int i = 0; i < m_AdjacentList.size();i++)
		{
			delete m_AdjacentList[i];
		}
	}

	AStarNode* m_pPrevious;

	int m_nGScore;
	int m_nHScore;
	int m_nFScore;
	int m_nIndex;
	bool m_blocked;
	vector <AStarEdge*> m_AdjacentList;
};