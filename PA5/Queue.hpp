#pragma once
#include "QueueNode.hpp"

class Queue
{
public:
	Queue();

	void enqueue(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0);

	QueueNode* getmpHead();
	QueueNode* getmpTail();

private:

	QueueNode* createNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime);

	QueueNode* mpHead;
	QueueNode* mpTail;
};