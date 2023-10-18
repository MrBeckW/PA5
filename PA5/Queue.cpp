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
void Queue::enqueue(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime)
{
	QueueNode* pMem = createNode(newCustomerNumber, newServiceTime, newTotalTime, newArrivalTime);

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
/// dequeues function for queue
/// </summary>
/// <returns>returns a pointer to a newly allocated Data member</returns>
Data Queue::dequeue()
{
	if (!this->isEmpty())
	{
		Data pTempData = *(this->mpHead->getData());
		QueueNode* pTempNode = mpHead;

		if (this->mpHead->getpNext() == nullptr)//checks if there is only one node in the queue
		{
			mpHead = nullptr;
			mpTail = nullptr;
		}
		else
		{
			mpHead = mpHead->getpNext();
		}
		delete pTempNode;//deletes node pointed to by mpHead, nodes destructor will take care of freeing memory from its Data member
		return pTempData;
	}
	else
	{
		std::cout << "Queue is Empty!\n";
	}
	return NULL;
}

/// <summary>
/// checks if the queue is empty
/// </summary>
/// <returns>true if the queue is empty</returns>
bool Queue::isEmpty()
{
	bool success = false;
	if (this->mpHead == nullptr)
	{
		success = true;
	}
	return success;
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
QueueNode* Queue::createNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime)
{
	QueueNode* pMem = new QueueNode(newCustomerNumber, newServiceTime, newTotalTime, newArrivalTime);

	return pMem;
}
