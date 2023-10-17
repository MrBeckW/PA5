#pragma once

#include <iostream>
#include "Data.hpp"


class QueueNode
{
public:
	QueueNode(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0);

	Data* getData();
	QueueNode* getpNext();

	void setmpNext(QueueNode* nextNode);

private:
	Data* createData(const int newCustomerNumber, const int newServiceTime, const int newTotalTime);

	Data* mpData;
	QueueNode* mpNext;
};