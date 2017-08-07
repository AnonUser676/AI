/********************************************************************************************
AI Pathfinding and Behavior Styles
by Rouie Ortega
using AIE Boostrap

AStar - CPP
*******************************************************************************************/

//include files to get references and required files

#include "AStar.h"

/********************************************************************************************
Class AStar Constructor - parameter MaxNodes
*********************************************************************************************/
AStar::AStar(int MaxNodes) 
{
	m_nMaxNodes = MaxNodes;																		  
	m_ClosedList = new bool[MaxNodes];															 //MaxNodes used for creating Closed List
}

/********************************************************************************************
Class AStar Destructor
*********************************************************************************************/
AStar::~AStar() 
{
	delete[] m_ClosedList;																		 //deletes Closed List
}

/********************************************************************************************
Class AStar CalculatePath - parameters AStarNode pStart, AstarNode pEnd, AstarNode path
*********************************************************************************************/
bool AStar::CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath)
{
	m_OpenList.clear();																			 //Reset everything in case there was a previous path
	memset(m_ClosedList, 0, sizeof(bool) * m_nMaxNodes);
																								 //add start node to open file
	pStart->m_nGScore = 0;
	pStart->m_nHScore = CalcHeuristic(pStart,pEnd);
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;
	pStart->m_pPrevious = nullptr;
	m_OpenList.Push(pStart);

	while (m_OpenList.GetSize() > 0)															 //while there are still nodes in the open list
	{
		AStarNode* pCurrentNode = m_OpenList.pop();												 //get the node from the open list with the lowest F scope call it current node
																								 //Remove that node from the open list
		m_ClosedList[pCurrentNode->m_nIndex] = true;											 //add that node to the closed list
		
		if (pCurrentNode == pEnd)																 //if current node is end node we are finished
		{
			AStarNode* pNode = pEnd;
			
			do																					 //build path remember it is backwards so we need to fix that
			{
				finishedPath->insert(finishedPath->begin(), pNode);
				pNode = pNode->m_pPrevious;
			} while (pNode);

			return true;																		 //return that we found a valid path
		}
		
		for (int i = 0; i < pCurrentNode->m_AdjacentList.size(); i++)							 //Loop through all of current nodes neighbors
		{
			AStarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_pEndNode;
			int nCost = pCurrentNode->m_AdjacentList[i]->m_ncost;

			if (pNeighbour->m_blocked == true)													 //check if the node is blocked
				continue;

			if (m_ClosedList[pNeighbour->m_nIndex]) 											 //skip neighbors that are already in the closed list
				continue;

			if (m_OpenList.Contains(pNeighbour))												 //if neighbor is already in open list
			{
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)					 //check if this current path is better than old path (lower f score)
				{
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;					 //update G score
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;		 //update H score
					pNeighbour->m_pPrevious = pCurrentNode;										 //update F score
				}
			}
			else																				 //else (neighbor now in open list)
			{
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;						 //calculate G score
				pNeighbour->m_nHScore = CalcHeuristic(pNeighbour,pEnd);							 //calculate H score
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;			 //calculate F score
				pNeighbour->m_pPrevious = pCurrentNode;											 //Set Prev mode pointer
				m_OpenList.Push(pNeighbour);													 //add neighbour to open list
			}
		}
	}
	return false;																				 //if it get to here, then there is no path, return false...
}

/********************************************************************************************
Class AStar SetHeuristic - parameters HeuristicFunc func
*********************************************************************************************/
void AStar::SetHeuristic(HeuristicFunction func)
{
	FuncCall = func;																			 //sets passed in function as Heuristic
}

/********************************************************************************************
Class AStar CalcHeuristic - parameters AStarNode pNode, AstarNode pEnd
*********************************************************************************************/
int AStar::CalcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{	
	return FuncCall(pNode, pEnd);																 //Calculates Heuristic based on passed in function and inputted Nodes

}