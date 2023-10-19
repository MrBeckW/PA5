#pragma once

#include <iostream>
#include "Data.hpp"
#include "GroceryList.hpp"

using std::ostream;

class QueueNode
{
public:
	QueueNode(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0, const int newArrivalTime = 0);
	~QueueNode();

	Data* getData();
	QueueNode* getpNext();
	int getNumItems();

	void setmpNext(QueueNode* nextNode);
	void initializeGroceryList();

private:
	Data* createData(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime);
	

	Data* mpData;
	QueueNode* mpNext;
	List mGroceryList;
	int mNumItems;
};

ostream& operator<<(ostream& rhs, QueueNode &lhs);
int genRandomnum(int min, int max);