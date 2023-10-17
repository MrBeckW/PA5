#pragma once


class Data
{
public:
	Data(const int newCustomerNumber = 0, const int newServiceTime = 0, const int newTotalTime = 0);

	int getCustomerNumber();
	int getServiceNumber();
	int getTotalTime();

	
private:
	int mCustomerNumber;
	int mServiceTime;
	int mTotalTime;
};

