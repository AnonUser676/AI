#pragma once
#include <vector> //use dybnamic array
#include "math.h"
#include "AStarNode.h"


class Heap
{
public:
	
	void Push(AStarNode* data)
	{
		//add data to end of array
		m_Data.push_back(data);

		//loop through and swap value with if data is smaller
		int current = m_Data.size() - 1;
		while (true)
		{
			if (current == 0)
				break;

			int Parent = GetParentIndex(current);

			if (m_Data[current]->m_nFScore < m_Data[Parent]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[Parent];
				m_Data[Parent] = swap;

				current = Parent;
			}
			else
				break;
		}
		//repeat until no swap required
	}

	AStarNode* pop()
	{
		AStarNode* result = m_Data[0];

		int last = m_Data.size() - 1;
		m_Data[0] = m_Data[last];

		int current = 0;

		while (true)
		{
			int child0 = GetChildIndex(current,1);
			if (child0 > last) { break; }

			int child1 = GetChildIndex(current, 2);
			int smallerchild = child0;
			
			if (child1 <= last && m_Data[child1]->m_nFScore < m_Data[smallerchild]->m_nFScore)
				smallerchild = child1;
			
			if (m_Data[smallerchild]->m_nFScore < m_Data[current]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[smallerchild];
				m_Data[smallerchild] = swap;

				current = smallerchild;
			}
			else
				break;
		}
		
		m_Data.pop_back();
		return result;
		//replace first element with last element
		//swap first element with smaller element if child is smaller
	}

	void clear()
	{
		m_Data.clear();
	}

	int GetSize()
	{
		return (int)m_Data.size();
	}
	
	int GetParentIndex(int childindex)
	{
		return (childindex - 1) / 2;
	}

	int GetChildIndex(int ParentIndex, int ChildIndex)
	{
		return (2 * ParentIndex) + ChildIndex;
	}

	bool Contains(AStarNode* m_nData)
	{
		for (int i = 0; i < GetSize(); i++)
		{
			if (m_Data[i] == m_nData)
			{
				return true;
			}
		}
		return false;
	}

private:
	vector<AStarNode*> m_Data;
};

