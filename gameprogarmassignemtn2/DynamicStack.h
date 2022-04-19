#pragma once
//#include "DynamicStack.h"
#include <iostream>
#include <cstdlib>	

template <typename T>
class DynamicStack
{


private:
	class StackNode
	{
		friend class DynamicStack;
		T value;
		StackNode* next;

		// Constructor
		StackNode(T val, StackNode* next = nullptr)
		{
			value = val;
			this->next = next;
		}
	};

	StackNode* top;
public:
	DynamicStack()
	{
		top = nullptr;
	}

	void push(T inpute);
	void pop(T&);
	bool isEmpty() const;



};
