#include "TestClass.hpp"

TestClass::TestClass()
{
	this->testCustomerNumber = 0;
	this->testServiceTime = 0;
	this->testTotalTime = 0;
}

/// <summary>
/// Tests the function Enqueue on an empty queue
/// </summary>
/// <param name=""void></param>
void TestClass::testEnqueueEmpty(void)
{
	std::cout << "--ENQUEUE TEST ON EMPTY QUEUE--\n";

	this->mEmptyQueue.enqueue(testCustomerNumber, testServiceTime, testTotalTime);
	
	if (this->mEmptyQueue.getmpHead() != nullptr)
	{
		if (this->mEmptyQueue.getmpTail() != nullptr)
		{
			if (this->mEmptyQueue.getmpHead() == this->mEmptyQueue.getmpTail())
			{
				std::cout << "Test Success\n";
			}
			else
			{
				std::cout << "Test Failed, head and tail pointer not equal\n";
			}
		}
		else
		{
			std::cout << "Test Failed, tail pointer null\n";
		}
		
	}
	else
	{
		std::cout << "Test Failed, head pointer null\n";
	}
	
}

/// <summary>
/// PRECONDITION: testEnqueueEmpty must pass
/// Tests the enqueue function on a queue with a single node
/// </summary>
/// <param name="">void</param>
void TestClass::testEnqueueOneNode(void)
{
	std::cout << "--ENQUEUE TEST ON QUEUE WITH ONE NODE--\n";

	this->mEmptyQueue.enqueue(testCustomerNumber, testServiceTime, testTotalTime);

	if (this->mEmptyQueue.getmpHead() != this->mEmptyQueue.getmpTail())
	{
		if (this->mEmptyQueue.getmpHead()->getpNext() == this->mEmptyQueue.getmpTail())
		{
			std::cout << "Test Success";
		}
		else
		{
			std::cout << "Test Failed, next pointer did not update correctly";
		}
	}
	else
	{
		std::cout << "Test Failed, tail pointer and head pointer point to the same location.\n";
	}
}

void TestClass::testDequeueOneNode(void)
{
}

void TestClass::testDequeueTwoNodes(void)
{
}
