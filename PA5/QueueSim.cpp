#include "QueueSim.hpp"

/////////////////////
///public member-functions

/// <summary>
/// default constructor for QueueSim
/// </summary>
QueueSim::QueueSim()
{
	mSimCurrentTime = 0;
	mSimRunTime = 0;
	mNormalLaneNextCusTime = genRanNum(3,8);
	mExpressLaneNextCusTime = genRanNum(1,5);
	mTotalCustomers = 0;
	
}

/// <summary>
/// function that runs the simulation
/// </summary>
/// <param name="minutes">number of simulated minutes the program will be ran for.</param>
void QueueSim::runSim(int minutes)
{
	if (minutes == 0)//if no argument is given, the program asks for one
	{
		setSimRunTime();
	}
	else
	{
		mSimRunTime = minutes;
	}

	while (mSimCurrentTime != mSimRunTime)
	{
		//each loop corrisponds to one minute
		
		//step one- Check if new customers have arrived.
		if (mSimCurrentTime == mNormalLaneNextCusTime)//adds next customer to normal queue if they arrived 
		{
			mTotalCustomers++;	//updates total customer count, will also represent customer number
			mNormalLane.enqueue(mTotalCustomers, genRanNum(3, 8), 0, mSimCurrentTime);	//adds customer to queue // service time is taken care of within enque function
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
		if (!mNormalLane.isEmpty() && mNormalLane.getmpHead()->getData()->getServiceNumber() + mNormalLane.getmpHead()->getData()->getArrivalTime() <= mSimCurrentTime) //checks if the queue is empty and if the checkout time for the customer at the top of the queue
		{																																								//also corrects any error that might occur if for some reason the sum of serviceTime+ArrivalTime is less than the current time.
			mTempData = mNormalLane.dequeue();	//removes customer from queue and fetches their data																	
			
			cout << "\nCustomer " << mTempData.getCustomerNumber() << " has left the normal lane at sim time +" << mSimCurrentTime <<". They spent " << mSimCurrentTime - mTempData.getArrivalTime() << " minutes in line.\n";  //output message
		}
		if (!mExpressLane.isEmpty() && mExpressLane.getmpHead()->getData()->getServiceNumber() + mExpressLane.getmpHead()->getData()->getArrivalTime() <= mSimCurrentTime)
		{
			mTempData = mExpressLane.dequeue();
			cout << "\nCustomer " << mTempData.getCustomerNumber() << " has left the express lane at sim time +" << mSimCurrentTime << ". They spent " << mSimCurrentTime - mTempData.getArrivalTime() << " minutes in line.\n";
		}


		//step three- print queue if 10+ minutes have passed
		if (mSimCurrentTime % 10 == 0 && mSimCurrentTime != 0)
		{
			//prints queue
			cout << "\n----------------------------------------";
			cout << "\nStandard Queue at Sim Time " << mSimCurrentTime << std::endl;
			mNormalLane.printQueue();
			cout << std::endl;

			cout << "\nExpress Queue at Sim Time " << mSimCurrentTime << std::endl;
			mExpressLane.printQueue();
			cout << "\n----------------------------------------\n";

		}

		mSimCurrentTime++;
	}
}


///////////////////
//private member-funcitons

/// <summary>
/// asks the user how many minutes they would like to run the simulation for
/// </summary>
void QueueSim::setSimRunTime()
{
	while (mSimRunTime <= 0)
	{
		cout << "How long, in minutes, do you wish the sim to run?\n>";
		cin >> this->mSimRunTime;
		if (mSimRunTime <= 0)
		{
			cout << "Input out of Bounds!\n";
		}
	}
}

/// <summary>
/// member function that generates a random number 
/// </summary>
/// <param name="min">generated num min range</param>
/// <param name="max">generated number max range</param>
/// <returns>generated numeber</returns>
int QueueSim::genRanNum(int min, int max)
{
	srand((unsigned)time(NULL));//sets seed for random generation
	
	int ranNum = min + (rand() % max);

	return ranNum;
}
