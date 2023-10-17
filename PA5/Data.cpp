#include "Data.hpp"


/// <summary>
/// defualt constuctor for Data class
/// </summary>
/// <param name="newCustomerNumber">int customer number</param>
/// <param name="newServiceTime">int service time</param>
/// <param name="newTotalTime">int total time</param>
Data::Data(const int newCustomerNumber, const int newServiceTime, const int newTotalTime)
{
	this->mCustomerNumber = newCustomerNumber;
	this->mServiceTime = newServiceTime;
	this->mTotalTime = newTotalTime;
}

/// <summary>
/// getter for mCustomerNumber
/// </summary>
/// <returns>mCustomerNumber</returns>
int Data::getCustomerNumber()
{
	return this->mCustomerNumber;
}

/// <summary>
/// getter for mServiceTime
/// </summary>
/// <returns>mServiceTime</returns>
int Data::getServiceNumber()
{
	return this->mServiceTime;
}

/// <summary>
/// getter for mTotalTime
/// </summary>
/// <returns>mTotalTime</returns>
int Data::getTotalTime()
{
	return this->mTotalTime;
}
