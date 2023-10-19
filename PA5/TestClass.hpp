#pragma once

#include "Queue.hpp"

class TestClass 
{
public:
	TestClass();

	void testEnqueueEmpty(void);
	void testEnqueueOneNode(void);
	void testDequeueOneNode(void);
	void testDequeueTwoNodes(void);
	void testSim(void);
private:
	Queue mEmptyQueue;

	int testCustomerNumber;
	int testServiceTime;
	int testTotalTime;
};