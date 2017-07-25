#pragma once
#include <memory.h>

// Templates so it can be applied to any class or variable type
template <typename T>
class DynamicArray
{
public:

	//----------------------------------------------------
	// Creates the dynamic array with a max size stated by user
	// parameters:
	//		initial size: max size to start the dynamic array at
	//----------------------------------------------------
	DynamicArray(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	//----------------------------------------------------
	// default destructor
	// deletes dynamic array
	//----------------------------------------------------
	~DynamicArray()
	{
		delete m_pData;
	}

	//----------------------------------------------------
	// Creates dynamic array from existing array
	// parameters:
	//		takes in a const dynamic array
	//----------------------------------------------------
	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	//----------------------------------------------------
	// Checks if there is enough room for more data if not calls Resize()
	// adds data to the back of the array and pushes everything back
	// parameters:
	//		value: Takes in data of type determined by template
	//----------------------------------------------------
	void pushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();

		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	//----------------------------------------------------
	// Calls insert() for first index
	// parameters:
	//		value: Takes in data of type determined by template
	//----------------------------------------------------
	void pushFront(T value)
	{
		Insert(0, value);
	}

	//----------------------------------------------------
	// Checks if index is valid
	// Checks if there is enough room for more data if not calls Resize()
	// adds data to the specified index in array and pushes everything else back
	// parameters:
	//		Index: int that determines where in the array to add value
	//		value: Takes in data of type determined by template
	//----------------------------------------------------
	void Insert(int index, T value)
	{
		if (index > m_nUsed)
			return;

		if (m_nUsed >= m_nCapacity)
			Resize();

		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}
		m_pData[index] = value;
		++m_nUsed;

	}

	//----------------------------------------------------
	// reduces the amount of used slots by 1 
	// returns the data from the back of the array
	// return:
	//		returns the last value on the array
	//----------------------------------------------------
	T popBack()
	{
		--m_nUsed;
		return m_pData[m_nUsed];
	}

	//----------------------------------------------------
	// Checks if the index is valid
	// adds data to the back of the array and pushes everything back
	// parameters:
	//		index: int that determines a location in the array
	//----------------------------------------------------
	T Remove(int index)
	{
		// backup value we are removing from list
		T value = m_pData[index];

		// shuffle all other values across to fill removed space
		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		// return removed value
		return value;
	}

	//----------------------------------------------------
	// calls remove() on first index
	// returns the data from the back of the array
	// return:
	//		returns the last value on the array
	//----------------------------------------------------
	T popFront()
	{
		return Remove(0);
	}

	//----------------------------------------------------
	// makes m_nUsed = 0 basically removing all usefull data from the array
	//----------------------------------------------------
	void Clear()
	{
		m_nUsed = 0;
	}

	//----------------------------------------------------
	// checks capacity size
	// resizes array to smallest possible size while retaining the data
	//----------------------------------------------------
	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[nCapacity];
		memcpy(newData, m_pData, sizeof(T) * nCapacity);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = nCapacity;
	}

	//----------------------------------------------------
	// Operator overload for []
	// params:
	//		takes in a templated data type
	// return:
	//		returns data from selected index
	//----------------------------------------------------
	T& operator[](const int index)
	{
		return m_pData[index];
	}

	//----------------------------------------------------
	// Gets the size of the array as int
	// return:
	//		m_nUsed: returns the size of the array
	//----------------------------------------------------
	int Size()
	{
		return m_nUsed;
	}

	//----------------------------------------------------
	// Gets the capacity of the array as int
	// return:
	//		m_nCapacity: returns the Capacity of the array
	//----------------------------------------------------
	int Capacity()
	{
		return m_nCapacity;
	}

	//----------------------------------------------------
	// checks if the array is empty or not
	// returns:
	//		bool indicating whether array is empty or not
	//----------------------------------------------------
	bool empty()
	{
		if (m_nUsed <= 0)
			return true;
		else
			return false;
	}

	//----------------------------------------------------
	// returns the data from the end of the array
	// return:
	//		Returns the data from the end of the array
	//----------------------------------------------------
	T back()
	{
		return m_pData[m_nUsed - 1];
	}

	//----------------------------------------------------
	// returns the second last piece of data from the array
	// return:
	//		Returns the second last piece of data from the array
	//----------------------------------------------------
	T SecondLast()
	{
		return m_pData[m_nUsed - 2];
	}
	

private:
	// IDK
	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

	void Resize()
	{
		// Create new array that is twice as big as original
		T* newData = new T[m_nCapacity * 2];

		// Cope old data across into new array
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);

		// Delete old array
		delete m_pData;

		//Make sure our pointers still work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	};

	T* m_pData;
	int m_nCapacity;
	int m_nUsed;
};