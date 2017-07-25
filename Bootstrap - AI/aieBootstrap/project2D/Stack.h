#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:

	//----------------------------------------------------
	// Default constructor
	//----------------------------------------------------
	Stack(){}

	//----------------------------------------------------
	// Default destructor
	//----------------------------------------------------
	~Stack(){}

	//----------------------------------------------------
	// Checks if the stack is empty or not
	// returns:
	//		bool: is empty or not
	//----------------------------------------------------
	bool empty()
	{
		return s.empty();
	}
	
	//----------------------------------------------------
	// returns the number of items on the stack
	// returns:
	//		Size: how many items on the stack
	//----------------------------------------------------
	int size()
	{
		return s.Size();
	}

	//----------------------------------------------------
	// Adds an item to the top of the stack
	// params:
	//		value: item to add to stack
	//----------------------------------------------------
	void push(T value)
	{
		s.pushBack(value);
	}

	//----------------------------------------------------
	// Removes top item on stack
	// returns:
	//		T: returns the top objects contents
	//----------------------------------------------------
	T pop()
	{
		return s.popBack();
	}

	//----------------------------------------------------
	// returns the contents of the top of the stack without removing it
	// returns:
	//		T: returns the data on top of stack
	//----------------------------------------------------
	T top()
	{
		return s.back();
	}

	//----------------------------------------------------
	// Clears entire stack
	//----------------------------------------------------
	void Clear()
	{
		s.Clear();
	}

	//----------------------------------------------------
	// returns the contents of the second item on the stack
	// returns:
	//		T: returns the data of the second item on stack
	//----------------------------------------------------
	T SecondLast()
	{
		return s.SecondLast();
	}

	// Dynamic array for all stack functions to call from
	DynamicArray<T> s;

};