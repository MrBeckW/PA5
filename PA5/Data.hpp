#pragma once
#include <iostream>
using std::ostream;

class Data
{
public:
	Data(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0, const int newArrivalTime = 0);
	Data(const Data &newData);

	int getCustomerNumber();
	int getServiceNumber();
	int getTotalTime();
	int getArrivalTime();
	
	void setServicetime(int numItems);
private:
	int mCustomerNumber,
		mServiceTime,
		mTotalTime,
		ArrivalTime;
		
};

ostream& operator<<(ostream& lhs, Data& rhs);
