#pragma once

// Static Integer Stack (array implementation)

class IntStack
{
private:
	int* stackArray;	// Array
	int capacity;		// How many items can be stored in the stack
	int top;			// Current top of the stack
public:
	IntStack(int capacity);	// Constructor
	~IntStack()
	{
		delete[] stackArray;
	}
	void push(int value);
	void pop(int& value);	// Reference used for printing purposes only
	bool isEmpty() const;

	// Stack Exceptions (Inner classes)
	class Overflow {};
	class Underflow {};
};