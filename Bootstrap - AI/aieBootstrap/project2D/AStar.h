#pragma once
#include <vector>
#include "AStarNode.h"
#include "Heap.h"
#include "GridNode.h"

using namespace std;

struct AStarNode;

typedef int(*HeuristicFunction)(AStarNode* pNode, AStarNode* pEnd);

class AStar
{
public:
	AStar(int MaxNodes);
	~AStar();

	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath);
	
	int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd);

	void SetHeuristic(HeuristicFunction func);

private:
	
	HeuristicFunction FuncCall = nullptr;

	int m_nMaxNodes;

	Heap m_OpenList;
	bool* m_ClosedList;
};

