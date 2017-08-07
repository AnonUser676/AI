/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

AStar - header
*******************************************************************************************/

//include files to get references and required files

#pragma once
#include <vector>
#include "AStarNode.h"
#include "Heap.h"
#include "GridNode.h"

using namespace std;																		   //namespace to use aie type files easier

struct AStarNode;                                             								   

typedef int(*HeuristicFunction)(AStarNode* pNode, AStarNode* pEnd);							   //used for setting in custom heuritics for Astar


/********************************************************************************************
Class AStar Contents
*********************************************************************************************/
class AStar
{
public:
	AStar(int MaxNodes);																		//AStar constructor with MaxNodes parameter
	~AStar();																					//AStar destructor

	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath);	//bool function that checks path for AStar
	int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd);										//int function that calculates for Heuristic
	void SetHeuristic(HeuristicFunction func);													//function that can pass on custom heuristic functions

private:
	Heap		m_OpenList;																		//instance of Heap used for AStar

	HeuristicFunction FuncCall = nullptr;														//variable used for setting Heuristic functions initially set as nullptr
	int m_nMaxNodes;																			//variable for Max Nodes
	bool* m_ClosedList;																			//Bool variable used for setting closed list
};