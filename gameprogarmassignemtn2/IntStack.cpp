#include "IntStack.h"

// Constructor
IntStack::IntStack(int capacity)
{
	this->capacity = capacity;
	stackArray = new int[capacity];
	top = 0;
}

// Push a value to the stack
void IntStack::push(int value)
{
	if (top == capacity) throw IntStack::Overflow();
	stackArray[top] = value;
	top++;
}

bool IntStack::isEmpty() const
{
	return (top == 0);
}

// Remove a value from the stack
void IntStack::pop(int& value)
{
	if (isEmpty()) throw IntStack::Underflow();
	top--;
	value = stackArray[top];
}