#pragma once
#include "QueueNode.hpp"

class Queue
{
public:
	Queue();

	void enqueue(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0, const int newArrivalTime = 0);
	Data dequeue();

	bool isEmpty();

	QueueNode* getmpHead();
	QueueNode* getmpTail();

private:

	QueueNode* createNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime);

	QueueNode* mpHead;
	QueueNode* mpTail;
};