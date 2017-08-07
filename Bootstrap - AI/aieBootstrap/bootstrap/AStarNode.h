/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

AStarNode - Header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include <vector>

using namespace std;

struct AStarNode;

/********************************************************************************************
Struct AStarEdge
*********************************************************************************************/
struct AStarEdge
{
	AStarNode* m_pEndNode;
	int m_ncost;
};

/********************************************************************************************
Struct AStarNode
*********************************************************************************************/
struct AStarNode
{
	AStarNode(int Index)										  //ASTarNode Constructor - parameter Index passed in
	{
		m_pPrevious = nullptr;									  //Initializes Previous Node as Null
		m_nGScore = 0;											  //Sets G Score as 0
		m_nHScore = 0;											  //Sets H Score as 0
		m_nFScore = 0;											  //Sets F Score as 0
		m_nIndex = Index;										  //Sets m_nIndex as Index
		m_blocked = false;										  //Initializes Node as unblocked
	}
	//constructor ends

	virtual ~AStarNode()										  //AStarNode Destructor
	{
		for(unsigned int i = 0; i < m_AdjacentList.size();i++)    //Goes through Loop deleting all Adjacent list
		{
			delete m_AdjacentList[i];
		}
	}
	//destructor ends

	AStarNode*			m_pPrevious;							  //Creates Nodes for Previous
	vector <AStarEdge*> m_AdjacentList;							  //Creates an Object Array for AStarEdge called m_AdjacentList

	int m_nGScore;												  //Creates variable m_nGScore for G Score
	int m_nHScore;												  //Creates variable m_nHScore for H Score
	int m_nFScore;												  //Creates variable m_nFScore for F Score
	int m_nIndex;												  //Creates variable m_nIndex for indexing nodes
	bool m_blocked;												  //Creates variable m_blocked for determining if Node is blocked
};