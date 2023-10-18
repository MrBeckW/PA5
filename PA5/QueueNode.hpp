#pragma once

#include <iostream>
#include "Data.hpp"


class QueueNode
{
public:
	QueueNode(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0, const int newArrivalTime = 0);
	~QueueNode();

	Data* getData();
	QueueNode* getpNext();

	void setmpNext(QueueNode* nextNode);

private:
	Data* createData(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime);

	Data* mpData;
	QueueNode* mpNext;
};