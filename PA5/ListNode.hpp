#pragma once
#include <string>

using std::string;

class ListNode
{
public:
	ListNode(string& item);

	ListNode* getpNext();
	
	void setpNext(ListNode* pNext);

private:
	ListNode* pNext;
	string item;
};