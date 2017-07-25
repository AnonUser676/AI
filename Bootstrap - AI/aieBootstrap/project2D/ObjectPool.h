#pragma once

#include <unordered_map>
using namespace std;

template<class T, int SIZE>

class ObjectPool
{
public:
	ObjectPool()
	{
		m_pool = new T[SIZE];

		for (int i = 0; i < SIZE; i++)
			m_active[&m_pool[i]] = false;
	}

	virtual ~ObjectPool()
	{
		m_active.clear();
		delete[] m_pool;
	}

	T *Create()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (m_active[&m_pool[i]] == false)
			{
				m_active[&m_pool[i]] = true;
				return &m_pool[i];
			}
		}
		return nullptr;
	}
	


	void Destroy(T *obj)
	{
		m_active[obj] = false;
	}

private:
	T *m_pool;

	unordered_map<T*, bool> m_active;

};

