////////////////////
// Beck Williams
// PA 5
// CptS 122
////////////////////


#include "QueueSim.hpp"
#include "TestClass.hpp"


int main()
{
	TestClass test;
	test.testEnqueueEmpty();
	test.testEnqueueOneNode();
	test.testDequeueTwoNodes();
	test.testDequeueOneNode();
	test.testSim();
	
}