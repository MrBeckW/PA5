#include "QueueNode.hpp"

/// <summary>
/// defualt constructor for a QueueNode 
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
QueueNode::QueueNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime)
{
	this->mpData = createData(newCustomerNumber, newServiceTime, newTotalTime);
	this->mpNext = nullptr;
	if (mpData == nullptr)
	{
		std::cout << "Failed to allocate memory for Data!";
	}
}

/// <summary>
/// getter for mpData
/// </summary>
/// <returns>mpData</returns>
Data* QueueNode::getData()
{
	return this->mpData;
}

/// <summary>
/// getter for mpNext
/// </summary>
/// <returns>mpNext</returns>
QueueNode* QueueNode::getpNext()
{
	return mpNext;
}

/// <summary>
/// setter for mpNext
/// </summary>
/// <param name="nextNode">pointer to the next node in queue</param>
void QueueNode::setmpNext(QueueNode* nextNode)
{
	this->mpNext = nextNode;
}

/// <summary>
/// Allocates space on the heap for a Data class
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
/// <returns>pointer to created Data class</returns>
Data* QueueNode::createData(const int newCustomerNumber, const int newServiceTime, const int newTotalTime)
{
	Data* pMem = new Data(newCustomerNumber, newServiceTime, newTotalTime);

	return pMem;
}
