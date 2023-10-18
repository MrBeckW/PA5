#include "QueueSim.hpp"

/////////////////////
///public member-functions

QueueSim::QueueSim()
{
	mSimCurrentTime = 0;
	mSimRunTime = 0;
	mNormalLaneNextCusTime = genRanNum(3,8);
	mExpressLaneNextCusTime = genRanNum(1,5);
	mTotalCustomers = 0;
	
}

void QueueSim::runSim()
{
	setSimRunTime();
	

	while (mSimCurrentTime != mSimRunTime)
	{
		//each loop corrisponds to one minute
		
		//step one- Check if new customers have arrived.
		if (mSimCurrentTime == mNormalLaneNextCusTime)//adds next customer to normal queue if they arrived 
		{
			mTotalCustomers++;	//updates total customer count, will also represent customer number
			mNormalLane.enqueue(mTotalCustomers, genRanNum(3, 8), 0, mSimCurrentTime);	//adds customer to queue
			mNormalLaneNextCusTime = genRanNum(3, 8) + mSimCurrentTime;	//generates next customer arrival time

			cout << "\nCustomer " << mTotalCustomers << " has arrived in the normal lane at sim time +" << mSimCurrentTime << " minutes.\n";  //output message
		}
		if (mSimCurrentTime == mExpressLaneNextCusTime)
		{
			mTotalCustomers++;
			mExpressLane.enqueue(mTotalCustomers, genRanNum(1, 5), 0, mSimCurrentTime);
			mExpressLaneNextCusTime = genRanNum(1, 5) + mSimCurrentTime;

			cout << "\nCustomer " << mTotalCustomers << " has arrived in the express lane at sim time +" << mSimCurrentTime << " minutes.\n";
		}
		//step two- Check if a customer leaves line
		if (!mNormalLane.isEmpty() && mNormalLane.getmpHead()->getData()->getServiceNumber() + mNormalLane.getmpHead()->getData()->getArrivalTime() == mSimCurrentTime)//checks if the queue is empty and if the checkout time for the customer at the top of the queue
		{
			mTempData = mNormalLane.dequeue();	//removes customer from queue and fetches their data
			
			cout << "\nCustomer " << mTempData.getCustomerNumber() << " has left the normal lane at sim time +" << mSimCurrentTime <<". They spent " << mSimCurrentTime - mTempData.getArrivalTime() << " minutes in line.\n";  //output message
		}
		if (!mExpressLane.isEmpty() && mExpressLane.getmpHead()->getData()->getServiceNumber() + mExpressLane.getmpHead()->getData()->getArrivalTime() == mSimCurrentTime)
		{
			mTempData = mExpressLane.dequeue();
			cout << "\nCustomer " << mTempData.getCustomerNumber() << " has left the express lane at sim time +" << mSimCurrentTime << ". They spent " << mSimCurrentTime - mTempData.getArrivalTime() << " minutes in line.\n";
		}
		//step three- print queue if 10+ minutes have passed
		if (mSimCurrentTime % 10 == 0)
		{
			//prints queue
		}
		mSimCurrentTime++;
	}
}

///////////////////
//private member-funcitons

void QueueSim::setSimRunTime()
{
	cout << "How long, in minutes, do you wish the sim to run?\n>";
	cin >> this->mSimRunTime;
}

int QueueSim::genRanNum(int min, int max)
{
	srand((unsigned)time(NULL));
	
	int ranNum = min + (rand() % max);

	return ranNum;
}
