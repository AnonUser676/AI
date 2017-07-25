#include "AStar.h"

AStar::AStar(int MaxNodes) 
{
	m_nMaxNodes = MaxNodes;
	m_ClosedList = new bool[MaxNodes];
}

AStar::~AStar() 
{
	delete[] m_ClosedList;
}

bool AStar::CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath)
{
	
	//Reset everything in case there was a previous path
	m_OpenList.clear();

	memset(m_ClosedList, 0, sizeof(bool) * m_nMaxNodes);
	
	//add start node to open file
	pStart->m_nGScore = 0;

	pStart->m_nHScore = CalcHeuristic(pStart,pEnd);

	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;

	pStart->m_pPrevious = nullptr;

	m_OpenList.Push(pStart);

	//while there are still nodes in the open list
	while (m_OpenList.GetSize() > 0)
	{
		AStarNode* pCurrentNode = m_OpenList.pop();
		//get the node from the open list with the lowest F scope call it current node

		//Remove that node from the open list
		m_ClosedList[pCurrentNode->m_nIndex] = true;
		//add that node to the closed list

		//if current node is end node we are finished
		if (pCurrentNode == pEnd)
		{
			AStarNode* pNode = pEnd;
			//build path remember it is backwards so we need to fix that
			do
			{
				finishedPath->insert(finishedPath->begin(), pNode);
				pNode = pNode->m_pPrevious;
			} while (pNode);

			//return that we found a valid path
			return true;
		}
		
		//Loop through all of current nodes neighbors, 
		for (int i = 0; i < pCurrentNode->m_AdjacentList.size(); i++)
		{
			AStarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_pEndNode;
			int nCost = pCurrentNode->m_AdjacentList[i]->m_ncost;

			//check if the node is blocked
			if (pNeighbour->m_blocked == true)
				continue;

			//skip neighbors that are already in the closed list
			if (m_ClosedList[pNeighbour->m_nIndex])
				continue;

			//if neighbor is already in open list
			if (m_OpenList.Contains(pNeighbour))
			{
				
				//check if this current path is better than old path (lower f score)
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)
				{
					//update G score
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

					//update H score
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;
					
					//update F score
					pNeighbour->m_pPrevious = pCurrentNode;
				}
			}

			//else (neighbor now in open list)
			else
			{
				//calculate G score
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

				//calculate H score
				pNeighbour->m_nHScore = CalcHeuristic(pNeighbour,pEnd);

				//calculate F score
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

				//Set Prev mode pointer
				pNeighbour->m_pPrevious = pCurrentNode;

				//add neighbour to open list
				m_OpenList.Push(pNeighbour);
			}
		}
	}
	//if it get to here, then there is no path, return false...
	return false;
}

void AStar::SetHeuristic(HeuristicFunction func)
{
	FuncCall = func;
}

int AStar::CalcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{	
	return FuncCall(pNode, pEnd);

}

//testclass
/*

#pragma once

typedef void (*MyFunction)(float);

class TestClass
{
public:
	void CallFunction();
	void SetFunction(MyFunction func);

	MyFunctionmyFunc = nullptr;
	
};

#CPP
void TestClass::CallFunction()
{
myFunc(5.0f);
}

void TestClass::SetFunction(MyFunction func)
{
myFunc = func
}

#main
void main()
{
TestClass tc;
tc.SetFunction(&cat);
tc.CallFunction();
}
*/