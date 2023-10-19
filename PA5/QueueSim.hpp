#pragma once

#include <cstdlib>
#include "Queue.hpp"
using std::cout;
using std::cin;

class QueueSim
{
public:
	QueueSim();

	void runSim(int minutes = 0);
	

private:
	void setSimRunTime();
	int genRanNum(int min, int max);

	Queue mExpressLane, mNormalLane;
	Data mTempData;

	int mSimRunTime,
	mNormalLaneNextCusTime,
	mExpressLaneNextCusTime,
	mSimCurrentTime,
	mTotalCustomers;
	
};