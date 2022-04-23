
#include "DynamicStack.h"
#include <iostream>

//
//template <typename T>
//void DynamicStack<T>::push(T  inpute)
//{
//	top = new StackNode(inpute, top);
//}
//
//template <typename T>
//void DynamicStack<T>::pop(T& inpute)
//{
//	StackNode* temp;
//
//	if (isEmpty())
//	{
//		std::cout << "The stack is empty.\n";
//		exit(1);	// Don't do this!!! Use exception handling
//	}
//	else
//	{
//		inpute = top->value;
//
//		temp = top;
//		top = top->next;
//		delete temp;
//	}
//
//	temp = nullptr;
//}
//
//template <typename T>
//bool DynamicStack<T>::isEmpty() const
//{
//	return (!top);
//}