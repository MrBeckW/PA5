#include "Queue.hpp"


/////////
//Queue - MemberFunctions

/// <summary>
/// defualt constructor for a Queue
/// </summary>
Queue::Queue()
{
	this->mpHead = this->mpTail = nullptr;
}

/// <summary>
/// creates a new QueueNode and inserts it at the end of the queue
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
void Queue::enqueue(const int newCustomerNumber, const int newServiceTime, const int newTotalTime)
{
	QueueNode* pMem = createNode(newCustomerNumber, newServiceTime, newTotalTime);

	if (pMem != nullptr && pMem->getData() != nullptr)//checks if memory was correctly allocated for both data and node
	{
		if (this->mpHead == nullptr)//inserts into an empty queue
		{
			mpHead = pMem;
			mpTail = pMem;
		}
		else//inserts into a queue with atleast one node
		{
			mpTail->setmpNext(pMem);
			mpTail = pMem;
			
		}
	}
	else
	{
		std::cout << "Failed to allocate memory for QueueNode!\n";
	}
}

/// <summary>
/// getter for mpHead
/// </summary>
/// <returns>mpHead</returns>
QueueNode* Queue::getmpHead()
{
	return this->mpHead;
}

/// <summary>
/// getter for mpTail
/// </summary>
/// <returns>mpTail</returns>
QueueNode* Queue::getmpTail()
{
	return this->mpTail;
}



////////
//Queue- Private Member Functions

/// <summary>
/// allocates space for a QueueNode on the heap
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
/// <returns>pointer to newly allocated node</returns>
QueueNode* Queue::createNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime)
{
	QueueNode* pMem = new QueueNode(newCustomerNumber, newServiceTime, newTotalTime);
	
	return pMem;
}
