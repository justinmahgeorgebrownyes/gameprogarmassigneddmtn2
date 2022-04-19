#pragma once



#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class DynamicQueue
{
private:
	class QueueNode
	{
		friend class DynamicQueue;
		T value;
		QueueNode* next;

		QueueNode(T val, QueueNode* next = nullptr)
		{
			value = val;
			this->next = next;
		}
	};

	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and destructor
	DynamicQueue();
	~DynamicQueue();

	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	void clear();
};



