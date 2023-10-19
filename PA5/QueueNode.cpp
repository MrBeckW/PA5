#include "QueueNode.hpp"

///////////////////
//member-functions

/// <summary>
/// defualt constructor for a QueueNode 
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
QueueNode::QueueNode(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime)
{
	this->mpData = createData(newCustomerNumber, newServiceTime, newTotalTime, newArrivalTime);
	this->mpNext = nullptr;
	if (mpData == nullptr)
	{
		std::cout << "Failed to allocate memory for Data!";
	}
	
	mNumItems = genRandomnum(1, 10);
	initializeGroceryList();
}

/// <summary>
/// destructor for QueueNode, frees allocated memory for Data member
/// </summary>
QueueNode::~QueueNode()
{
	delete this->mpData;
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
/// getter for mNumItems
/// </summary>
/// <returns></returns>
int QueueNode::getNumItems()
{
	return mNumItems;
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
Data* QueueNode::createData(const int newCustomerNumber, const int newServiceTime, const int newTotalTime, const int newArrivalTime)
{
	Data* pMem = new Data(newCustomerNumber, newServiceTime, newTotalTime, newArrivalTime);

	return pMem;
}

/// <summary>
/// this function creates a grocery list consisting of random items. The number of items is randomly generated in the QueNode constructor.
/// </summary>
void QueueNode::initializeGroceryList()
{
	
	for (int i = 0; i < mNumItems; i++)
	{
		int selection = genRandomnum(1, 10);

		switch (selection)
		{
		case 1:
			mGroceryList.mInsertAtFront("Milk");
			break;
		case 2:
			mGroceryList.mInsertAtFront("Steak");
			break;
		case 3:
			mGroceryList.mInsertAtFront("Chicken");
			break;
		case 4: 
			mGroceryList.mInsertAtFront("Yogurt");
			break;
		case 5:
			mGroceryList.mInsertAtFront("Cereal");
			break;
		case 6:
			mGroceryList.mInsertAtFront("Coffee");
			break;
		case 7:
			mGroceryList.mInsertAtFront("Eggs");
			break;
		case 8:
			mGroceryList.mInsertAtFront("Cheese");
			break;
		case 9:
			mGroceryList.mInsertAtFront("Pretzels");
			break;
		case 10:
			mGroceryList.mInsertAtFront("Bacon");
			break;
		default:
			break;
		}
		

	}
}


///////////////////////
//Non member-functions

/// <summary>
/// stream insertion operator for QueueNode class
/// </summary>
/// <param name="rhs"></param>
/// <param name="lhs"></param>
/// <returns></returns>
ostream& operator<<(ostream& rhs, QueueNode& lhs)
{
	rhs << *lhs.getData();
	return rhs;
}

/// <summary>
/// function that randomly generates a number specified by the input range
/// </summary>
/// <param name="min">range minimum for random number</param>
/// <param name="max">range maximum for random number</param>
/// <returns>the randomized number</returns>
int genRandomnum(int min, int max)
{
	srand((unsigned)time(NULL));

	int ranNum = min + (rand() % max);

	return ranNum;
}
