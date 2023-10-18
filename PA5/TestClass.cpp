#include "TestClass.hpp"

TestClass::TestClass()
{
	this->testCustomerNumber = 333;
	this->testServiceTime = 222;
	this->testTotalTime = 111;
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
				std::cout << "Test Passed!\n";
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
			std::cout << "Test Passed!\n";
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

/// <summary>
/// PRECONDITION: testEnqueueEmpty, testEnqueueOneNode and testDequeueTwoNodes all must pass
/// tests the Dequeue function with a queue with a single node
/// </summary>
/// <param name="">void</param>
void TestClass::testDequeueOneNode(void)
{
	std::cout << "--DEQUEUE TEST ON QUEUE WITH ONE NODE--\n";

	Data pTestData = this->mEmptyQueue.dequeue();

	if (mEmptyQueue.getmpHead() == nullptr)
	{
		if (mEmptyQueue.getmpTail() == nullptr)
		{
			if (pTestData.getCustomerNumber() == this->testCustomerNumber)
			{
				std::cout << "Test Passed!\n";
			}
			else
			{
				std::cout << "Test Failed, Data did not return correctly\n";
			}
		}
		else
		{
			std::cout << "Test Failed, Tail pointer not nullptr\n";
		}
	}
	else
	{
		std::cout << "Test Failed, Head pointer not nullptr\n";
	}
}

/// <summary>
/// PRECONDITION: testEnqueueEmpty and testEnqueueOneNode must pass
/// tests dequeue function with a queue with two nodes
/// </summary>
/// <param name=""></param>
void TestClass::testDequeueTwoNodes(void)
{
	std::cout << "--DEQUEUE TEST ON QUEUE WITH TWO NODES--\n";

	Data pTestData = this->mEmptyQueue.dequeue();

	if (mEmptyQueue.getmpHead() != nullptr)
	{
		if (mEmptyQueue.getmpHead() == mEmptyQueue.getmpTail())
		{
			if (pTestData.getCustomerNumber() == this->testCustomerNumber)
			{
				std::cout << "Test Passed!\n";
			}
			else
			{
				std::cout << "Test Failed, Data did not return correctly\n";
			}
		}
		else
		{
			std::cout << "Test Failed, Head pointer not updated correctly\n";
		}
	}
	else
	{
		std::cout << "Test Failed, Head pointer set to nullptr\n";
	}
}
